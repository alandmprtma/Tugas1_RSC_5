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

vector<string> Console::commands = {"takeoff", "landing", "status", "move", "recharge", "autonomous", "generateobstacles", "quit"};

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

    if (command == "quit" || command == "8")
    {
        system("cls");
        exit(0);
    }

    Drone drone = this->map.getDrone();
    
    if (command == "takeoff" || command == "1")
    {
        system("cls");
        drone.takeOff();
    }
    else if (command == "landing" || command == "2")
    {
        system("cls");
        drone.landing();
    }
    else if (command == "status" || command == "3")
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
    else if (command == "move" || command == "4")
    {
        system("cls");
        char input = ' ';
        while (input != 'q')
        {
            drone = this->map.getDrone();
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
    else if (command == "recharge" || command == "5")
    {
        system("cls");
        drone.rechargeBattery();
    }
    else if (command == "autonomous" || command == "6")
    {
        system("cls");
        drone.autonomous(this->map.getGenerator());
        this->map.mountDrone(drone);
        this->map.printMap();
        drone.clearTrail();
    }
    else if (command == "generateobstacles" || command == "7")
    {
        system("cls");
        this->map.generateRandomObstacles();
        this->map.printMap();
    }
    
    else
    {
        system("cls");
        cout << "Invalid command!" << endl;
    }
    
    this->map.mountDrone(drone);
    
}