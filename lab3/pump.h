#ifndef _PUMP_H_
#define _PUMP_H_
#include <iostream>
#include <math.h>
#include "wheel.h"




class Pump
{
    friend class Car; 
    friend class Wheel;
public:
    bool setPressure(Wheel* wheel, double Pressure)
    {
        if (wheel->pressure!=Pressure)
        {
            wheel->pressure=Pressure;
            return true;   

        }
        
        else
        {
            return false;
        }

    }       
};

#endif 