#include "Map.h"
#include "Drone.h"

Map::Map(Drone drone) 
: data(5, vector<char>(5, '-')) 
{
        data[0][0] = 'D';
        this->drone = drone;
}

Map::Map()
{
    Drone drone;
    Map(drone);
}

Map::~Map() 
{
}

void Map::printMap() 
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void Map::moveForward() 
{
    if (pose[0] - 1 >= 0 && data[pose[0] - 1][pose[1]] == '-') {
        data[pose[0]][pose[1]] = '-';
        data[pose[0] - 1][pose[1]] = 'D';
        pose[0] = pose[0] - 1;
        cout<<"Your drone moved one tile to the front" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveRight() 
{
    if (pose[1] + 1 < 5 && data[pose[0]][pose[1] + 1] == '-') {
        data[pose[0]][pose[1]] = '-';
        data[pose[0]][pose[1] + 1] = 'D';
        pose[1] = pose[1] + 1;
        cout<<"Your drone moved one tile to the right" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveBackward() 
{
    if (pose[0] + 1 < 5 && data[pose[0] + 1][pose[1]] == '-') {
        data[pose[0]][pose[1]] = '-';
        data[pose[0] + 1][pose[1]] = 'D';
        pose[0] = pose[0] + 1;
        cout<<"Your drone moved one tile to the back" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveLeft() {
    if (pose[1] - 1 >= 0 && data[pose[0]][pose[1] - 1] == '-') {
        data[pose[0]][pose[1]] = '-';
        data[pose[0]][pose[1] - 1] = 'D';
        pose[1] = pose[1] - 1;
        cout<<"Your drone moved one tile to the left" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

int Map::getLocationX(){
  return pose[1];
}

int Map::getLocationY(){
  return pose[0];
}
