#ifndef _WHEEL_H_
#define _WHEEL_H_
#include <iostream>
#include <math.h>

class Wheel {

    friend class Pump;  
    friend class Car;  
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

    double calculateSpeed() const{
        return ((this->rpm)*(2*M_PI*(this->radius)))/60;
    }

    void setSpeed(double speed){
        rpm = ((speed * 60)/(2*M_PI*(this->radius)));
    }
    
    bool operator== (const Wheel& wheel) const{
        return calculateSpeed() == wheel.calculateSpeed();
    }

    bool operator!= (const Wheel& wheel) const{
        return calculateSpeed() != wheel.calculateSpeed();
    }

    bool operator< (const Wheel& wheel) const{
        return calculateSpeed() < wheel.calculateSpeed();
    }

    bool operator> (const Wheel& wheel) const{
        return calculateSpeed() > wheel.calculateSpeed();
    }

    bool operator<= (const Wheel& wheel) const{
        return calculateSpeed() <= wheel.calculateSpeed();
    }

    bool  operator>= (const Wheel& wheel) const{
        return calculateSpeed() >= wheel.calculateSpeed();
    }
};


#endif // _WHEEL_H_