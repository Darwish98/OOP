#ifndef _CAR_H
#define _CAR_H


#include <iostream>
#include <math.h>
#include "wheel.h"
#include <string>  
using std::string;



enum Color {no_color,red, green, blue };




class Car 
{
    
    Color color;
    int weight;
    string model;
    double linearVelociy;
    double angularVelocity;
    Wheel * flWheel;
    Wheel * frWheel;
    Wheel * rlWheel;
    Wheel * rrWheel;


    void Update_wheel(){
        double RPM = linearVelociy * flWheel->getRadius();
        double Angle = angularVelocity;
        flWheel->setrpm(RPM);
        frWheel->setrpm(RPM);
        rlWheel->setrpm(RPM);
        rrWheel->setrpm(RPM);
        flWheel->setangle(Angle);
        frWheel->setangle(Angle);
        rlWheel->setangle(Angle);
        rrWheel->setangle(Angle);
       
    }

public:
    



    bool setSpeed(double speed) 
    {
        if(speed < 500 )//fastet car have reached about 500km/h
        {
            this->linearVelociy=speed;
            return true;
            Update_wheel();
        }
        return false;
    }

    bool setTurningAngle(double angle) 
    {
        if(angle<=33)
        {
            this->flWheel->setangle(angle);
            this->frWheel->setangle(angle);
            this->rlWheel->setangle(angle);
            this->rrWheel->setangle(angle);
            Update_wheel();
            return true;
        }
        return false;
    }

    void setModel(string name)
    {
        this->model=name;
    }   

    void getModel()
    {
        std::cout<<"Car model is "<<this->model<<std::endl;;
    }

    void setWeight(int w)
    {
        this->weight=w;
    }
    
    void getColor()
    {
    
        Color r = this->color;
        switch(r)
        {
            case no_color:std::cout <<"\nNo color assigned\n"; break;
            case red : std::cout << "\nCar color is red\n"; break;
            case green: std::cout <<"\nCar color isgreen\n"; break;
            case blue : std::cout <<"\nCar color isblue\n"; break;
        }
    

    }
    void display_info()
    {
        std::cout <<"Wheels info about " << this->model <<std::endl;
        std::cout<<"Wheel 1 angle:" <<this->flWheel->getangle()<<std::endl;
        std::cout<<"Wheel 1 RPM:" << this->flWheel->getrpm()<<std::endl;
        std::cout<<"Wheel 2 angle:" <<this->frWheel->getangle()<<std::endl;
        std::cout<<"Wheel 2 RPM:" <<this->frWheel->getrpm()<<std::endl;
        std::cout<<"Wheel 3 angle:" <<this->rlWheel->getangle()<<std::endl;
        std::cout<<"Wheel 3 RPM:" << this->rlWheel->getrpm()<<std::endl;
        std::cout<<"Wheel 4 angle:" <<this->rrWheel->getangle()<<std::endl;
        std::cout<<"Wheel 4 RPM:" <<this->rrWheel->getrpm()<<std::endl;
        

    }

    Car(Color C){
        this->color= C;
        flWheel= new Wheel();
        frWheel= new Wheel();
        rlWheel= new Wheel();
        rrWheel= new Wheel();
        Update_wheel();
        
    }
    //shallow copy 
    Car(const Car& other){
        std::cout<<"\nThis is CC-tor..The model is:"<< other.model <<std::endl;
        this->model= other.model;
        this->angularVelocity=other.angularVelocity;
        this->linearVelociy= other.linearVelociy;
        this->color= other.color;
        this->weight = other.weight;
        this->flWheel=new Wheel(other.flWheel->getRadius());
        this->frWheel=new Wheel(other.frWheel->getRadius());
        this->rlWheel=new Wheel(other.rlWheel->getRadius());
        this->rrWheel=new Wheel(other.rrWheel->getRadius());
        this->flWheel->rpm=other.flWheel->rpm;
        this->frWheel->rpm=other.frWheel->rpm;
        this->rlWheel->rpm=other.rlWheel->rpm;
        this->rrWheel->rpm=other.rrWheel->rpm;
        this->flWheel->angle=other.flWheel->angle;
        this->frWheel->angle=other.frWheel->angle;
        this->rlWheel->angle=other.rlWheel->angle;
        this->rrWheel->angle=other.rrWheel->angle;
    

    }

     Car& operator=(const Car& other){
        std::cout<<"This is CA-tor...The model is:"<<other.model<<std::endl;;
        this->model= other.model;
        this->angularVelocity=other.angularVelocity;
        this->linearVelociy= other.linearVelociy;
        this->color= other.color;
        this->weight= other.weight;
        delete flWheel;
        delete frWheel; 
        delete rlWheel;
        delete rrWheel;
        this->flWheel=other.flWheel;
        this->frWheel=other.frWheel;
        this->rlWheel=other.rlWheel;
        this->rrWheel=other.rrWheel;
        return *this;
    }

    Car(Car&& other) {
        std::cout<<"This is MC-tor"<<std::endl;
        this->model= other.model;
        this->angularVelocity=other.angularVelocity;
        this->linearVelociy= other.linearVelociy;
        this->color= other.color;
        this->weight= other.weight;
        this->flWheel=other.flWheel;
        this->frWheel=other.frWheel;
        this->rlWheel=other.rlWheel;
        this->rrWheel=other.rrWheel;
        other.model="";
        other.angularVelocity=0;
        other.linearVelociy=0;
        other.color=no_color;
        other.weight=0;
        other.flWheel=nullptr;
        other.frWheel=nullptr;
        other.rlWheel=nullptr;
        other.rrWheel=nullptr;
    }

    Car& operator=(Car&& other) {
        std::cout<<"This is MA-tor"<<std::endl;
        this->model= other.model;
        this->angularVelocity=other.angularVelocity;
        this->linearVelociy= other.linearVelociy;
        this->color= other.color;
        this->weight= other.weight;
        delete flWheel;
        delete frWheel;
        delete rlWheel;
        delete rrWheel;
        this->flWheel=other.flWheel;
        this->frWheel=other.frWheel;
        this->rlWheel=other.rlWheel;
        this->rrWheel=other.rrWheel;
        other.model="";
        other.angularVelocity=0;
        other.linearVelociy=0;
        other.color=no_color;
        other.weight=0;
        other.flWheel=nullptr;
        other.frWheel=nullptr;
        other.rlWheel=nullptr;
        other.rrWheel=nullptr;
        return *this;
    }
    ~Car(){
        delete flWheel;
        delete frWheel;
        delete rlWheel;
        delete rrWheel;
        std::cout<<"This is Ds-tor.... the model is: "<< this->model<<std::endl;
    }


   

};




#endif