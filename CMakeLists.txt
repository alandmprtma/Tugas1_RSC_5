cmake_minimum_required(VERSION 3.5.0)
project(TUGAS1_RSC_5 VERSION 0.1.0 LANGUAGES C CXX)

enable_testing()

add_library(
    Console
    src/Modules/Console.cpp
    src/Modules/Console.h
)

add_library(
    Drone
    src/Modules/Drone.cpp
    src/Modules/Drone.h
)

add_library(
    Map
    src/Modules/Map.cpp
    src/Modules/Map.h
)

add_executable(main src/main.cpp)

target_link_libraries(main Console)
target_link_libraries(main Drone)
target_link_libraries(main Map)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
