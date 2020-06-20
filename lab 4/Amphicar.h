#ifndef _AMPHICAR_H
#define _AMPHICAR_H

#include <iostream>

// ---Diamond prolem----
// constructor of vehicle is called then the- 
//-constructor of Car is called then constructor
//- of boat is called then constructor of amphicar is called 
class Amphicar :public Car,public Boat{

    public: 
        Amphicar(){
            
        }

        virtual void printClass(){
            std::cout << "Amphicar \n";
        }

        virtual ~Amphicar(){

        }
};


#endif