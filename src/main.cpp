#include <iostream>
#include <Console.h>
#include <Drone.h>

using namespace std;

void showPose(Drone drone)
{
    cout << "x: " << drone.getXPos() << " y: " << drone.getYPos() << endl;
}

int main(int, char**){
    Drone drone = Drone(2, 3);
    showPose(drone);
}
