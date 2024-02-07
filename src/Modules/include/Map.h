#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "Drone.h"

using namespace std;

class Map {
    private:
        vector<vector<char>> data;
        vector<int> pose;
        Drone drone;
    public:
        // constructor
        Map(Drone drone);
        Map();

        // destructor
        ~Map();

        // Map Print
        void printMap();

        // movement function
        void moveForward();
        void moveRight();
        void moveBackward();
        void moveLeft();

        // getter location (X,Y)
        int getLocationX();
        int getLocationY();
};
#endif
