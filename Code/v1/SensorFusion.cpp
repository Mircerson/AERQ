#include "SensorFusion.hpp"

static EventQueue fusionQueue(5 *EVENTS_EVENT_SIZE);
SensorFusion::SensorFusion() : _iaqSensor(), _lora(),_fusionThread(osPriorityAboveNormal,OS_STACK_SIZE,nullptr,"SensorThread")
{
    
} 




void SensorFusion::start()
{
    _lora.start();
    _iaqSensor.initialise();
    _iaqSensor.doMeasurements();
    _fusionThread.start(callback(this,&SensorFusion::_fusionThreadWorker));
    fusionQueue.call_every(15s,callback(this,&SensorFusion::checkDataAndPost));
}


void SensorFusion::checkDataAndPost()
{
    printf("Test\n\r");
    if(_iaqSensor.isNewDataAvailable())
    {
        _lora.sendData(_iaqSensor.returnLatest());   
    }
    else
    {
        //Replace with Error
        _lora.sendGarbage();
    }
}


void SensorFusion::_fusionThreadWorker()
{
    fusionQueue.dispatch_forever();
}