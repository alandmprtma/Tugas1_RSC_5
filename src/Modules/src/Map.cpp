#include "Map.h"
#include "Drone.h"

Map::Map(Drone drone) 
: data(5, vector<char>(5, '-')), base(data)
{
    this->drone = drone;
    data[this->drone.getXPos()][this->drone.getYPos()] = 'D';
}

Map::Map()
: data(5, vector<char>(5, '-')), base(data)
{
    Drone drone;
    this->drone = drone;
    data[this->drone.getXPos()][this->drone.getYPos()] = 'D';

}

Map::~Map() 
{
}

void Map::printMap() 
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << this->data[i][j] << " ";
        }
        cout << endl;
    }
    this->drone.showPose();
    cout << "Battery: " << this->drone.getBatteryLevel() << endl;
    cout << endl;
}

void Map::printBase() 
{
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            cout << this->base[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Map::reset()
{
    vector<char> row(5, '-');
    vector<vector<char>> mat(5, row);
    this->data = mat;
}

void Map::refresh()
{
    this->data = base;
    int x, y;
    x = this->drone.getXPos();
    y = this->drone.getYPos();
    data[x][y] = 'D';
}

void Map::moveUp() 
{
    int x, y;
    x = this->drone.getXPos();
    y = this->drone.getYPos();
    if (x - 1 >= 0 && data[x - 1][y] == '-') {
        data[x][y] = '-';
        data[x - 1][y] = 'D';
        this->drone.moveUp();
        cout<<"Your drone moved one tile to the front" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveRight() 
{
    int x, y;
    x = this->drone.getXPos();
    y = this->drone.getYPos();
    if (x + 1 < 5 && data[x][y + 1] == '-') {
        data[x][y] = '-';
        data[x][y + 1] = 'D';
        this->drone.moveRight();
        cout<<"Your drone moved one tile to the right" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveDown() 
{
    int x, y;
    x = this->drone.getXPos();
    y = this->drone.getYPos();
    if (x + 1 < 5 && data[x + 1][y] == '-') {
        data[x][y] = '-';
        data[x + 1][y] = 'D';
        this->drone.moveDown();
        cout<<"Your drone moved one tile to the back" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::moveLeft() 
{
    int x, y;
    x = this->drone.getXPos();
    x = this->drone.getYPos();
    if (x - 1 >= 0 && data[x][y - 1] == '-') {
        data[x][y] = '-';
        data[x][y - 1] = 'D';
        this->drone.moveLeft();
        cout<<"Your drone moved one tile to the left" << endl;
    } else {
        cout << "You cant move the drone off the map" << endl;
    }
}

void Map::mountDrone(Drone drone)
{
    this->drone = drone;
    this->refresh();
}

Drone Map::getDrone() {return this->drone;}

int Map::getLocationX() {return this->drone.getXPos();}

int Map::getLocationY() {  return this->drone.getYPos();}
