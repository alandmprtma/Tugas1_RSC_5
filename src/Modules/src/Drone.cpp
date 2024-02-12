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

void Drone::generateObstacle()
{

}

void Drone::autonomous()
{
    std::cout << "Autonomous On!" << std::endl;
    std::cout << "Target: " << std::endl;
    int x, y;
    std::cout << "> x: ";
    std::cin >> x;
    std::cout << "> y: ";
    std::cin >> y;
    if (x < 0 || x > 4 || y < 0 || y > 4)
    {
        std::cout << "Invalid target!" << std::endl;
        return;
    }
    else
    {
        if (this->getLandingStatus() == true)
        {
            std::cout << "Drone is on land, Please take-off first!" << std::endl;
            return;
        }
        else
        {
            if (this->getBatteryLevel() < abs(this->getXPos()- x) + abs(this->getYPos() - y)){
                std::cout << "Battery not enough, Please recharge!" << std::endl;
                return;
            }
            else{
                char matrix[5][5];
                    for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        matrix[i][j] = '-';
                    }
                }
                int Xpos = this->getXPos();
                int Ypos = this->getYPos();
                if (this->getXPos() > x){
                    while (Xpos != x){
                        Xpos--;
                        matrix[Xpos][Ypos] = 'x';

                    }
                } else if (Xpos < x){
                    while (Xpos != x){
                        Xpos++;
                        matrix[Xpos][Ypos] = 'x';
                    }
                }
                if (Ypos > y){
                    while (Ypos != y){
                        Ypos--;
                        matrix[Xpos][Ypos] = 'x';
                    }
                } else if (Ypos < y){
                    while (Ypos != y){
                        Ypos++;
                        matrix[Xpos][Ypos] = 'x';
                    }
                }
                matrix[x][y] = 'D';
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        std::cout << matrix[i][j] << " ";
                    }
                    std::cout << std::endl;
                }
                std::cout << "Your drone is located at ("<< x << ", "<< y << ")." << std::endl;
                return;
            }
        }
    }
}