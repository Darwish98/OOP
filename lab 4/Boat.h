#ifndef _BOAT_H
#define _BOAT_H

#include <iostream>

class Boat : virtual public Vehicle{

    public: 
        Boat(){
            
        }

        virtual void printClass(){
            std::cout << "Boat\n";
        }

        virtual ~Boat(){
            
        }

};


#endif