#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Map.h"

using namespace std;

class Console
{
private:
    Map map;
    const string commands[5];

public:
    // Constructor
    Console(Map map);
    Console();

    // Destructor
    ~Console();

    // Methods
    void run();
    void quit(); 
    
    
};


#endif