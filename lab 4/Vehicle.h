#ifndef _VECHILE_H
#define _VECHILE_H

#include <iostream>

class Vehicle{

    public: 
        Vehicle(){//Defaultconstructor
            
        }

        virtual void printClass(){
            std::cout<< "Vehicle ";
        }

        virtual ~Vehicle(){
            
        }
};




#endif