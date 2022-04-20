#include "LoRa.hpp"






static EventQueue LoRaQueue(MAX_NUMBER_OF_EVENTS *EVENTS_EVENT_SIZE);
using namespace events;
static STM32WL_LoRaRadio radioLoRa;



LoRa::LoRa() : _lorawan(radioLoRa),  LoRaInternalThread(osPriorityNormal,OS_STACK_SIZE,nullptr,"LoRaThread")
{
}

void LoRa::start()
{
    LoRaInternalThread.start(callback(this,&LoRa::_internalThread));
}

void LoRa::loraHandler(lorawan_event_t event)
{
    switch (event) {
        case CONNECTED:
            printf("Connected to TTN\n\r");
            break;
        case DISCONNECTED:
            LoRaQueue.break_dispatch();
            printf("\r\n Disconnected Successfully \r\n");
            break;
        case TX_DONE:
            printf("\r\n Message Sent to Network Server \r\n");
            break;
        case TX_TIMEOUT:
        case TX_ERROR:
        case TX_CRYPTO_ERROR:
        case TX_SCHEDULING_ERROR:
            printf("\r\n Transmission Error - EventCode = %d \r\n", event);
            break;
        case RX_DONE:
            printf("\r\n Received message from Network Server \r\n");
            this->receiveMessage();
            break;
        case RX_TIMEOUT:
        case RX_ERROR:
            printf("\r\n Error in reception - Code = %d \r\n", event);
            break;
        case JOIN_FAILURE:
            printf("\r\n OTAA Failed - Check Keys \r\n");
            break;
        case UPLINK_REQUIRED:
            printf("\r\n Uplink required by NS \r\n");
            if (MBED_CONF_LORA_DUTY_CYCLE_ON) {
                this->sendMessage();
            }
            break;
        default:
            MBED_ASSERT("Unknown Event");
    }
}


void LoRa::_internalThread()
{
    setup_trace();
    
    ThisThread::sleep_for(1000ms);
    if (_lorawan.initialize(&LoRaQueue) != LORAWAN_STATUS_OK) {
        printf("\r\n LoRa initialization failed! \r\n");
    }
    
     // prepare application callbacks
    callbacks.events = mbed::callback(this,&LoRa::loraHandler);
    _lorawan.add_app_callbacks(&callbacks);

    // Set number of retries in case of CONFIRMED messages
    if (_lorawan.set_confirmed_msg_retries(CONFIRMED_MSG_RETRY_COUNTER)
            != LORAWAN_STATUS_OK) {
        printf("\r\n set_confirmed_msg_retries failed! \r\n\r\n");
    }
    printf("\r\n CONFIRMED message retries : %d \r\n",
           CONFIRMED_MSG_RETRY_COUNTER);

    // Enable adaptive data rate
    if (_lorawan.enable_adaptive_datarate() != LORAWAN_STATUS_OK) {
        printf("\r\n enable_adaptive_datarate failed! \r\n");
    }

    printf("\r\n Adaptive data  rate (ADR) - Enabled \r\n");
    retcode = _lorawan.connect();

    if (retcode == LORAWAN_STATUS_OK ||
            retcode == LORAWAN_STATUS_CONNECT_IN_PROGRESS) {
    } else {
        printf("\r\n Connection error, code = %d \r\n", retcode);
    }

    printf("\r\n Connection - In Progress ...\r\n");

    LoRaQueue.dispatch_forever();
}


void LoRa::sendMessage()
{

    printf("send something!\n\r");
    printf("Temperature:%2.1f *C\n\r",data.temperature);
    printf("Humidity:%2.1f\n\r",data.humidity);
    printf("CO2:%2.1f\n\r",data.CO2);
    printf("CO2 Accuracy:%d\n\r",data.CO2Accuracy);
    printf("IAQ:%2.1f\n\r",data.IAQ);
    printf("IAQ Accuracy:%d",data.IAQAccuracy);
    uint16_t packet_len;
    int16_t retcode;
    int32_t sensor_value=0;
    uint8_t tx_buffer[30];
   
    packet_len = sprintf((char *) tx_buffer, "%2.2f %2.2f %d %2.2f %2.2f",
                         data.temperature,data.humidity,data.IAQAccuracy,data.IAQ,data.CO2);


    retcode = _lorawan.send(MBED_CONF_LORA_APP_PORT, tx_buffer, packet_len,
                           MSG_UNCONFIRMED_FLAG);

    if (retcode < 0) {
        retcode == LORAWAN_STATUS_WOULD_BLOCK ? printf("send - WOULD BLOCK\r\n")
        : printf("\r\n send() - Error code %d \r\n", retcode);

        if (retcode == LORAWAN_STATUS_WOULD_BLOCK) {
            //retry in 3 seconds
            if (MBED_CONF_LORA_DUTY_CYCLE_ON) {
                LoRaQueue.call_in(3000ms, callback(this,&LoRa::sendMessage));
            }
        }
        return;
    }

    printf("\r\n %d bytes scheduled for transmission \r\n", retcode);
    memset(tx_buffer, 0, sizeof(tx_buffer));
}

void LoRa::receiveMessage()
{
    printf("Decode etc\n\r");
}

void LoRa::sendGarbage()
{
   data.temperature = 1;
   data.humidity = 1;
   data.CO2 = 1;
   data.CO2Accuracy = 1;
   data.IAQ = 1;
   data.IAQAccuracy = 4;
    printf("send something!\n\r");
    printf("Temperature:%2.1f *C\n\r",data.temperature);
    printf("Humidity:%2.1f\n\r",data.humidity);
    printf("CO2:%2.1f\n\r",data.CO2);
    printf("CO2 Accuracy:%d\n\r",data.CO2Accuracy);
    printf("IAQ:%2.1f\n\r",data.IAQ);
    printf("IAQ Accuracy:%d",data.IAQAccuracy);
    uint16_t packet_len;
    int16_t retcode;
    int32_t sensor_value=0;
    uint8_t tx_buffer[30];
   
    packet_len = sprintf((char *) tx_buffer, "%2.2f %2.2f %d %2.2f %2.2f",
                         data.temperature,data.humidity,data.IAQAccuracy,data.IAQ,data.CO2);


    retcode = _lorawan.send(MBED_CONF_LORA_APP_PORT, tx_buffer, packet_len,
                           MSG_UNCONFIRMED_FLAG);

    if (retcode < 0) {
        retcode == LORAWAN_STATUS_WOULD_BLOCK ? printf("send - WOULD BLOCK\r\n")
        : printf("\r\n send() - Error code %d \r\n", retcode);

        if (retcode == LORAWAN_STATUS_WOULD_BLOCK) {
            //retry in 3 seconds
            if (MBED_CONF_LORA_DUTY_CYCLE_ON) {
                LoRaQueue.call_in(3000ms, callback(this,&LoRa::sendMessage));
            }
        }
        return;
    }

    printf("\r\n %d bytes scheduled for transmission \r\n", retcode);
    memset(tx_buffer, 0, sizeof(tx_buffer));
}

void LoRa::updateData(dataContainer newestData)
{
    data = newestData;
}

void LoRa::sendData(dataContainer newestData)
{
   LoRaQueue.call(callback(this,&LoRa::updateData),newestData);
   LoRaQueue.call(callback(this,&LoRa::sendMessage));
}



