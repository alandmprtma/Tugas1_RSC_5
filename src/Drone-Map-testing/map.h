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
        Map();
        void printMap();
        void moveForward();
        void moveRight();
        void moveBackward();
        void moveLeft();
};
#endif
