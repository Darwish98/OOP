#include <iostream>
#include "wheel.h"
#include "Car.h"
#include "pump.h"


int main(int argc, char *argv[])
{
    Wheel* wheel1 = new Wheel(6);
    wheel1->setrpm(9);
    std::cout << "wheel1->getrpm " << wheel1->getrpm();
    delete(wheel1);
    std::cout<<"\n__________________________"<<std::endl;



    Wheel* wheel2 = new Wheel(5);
    std::cout << "\nWheel2 currentPressure: " << wheel2->getPressure();
    Pump* pump = new Pump();
    pump->setPressure(wheel2, 8);
    std::cout << "\nWheel2 currentPressure: " << wheel2->getPressure();
    delete(wheel2);
    std::cout<<"\n__________________________"<<std::endl;

  
    Wheel* wheel3 = new Wheel(4);
    Wheel* wheel4 = new Wheel(4);
    wheel3->setrpm(2);
    wheel4->setrpm(1);
    wheel3 < wheel4; 
    delete(wheel3);
    delete(wheel4);
    std::cout<<"\n__________________________"<<std::endl;

      

 
    Car* car_1 = new Car(blue); 
    car_1->setModel("Toyota");
    
    Car car_2 = *car_1;  //cc-tor 
    *car_1 = car_2;  //ca-tor

    std::cout<<"\n__________________________"<<std::endl;

    
    Car* car_3 = new Car(blue); 
    car_3->setSpeed(30);
    car_3->setTurningAngle(9);
    car_3->setModel("AUDI");

    Car *car_4 = new Car(std::move(*car_3));//MC-tor
    car_4->display_info();
    Car *car_5 = new Car(green);
    *car_5 = std::move(*car_4); //MA-tor
    car_5->display_info();
    delete(car_3);
    delete(car_4);
    delete(car_5);

    std::cout<<"\n__________________________"<<std::endl;

    Car car_6(blue);
    car_6.setSpeed(100);
    car_6.setTurningAngle(10);
    car_6.setModel("Skoda");
    Car car_7 = car_6;
    car_7.setSpeed(90);
    car_7.setTurningAngle(5);
    car_7.setModel("BMW");
    car_6.display_info();
    car_7.display_info();

    Car* car_8 = new Car(green);
    car_8->setModel("Suziki");
    car_8->setSpeed(200);
    car_8->setWeight(1700);
    car_8->setTurningAngle(29);
    car_8->setSpeed(200);

    Car* car_9 = new Car(*car_8); //cc-tor using pointer
    car_9->display_info(); 
    delete(car_8);
    delete(car_9);
  

    return 0;

}