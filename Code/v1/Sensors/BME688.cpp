#include "BME688.hpp"


//API requires uint8_t reg_addr, const uint8_t *reg_data, uint32_t length, void *intf_ptr)


static EventQueue sensorQueue(5 *EVENTS_EVENT_SIZE);
static I2C i2cLocal(PA_15,PB_15);
static int8_t readRegister(uint8_t reg_addr, uint8_t *regdata, uint32_t length, void *intf_ptr);
static int8_t writeRegister(uint8_t reg_addr,const uint8_t *reg_data, uint32_t length,void *intf_ptr);
static void delay(uint32_t period, void *intf_ptr);

BME688::BME688()
{
    //Do chip ID check
    //ThisThread::sleep_for(50ms);
    _tempProfile[0] = 320;
    _tempProfile[1] = 320;
    _durProfile[0] = 150;
    _durProfile[1] = 150;
   
}



void BME688::_internalThreadFunction()
{
    sensorQueue.dispatch_forever();
}



void BME688::doMeasurements()
{
    sensorQueue.call_every(500ms,callback(this,&BME688::run));
    //sensorQueue.call_every(750ms,callback(this,&BME688::dumpData));
}

void BME688::initialise()
{
    uint8_t rslt;
    rslt = this->_initialiseSensorStructure();
    if(rslt!=0)
    {
        printf("Error occured at initialising the sensor structure\n\r");
        return;
    }

    rslt = this->_initialiseSensorFilterSettings();
    if(rslt!=0)
    {
        printf("Error occured at initialising the sensor filter settings\n\r");
        return;
    }

    rslt = this->_initialiseSensorHeaterSettings();
    if(rslt!=0)
    {
        printf("Error occured at initialising the sensor heater settings\n\r");
        return;
    }
    
    rslt = this->_setSequentialMode();
    if(rslt!=0)
    {
        printf("Error occured at initialising the sensor heater settings\n\r");
        return;
    }

    rslt = this->_startBsec();
    if(rslt!=0)
    {
        printf("Error occured at initialising the BSEC library\n\r");
        return;
    }

    rslt = this->_doBsecSettings();
    if(rslt!=0)
    {
        printf("Error occured at initialising the BSEC library settings\n\r");
        return;
    }
    internalSensorThread.start(callback(this,&BME688::_internalThreadFunction));
}


void BME688::run()
{
    this->_processData();
    this->_bsecProcessing();
}


uint8_t BME688::_initialiseSensorStructure()
{
    uint8_t rslt;
    sensorStructure.intf     =   BME68X_I2C_INTF;
    sensorStructure.read     =   readRegister;
    sensorStructure.write    =   writeRegister;
    sensorStructure.delay_us =   delay;
    rslt = bme68x_init(&sensorStructure);
    if(rslt!=0)
    {
        return SENSOR_STRUCTURE_FAIL;
    }
    return rslt;
}

uint8_t BME688::_initialiseSensorFilterSettings()
{
    uint8_t rslt;
    bme68x_get_conf(&sensorConfig,&sensorStructure);
    sensorConfig.filter = BME68X_FILTER_OFF;
    sensorConfig.odr = BME68X_ODR_NONE;
    sensorConfig.os_hum = BME68X_OS_16X;
    sensorConfig.os_pres = BME68X_OS_1X;
    sensorConfig.os_temp = BME68X_OS_2X;
    rslt = bme68x_set_conf(&sensorConfig, &sensorStructure);
    if(rslt!=0)
    {
        return SENSOR_CONFIG_FAIL;
    }
    return rslt;
}

uint8_t BME688::_initialiseSensorHeaterSettings()
{
    uint8_t rslt;
    sensorHeaterConfig.enable = BME68X_ENABLE;
    sensorHeaterConfig.heatr_temp_prof = _tempProfile;
    sensorHeaterConfig.heatr_dur_prof = _durProfile;
    sensorHeaterConfig.profile_len = 1;
    rslt = bme68x_set_heatr_conf(BME68X_SEQUENTIAL_MODE, &sensorHeaterConfig, &sensorStructure);
    if(rslt!=0)
    {
        return SENSOR_HEATER_FAIL;
    }
    return rslt;
}


uint8_t BME688::_setSequentialMode()
{
    uint8_t rslt;
    rslt = bme68x_set_op_mode(BME68X_SEQUENTIAL_MODE, &sensorStructure);
    if(rslt!=0)
    {
        return SENSOR_OPERATION_SEQ_FAIL;
    }
    return rslt;
}


uint8_t BME688::_startBsec()
{
    uint8_t rslt;
    rslt = bsec_init();
    if(rslt!=0)
    {
        return SENSOR_BSEC_FAIL;
    }
    return rslt;
}

uint8_t BME688::_doBsecSettings()
{
    uint8_t rslt;
    requestedVirtualSensors[0].sensor_id = BSEC_OUTPUT_IAQ;
    requestedVirtualSensors[0].sample_rate = BSEC_SAMPLE_RATE_LP;
    requestedVirtualSensors[1].sensor_id = BSEC_OUTPUT_CO2_EQUIVALENT;
    requestedVirtualSensors[1].sample_rate = BSEC_SAMPLE_RATE_LP;
    requestedVirtualSensors[2].sensor_id = BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE;
    requestedVirtualSensors[2].sample_rate = BSEC_SAMPLE_RATE_LP;
    requestedVirtualSensors[3].sensor_id = BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY;
    requestedVirtualSensors[3].sample_rate = BSEC_SAMPLE_RATE_LP;
    bsec_sensor_configuration_t requiredSensorSettings[BSEC_MAX_PHYSICAL_SENSOR];
    numberRequiredSensorSettings = BSEC_MAX_PHYSICAL_SENSOR;
    rslt = bsec_update_subscription(requestedVirtualSensors, requestedVirtualSensorsNumber,
                             requiredSensorSettings, &numberRequiredSensorSettings);
    if(rslt!=0)
    {
        return SENSOR_BSEC_SUBSCRIPTION_FAIL;
    }
    
    return 0;
}

void BME688::_processData()
{
    uint32_t delayInUs = bme68x_get_meas_dur(BME68X_SEQUENTIAL_MODE, &sensorConfig, &sensorStructure) + (sensorHeaterConfig.heatr_dur_prof[0] * 1000);
    delay(delayInUs,NULL);
    statusGetData = bme68x_get_data(BME68X_SEQUENTIAL_MODE, sensorData, &dataFields, &sensorStructure);
}


void BME688::_bsecProcessing()
{
    if (!(sensorData[dataFields - 1].status & BME68X_NEW_DATA_MSK))
        return;
    bsec_input_t inputs[BSEC_MAX_PHYSICAL_SENSOR];
    uint8_t nInputs = 0;;
    currentTimeInNs = Kernel::get_ms_count() * INT64_C(1000000);
    inputs[nInputs].sensor_id = BSEC_INPUT_TEMPERATURE;
    inputs[nInputs].signal = sensorData[dataFields - 1].temperature;
    inputs[nInputs].time_stamp = currentTimeInNs;
    nInputs++;

    inputs[nInputs].sensor_id = BSEC_INPUT_HUMIDITY;
    inputs[nInputs].signal = sensorData[dataFields - 1].humidity;
    inputs[nInputs].time_stamp = currentTimeInNs;
    nInputs++;

    inputs[nInputs].sensor_id = BSEC_INPUT_PRESSURE;
    inputs[nInputs].signal = sensorData[dataFields - 1].pressure;
    inputs[nInputs].time_stamp = currentTimeInNs;
    nInputs++;

    inputs[nInputs].sensor_id = BSEC_INPUT_GASRESISTOR;
    inputs[nInputs].signal = sensorData[dataFields - 1].gas_resistance;
    inputs[nInputs].time_stamp = currentTimeInNs;
    nInputs++;

    inputs[nInputs].sensor_id = BSEC_INPUT_HEATSOURCE;
    inputs[nInputs].signal = temperatureOffset;
    inputs[nInputs].time_stamp = currentTimeInNs;

    
    uint8_t nOutputs = 0;
    nOutputs = BSEC_NUMBER_OUTPUTS;

    
    bsec_output_t outputStorage[BSEC_NUMBER_OUTPUTS];

    auto status = bsec_do_steps(inputs, nInputs, outputStorage, &nOutputs);
    if (status != BSEC_OK)
    {
        return;
    }
    if (nOutputs > 0)
    {
        newDataAvailable = 1;
        for (uint8_t i = 0; i < nOutputs; i++)
        {
            switch (outputStorage[i].sensor_id)
            {
            case BSEC_OUTPUT_IAQ:
                _dataHolder.IAQ = outputStorage[i].signal;
                _dataHolder.IAQAccuracy = outputStorage[i].accuracy;
                break;
            case BSEC_OUTPUT_CO2_EQUIVALENT:
                _dataHolder.CO2 = outputStorage[i].signal;
                _dataHolder.CO2Accuracy = outputStorage[i].accuracy;
                break;
            case BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_TEMPERATURE:
                _dataHolder.temperature = outputStorage[i].signal;
                break;
            case BSEC_OUTPUT_SENSOR_HEAT_COMPENSATED_HUMIDITY:
                _dataHolder.humidity = outputStorage[i].signal;
                break;
            default:
                break;
            }
        }
    }
    else
    {
        newDataAvailable = 0;
    }
}

void BME688::dumpData()
{
    printf("Temperature:%2.1f *C\n\r",_dataHolder.temperature);
    printf("Humidity:%2.1f\n\r",_dataHolder.humidity);
    printf("CO2:%2.1f\n\r",_dataHolder.CO2);
    printf("CO2 Accuracy:%d\n\r",_dataHolder.CO2Accuracy);
    printf("IAQ:%2.1f\n\r",_dataHolder.IAQ);
    printf("IAQ Accuracy:%d",_dataHolder.IAQAccuracy);
}

uint8_t BME688::isNewDataAvailable()
{
    if(newDataAvailable == 1)
        return 1;
    else
        return 0;
    
}


dataContainer BME688::returnLatest()
{
    return _dataHolder;
}

static int8_t readRegister(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr)
{
    int8_t rslt = 0;
    uint32_t aux = 0;
    aux      =   i2cLocal.write ( BME688_ADDRESS, (char*)&reg_addr, 1, true );
    aux      =   i2cLocal.read  ( BME688_ADDRESS, (char*)&reg_data[0], length );
    if ( aux == 0 ) {
        rslt     =   0;
    } else {
        rslt     =   0xFF;
    }
 
    return rslt;

}


static int8_t writeRegister(uint8_t reg_addr,const uint8_t *reg_data, uint32_t length,void *intf_ptr)
{

    int8_t rslt = 0; // Return 0 for Success, non-zero for failure
    uint32_t     aux     =   0;
    char         cmd[16] =  { 0 };
    uint32_t     i       =   0;
    // Prepare the data to be sent
    cmd[0]   =   reg_addr;
    for ( i = 1; i <= length; i++ ) {
        cmd[i]   =   reg_data[i - 1];
    }
    // Write data
    aux      =   i2cLocal.write( BME688_ADDRESS, &cmd[0], length + 1, false );
    if ( aux == 0 ) {
        rslt     =   0;
    } else {
        rslt     =   0xFF;
    }
    return rslt;
}


static void delay(uint32_t period, void *intf_ptr)
{
    wait_us ( period );
}


