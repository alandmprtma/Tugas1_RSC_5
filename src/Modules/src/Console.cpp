#include "Console.h"
#include "Map.h"

Console::Console(Map map)
: commands{}
{
    this->map = map;
}

Console::Console()
{
    Drone drone;
    Map map(drone);
    Console(map);
}

Console::~Console()
{
}