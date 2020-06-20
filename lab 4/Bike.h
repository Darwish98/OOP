#ifndef _BIKE_H
#define _BIKE_H
#include "Vehicle.h"
#include <iostream>

class Bike: virtual public Vehicle{//inherite

    public: 
        Bike(){//Ctor
            
        }

        void printClass(){
            std::cout << "Bike\n";
        }

        virtual ~Bike(){//Dtor
            
        }

};

#endif