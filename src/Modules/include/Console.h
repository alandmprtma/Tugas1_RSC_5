#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <vector>
#include "Map.h"

using namespace std;

class Console
{
private:
    Map map;

public:
    static vector<string> commands;

    // Constructor
    Console(Map map);
    Console();

    // Destructor
    ~Console();

    // Methods
    void showCommands();
    void run();
};


#endif