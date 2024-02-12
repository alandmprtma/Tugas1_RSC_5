#include "Map.h"
#include "Drone.h"
#include "AStar.h"
#include <cstdlib>

// constructor
Map::Map(Drone drone) 
: data(5, vector<char>(5, '-')), base(data)
{
    this->drone = drone;
    data[this->drone.getXPos()][this->drone.getYPos()] = 'D';
    AStar::Generator generator;
    generator.setWorldSize({5, 5});
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(false);
    this->generator = generator;
}

// constructor
Map::Map()
: data(5, vector<char>(5, '-')), base(data)
{
    Drone drone;
    this->drone = drone;
    data[this->drone.getXPos()][this->drone.getYPos()] = 'D';
    AStar::Generator generator;
    generator.setWorldSize({5, 5});
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(false);
    this->generator = generator;
}

// destructor
Map::~Map() 
{
}

void Map::printMap() 
{
    for (AStar::Vec2i& coordinate : this->drone.getTrail())
    {
        this->data[coordinate.x][coordinate.y] = 'X';
    }
    for (int i = 0; i < 5; ++i) 
    {
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
    vector<vector<char>> mat(5, vector<char>(5, '-'));
    this->generator.clearCollisions();
    this->base = mat;
    this->data = base;
}

void Map::refresh()
{
    this->data = base;
    int x, y;
    x = this->drone.getXPos();
    y = this->drone.getYPos();
    this->data[x][y] = 'D';
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
    if (this->base[drone.getXPos()][drone.getYPos()] == '-')
    {
        this->drone = drone;
        this->refresh();
    }
    else
    {
        cout << "There is an obstacle!" << endl;
    }
    
}

void Map::generateRandomObstacles()
{
    srand(time(0));
    for (int i = 0; i < this->base.size(); i++)
    {
        for (int j = 0; j < this->base[i].size(); j++)
        {
            if ((rand() % 100) > 70 && i != this->drone.getXPos() && j != this->drone.getYPos())
            {
                this->base[i][j] = 'O';
                this->generator.addCollision({i, j});
            }
        }
    }
    this->refresh();
}

Drone Map::getDrone() const {return this->drone;}

int Map::getLocationX() const {return this->drone.getXPos();}

int Map::getLocationY() const {return this->drone.getYPos();}

AStar::Generator Map::getGenerator() const {return this->generator;}
