#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "Drone.h"

using namespace std;

class Map {
    private:
        // private attribute
        vector<vector<char>> data;
        vector<vector<char>> base;
        Drone drone;
    public:
        // constructor
        Map(Drone drone);
        Map();

        // destructor
        ~Map();

        // Map Print
        void printMap();
        void printBase();

        // Reset data
        void reset();

        // Refresh data
        void refresh();

        // Movement function
        void moveUp();
        void moveRight();
        void moveDown();
        void moveLeft();

        // Get Drone
        Drone getDrone();

        // Mount drone
        void mountDrone(Drone drone);

        // getter location (X,Y)
        int getLocationX();
        int getLocationY();

};
#endif
