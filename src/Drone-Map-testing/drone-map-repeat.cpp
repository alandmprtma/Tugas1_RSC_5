#include <iostream>
#include <vector>
#include <windows.h>


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

int main() {
    Map obj;
    while(true) {
        obj.printMap();
        std::cout << "Your drone is located at ("<< obj.Drone[1]<<","<<obj.Drone[0]<<")."<< std::endl;

        char userInput;
        std::cout << "Input: ";
        std::cin >> userInput;

        switch (userInput) {
            case 'w':
                obj.moveForward();
                break;
            case 'a':
                obj.moveLeft();
                break;
            case 's':
                obj.moveBackward();
                break;
            case 'd':
                obj.moveRight();
                break;
            default:
                std::cout << "Invalid input. Please use W, A, S, or D." << std::endl;
                break;
        }
        Sleep(2000);
        system("cls");
    }
    return 0;
}
