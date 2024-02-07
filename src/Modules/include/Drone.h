#ifndef DRONE_H
#define DRONE_H

#include <string>

class Drone 
{ 
private:
//Attribute
    int x;
    int y;
    int battery;
    bool onLand;

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

//Methods
void takeOff();
void moveUp();
void moveRight();
void moveLeft();
void moveDown();
void rechargeBattery();

};

#endif