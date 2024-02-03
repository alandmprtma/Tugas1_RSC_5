#ifndef _DRONE_H
#define _DRONE_H

#include <iostream>

class Map {
public:
    std::vector<std::vector<char>> arr;
    std::vector<int> Drone;
    Map() : arr(5, std::vector<char>(5, '-')), Drone{0, 0} {
        arr[0][0] = 'D';
    }

    void printMap() {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                std::cout << arr[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void moveForward() {
        if (Drone[0] - 1 >= 0 && arr[Drone[0] - 1][Drone[1]] == '-') {
            arr[Drone[0]][Drone[1]] = '-';
            arr[Drone[0] - 1][Drone[1]] = 'D';
            Drone[0] = Drone[0] - 1;
            std::cout<<"Your drone moved one tile to the front" << std::endl;
        } else {
            std::cout << "You cant move the drone off the map" << std::endl;
        }
    }

    void moveRight() {
        if (Drone[1] + 1 < 5 && arr[Drone[0]][Drone[1] + 1] == '-') {
            arr[Drone[0]][Drone[1]] = '-';
            arr[Drone[0]][Drone[1] + 1] = 'D';
            Drone[1] = Drone[1] + 1;
            std::cout<<"Your drone moved one tile to the right" << std::endl;
        } else {
            std::cout << "You cant move the drone off the map" << std::endl;
        }
    }

    void moveBackward() {
        if (Drone[0] + 1 < 5 && arr[Drone[0] + 1][Drone[1]] == '-') {
            arr[Drone[0]][Drone[1]] = '-';
            arr[Drone[0] + 1][Drone[1]] = 'D';
            Drone[0] = Drone[0] + 1;
            std::cout<<"Your drone moved one tile to the back" << std::endl;
        } else {
            std::cout << "You cant move the drone off the map" << std::endl;
        }
    }

    void moveLeft() {
        if (Drone[1] - 1 >= 0 && arr[Drone[0]][Drone[1] - 1] == '-') {
            arr[Drone[0]][Drone[1]] = '-';
            arr[Drone[0]][Drone[1] - 1] = 'D';
            Drone[1] = Drone[1] - 1;
            std::cout<<"Your drone moved one tile to the left" << std::endl;
        } else {
            std::cout << "You cant move the drone off the map" << std::endl;
        }
    }
};

#endif
