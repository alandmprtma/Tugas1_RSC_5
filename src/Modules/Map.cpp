#include "Map.h"

Map::Map() : data(5, vector<char>(5, '-')), Drone{0, 0} {
        data[0][0] = 'D';
}

Map::~Map() {
}

void Map::printMap() {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }
}

void Map::moveForward() {
    if (Drone[0] - 1 >= 0 && data[Drone[0] - 1][Drone[1]] == '-') {
        data[Drone[0]][Drone[1]] = '-';
        data[Drone[0] - 1][Drone[1]] = 'D';
        Drone[0] = Drone[0] - 1;
        cout<<"Your drone moved one tile to the front" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveRight() {
    if (Drone[1] + 1 < 5 && data[Drone[0]][Drone[1] + 1] == '-') {
        data[Drone[0]][Drone[1]] = '-';
        data[Drone[0]][Drone[1] + 1] = 'D';
        Drone[1] = Drone[1] + 1;
        cout<<"Your drone moved one tile to the right" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveBackward() {
    if (Drone[0] + 1 < 5 && data[Drone[0] + 1][Drone[1]] == '-') {
        data[Drone[0]][Drone[1]] = '-';
        data[Drone[0] + 1][Drone[1]] = 'D';
        Drone[0] = Drone[0] + 1;
        cout<<"Your drone moved one tile to the back" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveLeft() {
    if (Drone[1] - 1 >= 0 && data[Drone[0]][Drone[1] - 1] == '-') {
        data[Drone[0]][Drone[1]] = '-';
        data[Drone[0]][Drone[1] - 1] = 'D';
        Drone[1] = Drone[1] - 1;
        cout<<"Your drone moved one tile to the left" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

int Map::getLocationX(){
  return Drone[1];
}

int Map::getLocationY(){
  return Drone[0];
}
