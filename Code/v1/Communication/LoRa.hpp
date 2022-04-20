#ifndef __LORA__H
#define __LORA__H

#include "BME688.hpp"
#include "mbed.h"
#include "lorawan/LoRaWANInterface.h"
#include "lorawan/system/lorawan_data_structures.h"
#include "events/EventQueue.h"
#include "trace_helper.h"
#include "lorawan/LoRaRadio.h"
#include "STM32WL_LoRaRadio.h"
#define MAX_NUMBER_OF_EVENTS            10
#define CONFIRMED_MSG_RETRY_COUNTER     3



class LoRa{

    public:
    LoRa();
    void start();
    void sendData(dataContainer newestData);
    void updateData(dataContainer newestData);
    void sendGarbage();
    private:
    dataContainer data;
    void sendMessage();
    void receiveMessage();
    void loraHandler(lorawan_event_t event);
    void _internalThread();
    LoRaWANInterface _lorawan;
    lorawan_app_callbacks_t callbacks;
    Thread LoRaInternalThread;
    lorawan_status_t retcode;
};











#endif 