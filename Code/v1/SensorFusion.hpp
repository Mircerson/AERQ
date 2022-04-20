#ifndef __SENSOR__FUSION__H
#define __SENSOR__FUSION__H
#include "LoRa.hpp"
#include "BME688.hpp"





class SensorFusion{

    public:
    SensorFusion();
    void checkDataAndPost();
    void start();
    private:    
    BME688 _iaqSensor;
    LoRa _lora;
    Thread _fusionThread;
    void _fusionThreadWorker();



};




#endif