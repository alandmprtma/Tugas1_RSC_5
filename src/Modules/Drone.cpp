#include "Drone.h"
#include <iostream>
#include <string>

Drone::Drone(int x_pos, int y_pos)
    :x{x_pos}, y{y_pos}, battery{5}, onLand{true} 
    {}
Drone::Drone()
    : Drone(0,0)
    {}

//Destructor
Drone::~Drone() {}


//Get Methods

int Drone::getXPos() const {return x;}
int Drone::getYPos() const {return y;}
int Drone::getBatteryLevel() const {return battery;}
bool Drone::getLandingStatus() const {return onLand;}

//Methods
void Drone::takeOff(){
    onLand = false;
    std::cout << "Drone has taken off" << std::endl;

}

void Drone::moveUp(){
    if (!onLand){
        if (battery > 0){
            if (x != 0 && battery > 0){
                --x;
                --battery;
                std::cout << "move up" << std::endl;
            } else 
                std::cout << "Cannot move off the map" << std::endl;
        } else
            std::cout << "Battery not enough, Please recharge!" << std::endl;
    } else
        std::cout << "Drone has not taken off!" << std::endl;
}

void Drone::moveRight(){
    if (!onLand){
        if (battery > 0){
            if (y != 4){
                ++y;
                --battery;
                std::cout << "move right" << std::endl;
            } else 
                std::cout << "Cannot move off the map" << std::endl;
        } else
            std::cout << "Battery not enough, Please recharge!" << std::endl;
    } else
        std::cout << "Drone has not taken off!" << std::endl;
}

void Drone::moveLeft(){
    if (!onLand){
        if (battery > 0){
            if (y != 0 && battery > 0){
                --y;
                --battery;
                std::cout << "move left" << std::endl;
            } else 
                std::cout << "Cannot move off the map" << std::endl;
        } else
            std::cout << "Battery not enough, Please recharge!" << std::endl;
    } else
        std::cout << "Drone has not taken off!"<< std::endl;
}
void Drone::moveDown(){
    if (!onLand){
        if (battery > 0){
            if (x != 4 && battery > 0){
                ++x;
                --battery;
                std::cout << "move down" << std::endl;
            } else 
                std::cout << "Cannot move off the map" << std::endl;
        } else
            std::cout << "Battery not enough, Please recharge!" << std::endl;
    } else
        std::cout << "Drone has not taken off!" << std::endl;
}

void Drone::rechargeBattery(){
    battery = 10;
    std::cout << "Battery Recharged"<< std::endl;
}
