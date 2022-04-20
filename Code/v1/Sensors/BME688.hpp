#ifndef __BME688__H
#define __BME688__H

#include "mbed.h"
#include "bme68x_defs.h"
#include "bsec_interface.h"
#include "bsec_datatypes.h"
#include "bme68x.h"

#define BME688_CHIP_ID_LOCATION 0xD0
#define BME688_ADDRESS 0x76 << 1




// int8_t readRegister(uint8_t reg_addr, uint8_t *reg_data, uint32_t length, void *intf_ptr);
// int8_t writeRegister(uint8_t reg_addr,const uint8_t *reg_data, uint32_t length,void *intf_ptr);
// void delay(uint32_t period, void *intf_ptr);

struct dataContainer
{
    float temperature;
    float humidity;
    float CO2;
    uint8_t CO2Accuracy;
    float IAQ;
    uint8_t IAQAccuracy;
};




class BME688{

    public:
        BME688();
        void start();
        void doMeasurements();
        dataContainer returnLatest();
        void dumpData();
        uint8_t isNewDataAvailable();
        void initialise();
    private:
        typedef enum{SENSOR_STRUCTURE_FAIL, SENSOR_CONFIG_FAIL,
                     SENSOR_HEATER_FAIL, SENSOR_OPERATION_SEQ_FAIL,
                     SENSOR_BSEC_FAIL,SENSOR_BSEC_SUBSCRIPTION_FAIL}sensorFailure;
        
        uint8_t newDataAvailable = 0 ;
        
        void run();
        void _internalThreadFunction();
        dataContainer _dataHolder;
        uint8_t _initialiseSensorStructure();
        uint8_t _initialiseSensorFilterSettings();
        uint8_t _initialiseSensorHeaterSettings();
        uint8_t _setSequentialMode();
        uint8_t _startBsec();
        uint8_t _doBsecSettings();
        void _processData();
        void _bsecProcessing();
       
    
        Thread internalSensorThread;
        //BSEC
        bme68x_data sensorData[3];
        bme68x_dev sensorStructure;
        bme68x_conf sensorConfig;
        bme68x_heatr_conf sensorHeaterConfig;    
        uint8_t dataFields;
        bsec_sensor_configuration_t requestedVirtualSensors[4];
        uint8_t numberRequiredSensorSettings;
        uint8_t requestedVirtualSensorsNumber = 4;
        int64_t currentTimeInNs;
        bsec_output_t outputs[BSEC_NUMBER_OUTPUTS];
        const float temperatureOffset = 7.0f;
        bool _newDataAvailable;
        uint16_t _tempProfile[1];
        uint16_t _durProfile[1];
        
        //BME68X General API
        uint8_t statusGetData;
};


#endif