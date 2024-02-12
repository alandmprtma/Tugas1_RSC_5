#include "Drone.h"
#include <iostream>
#include <string>
#include "AStar.h"

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
AStar::CoordinateList Drone::getTrail() const {return this->trail;}

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
    std::cout << "Your drone is located at (" << this->getYPos() << ", " << this->getXPos() << ")" << std::endl;
}

void Drone::searchTarget(AStar::Generator generator, AStar::Vec2i target)
{
    AStar::Vec2i source;
    source = {this->getXPos(), this->getYPos()};
    AStar::CoordinateList path = generator.findPath(source, target);
    path.erase(path.begin());
    this->trail = path;
}

void Drone::autonomous(AStar::Generator generator)
{
    std::cout << "Autonomous On!" << std::endl;
    std::cout << "Target: " << std::endl;
    int x, y;
    std::cout << "> x: ";
    std::cin >> y;
    std::cout << "> y: ";
    std::cin >> x;
    if (x < 0 || x > 4 || y < 0 || y > 4)
    {
        std::cout << "Invalid target!" << std::endl;
    }
    else
    {
        if (this->getLandingStatus() == true)
        {
            std::cout << "Drone is on land, Please take-off first!" << std::endl;
        }
        else
        {
            if (this->getBatteryLevel() < abs(this->getXPos()- x) + abs(this->getYPos() - y)){
                std::cout << "Battery not enough, Please recharge!" << std::endl;
            }
            else{
                AStar::Vec2i target = {x, y};
                this->searchTarget(generator, target);
                if (this->trail[0].x != target.x && this->trail[0].y != target.y)
                {
                    std::cout << "Cannot find path" << std::endl;
                    this->trail.clear();
                }
                else
                {
                    this->x = target.x;
                    this->y = target.y;
                    this->battery -= this->trail.size();
                    if (this->battery == 0)
                    {
                        std::cout << "Out of battery. Initiating landing." << std::endl;
                        this->landing();
                    }
                }
            }
        }
    }
}

void Drone::clearTrail() {this->trail.clear();}

