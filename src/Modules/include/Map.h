#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include "Drone.h"
#include "AStar.h"

using namespace std;

class Map {
    private:
        vector<vector<char>> data;
        vector<vector<char>> base;
        Drone drone;
        AStar::Generator generator;
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
        
        // Mount drone
        void mountDrone(Drone drone);
        
        // Generate obstacles
        void generateRandomObstacles();

        // Get Drone
        Drone getDrone() const;

        // getter location (X,Y)
        int getLocationX() const;
        int getLocationY() const;

        // Get generator
        AStar::Generator getGenerator() const;


};
#endif
