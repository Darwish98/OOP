#include <iostream>
#include <fstream>
#include <string>
#include "wheel.h"
#include "Car.h"
#include "pump.h"
#include "Bike.h"
#include "Boat.h"
#include "Amphicar.h"

int main(int argc, char *argv[])
{
    Vehicle * v1 = new Car(green);
    v1->printClass();
    Vehicle * v2 = new Bike();
    v2->printClass();
    Vehicle * v3 = new Boat();
    v3->printClass();
    Vehicle * v4 =new Amphicar();
    v4->printClass();
    delete(v4);
    std::cout<<"____________________________\n";




    std::ifstream inFile("Vehicles.txt");
    std::string currLine;
    int number_of_vechiles = 0; 
    while(std::getline(inFile,currLine))
    {
        ++number_of_vechiles;
    }
    Vehicle*vechiles[number_of_vechiles];
    inFile.clear();
    inFile.seekg(0);
    


    int index=0;
    while(std::getline(inFile,currLine))
    {
        if (currLine=="bike")
        {
            vechiles[index]=new Bike();

        }
        if (currLine=="car")
        {
            vechiles[index]=new Car();
           
        }
        if (currLine=="amphicar")
        {
           vechiles[index]= new Amphicar();
        }
        index++;
        
    }

    for(int i=0;i<number_of_vechiles;i++)
    {
        vechiles[i]->printClass();

    }

    inFile.close();   
    


    return 0;

}