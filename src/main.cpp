#include <iostream>
#include <Console.h>
#include <Drone.h>
#include <Map.h>

using namespace std;

void showPose(Drone drone)
{
    cout << "x: " << drone.getXPos() << " y: " << drone.getYPos() << endl;
}

int main(int, char**){
    Drone drone = Drone(2, 3);
    showPose(drone);
    Map map;
    char input;
    while(input != 'q')
    {
        map.printMap();
        cin >> input;
    }
}
