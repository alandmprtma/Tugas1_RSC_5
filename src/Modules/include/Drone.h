#ifndef DRONE_H
#define DRONE_H

#include <string>
#include "AStar.h"

class Drone 
{ 
private:
//Attribute
    int x; // row
    int y; // coloumn
    int battery;
    bool onLand;
    AStar::CoordinateList trail;
public:
//Constructors
    Drone(int x_pos, int y_pos);
    Drone();
//Destructor
    ~Drone();

//Get Methods
int getXPos() const;
int getYPos() const;
int getBatteryLevel() const;
bool getLandingStatus() const;
AStar::CoordinateList getTrail() const;

//Methods
void takeOff();
void landing();
void moveUp();
void moveRight();
void moveLeft();
void moveDown();
void rechargeBattery();
void showPose();
void searchTarget(AStar::Generator generator, AStar::Vec2i target);
void autonomous(AStar::Generator generator);

};

#endif