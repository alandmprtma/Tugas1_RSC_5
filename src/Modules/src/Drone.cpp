#include "Drone.h"
#include <iostream>
#include <string>

Drone::Drone(int x_pos, int y_pos)
    : x{x_pos}, y{y_pos}, battery{10}, onLand{true} 
    {}
Drone::Drone()
    : Drone(0,0)
    {}

//Destructor
Drone::~Drone() {}


//Get Methods
int Drone::getXPos() const {return this->x;}
int Drone::getYPos() const {return this->y;}
int Drone::getBatteryLevel() const {return this->battery;}
bool Drone::getLandingStatus() const {return this->onLand;}

//Methods
void Drone::takeOff()
{
    this->onLand = false;
    std::cout << "Take-off success!" << std::endl;
}

void Drone::landing()
{
    this->onLand = true;
    std::cout << "Landing success!" << std::endl;
}

void Drone::moveUp()
{
    if (!this->onLand){
        if (this->battery > 0){
            if (this->x != 0 && this->battery > 0){
                --this->x;
                --this->battery;
                std::cout << "move up" << std::endl;
            } else {
                std::cout << "Cannot move off the map" << std::endl;
            }
        } else {
            std::cout << "Battery not enough, Please recharge!" << std::endl;
            this->landing();
        }
    } else {
        std::cout << "Drone has not taken off!" << std::endl;
    } 
}

void Drone::moveRight()
{
    if (!this->onLand){
        if (this->battery > 0){
            if (this->y != 4){
                ++this->y;
                --this->battery;
                std::cout << "move right" << std::endl;
            } else {
                std::cout << "Cannot move off the map" << std::endl;
            }
        } else {
            std::cout << "Battery not enough, Please recharge!" << std::endl;
            this->landing();
        }
    } else {
        std::cout << "Drone has not taken off!" << std::endl;
    }
}

void Drone::moveLeft()
{
    if (!this->onLand){
        if (this->battery > 0){
            if (this->y != 0 && this->battery > 0){
                --this->y;
                --this->battery;
                std::cout << "move left" << std::endl;
            } else {
                std::cout << "Cannot move off the map" << std::endl;
            }
        } else {
            std::cout << "Battery not enough, Please recharge!" << std::endl;
            this->landing();
        }
    } else {
        std::cout << "Drone has not taken off!"<< std::endl;
    }
}
void Drone::moveDown()
{
    if (!this->onLand){
        if (this->battery > 0){
            if (this->x != 4 && this->battery > 0){
                ++this->x;
                --this->battery;
                std::cout << "move down" << std::endl;
            } else {
                std::cout << "Cannot move off the map" << std::endl;
            }
        } else {
            std::cout << "Battery not enough, Please recharge!" << std::endl;
            this->landing();
        }
    } else {
        std::cout << "Drone has not taken off!" << std::endl;
    }
}

void Drone::rechargeBattery()
{
    this->battery = 10;
    std::cout << "Battery Recharged"<< std::endl;
}

void Drone::showPose()
{
    std::cout << "Your drone is located at (" << this->getXPos() << ", " << this->getYPos() << ")" << std::endl;
}
