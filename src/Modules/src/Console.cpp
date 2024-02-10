#include "Console.h"
#include "Map.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

Console::Console(Map map)
{
    this->map = map;
}

Console::Console()
{
    Drone drone;
    Map map(drone);
    this->map = map;
}

Console::~Console()
{
}

vector<string> Console::commands = {"takeoff", "landing", "status", "move", "recharge", "autonomous", "quit"};

void Console::showCommands()
{
    cout << 
    "=====================\n"
    "COMMAND NAMES LIST\n"
    "=====================\n";
    for (size_t i = 0; i < commands.size(); i++)
    {
        cout << i + 1 << ". " << commands[i] << endl;
    }
    cout << endl;
}

void Console::run()
{
    this->showCommands();
    cout << "Input command name: ";
    string command;
    cin >> command;

    if (command == "quit")
    {
        system("cls");
        exit(0);
    }

    Drone drone = this->map.getDrone();
    
    if (command == "takeoff")
    {
        system("cls");
        drone.takeOff();
    }
    else if (command == "landing")
    {
        system("cls");
        drone.landing();
    }
    else if (command == "status")
    {
        system("cls");
        if (drone.getLandingStatus())
        {
            cout <<
            "Status: On land\n"
            "Battery: " << drone.getBatteryLevel() << endl;
        }
        else
        {
            cout <<
            "Status: Airborne\n"
            "Battery: " << drone.getBatteryLevel() << endl;
        }   
    }
    else if (command == "move")
    {
        system("cls");
        char input = ' ';
        while (input != 'q')
        {
            this->map.printMap();
            cout << 
            "Press q to stop moving\n"
            "Input wasd: " << endl;
            input = getch();

            if (input == 'w')
            {
                system("cls");
                drone.moveUp();
            }
            else if (input == 'a')
            {
                system("cls");
                drone.moveLeft();
            }
            else if (input == 's')
            {
                system("cls");
                drone.moveDown();
            }
            else if (input == 'd')
            {
                system("cls");
                drone.moveRight();
            }
            else if (input != 'q')
            {
                system("cls");
                cout << "Invalid input!" << endl;
            }
            this->map.mountDrone(drone);
        }
        system("cls");

    }
    else if (command == "autonomous")
    {
        system("cls");
        cout << "Autonomous On!" << endl;
        cout << "Target: " << endl;
        int x, y;
        cout << "> x: ";
        cin >> x;
        cout << "> y: ";
        cin >> y;
        if (x < 0 || x > 4 || y < 0 || y > 4)
        {
            cout << "Invalid target!" << endl;
            return;
        }
        else
        {
            if (drone.getLandingStatus() == true)
            {
                cout << "Drone is on land, Please take-off first!" << endl;
                return;
            }
            else
            {
                if (drone.getBatteryLevel() < abs(drone.getXPos()- x) + abs(drone.getYPos() - y)){
                    std::cout << "Battery not enough, Please recharge!" << std::endl;
                    return;
                }
                else{
                    char matrix[5][5];
                     for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                            matrix[i][j] = '-';
                        }
                    }
                    int Xpos = drone.getXPos();
                    int Ypos = drone.getYPos();
                    if (drone.getXPos() > x){
                        while (Xpos != x){
                            Xpos--;
                            matrix[Xpos][Ypos] = 'x';

                        }
                    } else if (Xpos < x){
                        while (Xpos != x){
                            Xpos++;
                            matrix[Xpos][Ypos] = 'x';
                        }
                    }
                    if (Ypos > y){
                        while (Ypos != y){
                            Ypos--;
                            matrix[Xpos][Ypos] = 'x';
                        }
                    } else if (Ypos < y){
                        while (Ypos != y){
                            Ypos++;
                            matrix[Xpos][Ypos] = 'x';
                        }
                    }
                    matrix[x][y] = 'D';
                    for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                            std::cout << matrix[i][j] << " ";
                        }
                        std::cout << std::endl;
                    }
                    std::cout << "Your drone is located at ("<< x << ", "<< y << ")." << std::endl;
                    return;
                }
            }
        }
    }
    else if (command == "recharge")
    {
        system("cls");
        drone.rechargeBattery();
    }
    else
    {
        system("cls");
        cout << "Invalid command!" << endl;
    }
    
    this->map.mountDrone(drone);
    
}