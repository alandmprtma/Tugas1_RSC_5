#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>

using namespace std;

class Map {
    private:
        vector<vector<char>> data;
        vector<int> Drone;
    public:
        // constructor
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
