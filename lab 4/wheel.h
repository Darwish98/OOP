#ifndef _WHEEL_H_
#define _WHEEL_H_
#include <iostream>
#include <math.h>

class Wheel {

    friend class Pump;  
    double radius;
    double rpm;
    double angle;
    double pressure;
    double Wheel_Speed;

public:


    Wheel(){
        radius=4;
    }
  

    Wheel(double wheelradius){
        radius = wheelradius;
    }


    double getRadius()
    {
    
        return this->radius;
    }

   
    bool setrpm(double newRPM)
    {
        if(newRPM != 0)
        {
            this->rpm = newRPM;
        }
        else
        {
            return false;
        }
    }
    double getrpm()
    {
        return this->rpm;
    }

    bool setangle(double newANGLE)
    {
        if(newANGLE!=0)
        {
           this->angle=newANGLE;
           return true;
        }
        else
        {
            return false;
        }
    }
    double getangle()
    {
        return this->angle;
    }
    double getPressure()
    {
    
        return this->pressure;
    }




    bool operator== (Wheel* other) 
    {
            
        double Speed_1 = (60 * 2* M_PI *  this->getrpm() * this->getRadius()); 
        double Speed_2 = (60 * 2* M_PI *  other->getrpm() * other->getRadius());

        if(Speed_1 == Speed_2)
        {
            std::cout<< Speed_1 << "==" <<Speed_2;
            return true;
        }
        return false;
        
    }
    bool operator!= (Wheel* other) 
    {
            
        int Speed_1 = (60 * 2* M_PI *  this->getrpm() * this->getRadius()); 
        int Speed_2 = (60 * 2* M_PI *  other->getrpm() * other->getRadius());

        if(Speed_1 != Speed_2){
            return true;
        }
        return false;
        
    }
    bool operator< (Wheel* other) 
    {
            
        int Speed_1 = (60 * 2* M_PI *  this->getrpm() * this->getRadius()); 
        int Speed_2 = (60 * 2* M_PI *  other->getrpm() * other->getRadius());

        if(Speed_1 < Speed_2){
            return true;
        }
        return false;
        
    }
    bool operator> (Wheel* other) 
    {
            
        int Speed_1 = (60 * 2* M_PI *  this->getrpm() * this->getRadius()); 
        int Speed_2 = (60 * 2* M_PI *  other->getrpm() * other->getRadius());

        if(Speed_1 > Speed_2){
            return true;
        }
        return false;
        
    }
    bool operator<= (Wheel* other) 
    {
            
        int Speed_1 = (60 * 2* M_PI *  this->getrpm() * this->getRadius()); 
        int Speed_2 = (60 * 2* M_PI *  other->getrpm() * other->getRadius());

        if(Speed_1 <= Speed_2){
            return true;
        }
        return false;
        
    }
    bool operator>= (Wheel* other) 
    {
            
        int Speed_1 = (60 * 2* M_PI *  this->getrpm() * this->getRadius()); 
        int Speed_2 = (60 * 2* M_PI *  other->getrpm() * other->getRadius());

        if(Speed_1 >= Speed_2){
            return true;
        }
        return false;
        
    }

    






   

};


#endif // _WHEEL_H_