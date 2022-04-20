#include "mbed.h"
#include "SensorFusion.hpp"
#include <stdio.h>




static EventQueue mainThread(5 *EVENTS_EVENT_SIZE);


DigitalOut hb(HEARTBEAT_LED);
SensorFusion sensorManagement;


void doHb();



int main()
{
    sensorManagement.start();
    mainThread.dispatch_forever();
}
 
void doHb()
{
    hb = !hb;
}

