cmake_minimum_required(VERSION 3.5.0)
project(TUGAS1_RSC_5 VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()


include_directories(src/Modules/include)
set(SRC_FILES
    ${PROJECT_SOURCE_DIR}/src/Modules/src/Map.cpp
    ${PROJECT_SOURCE_DIR}/src/Modules/src/Drone.cpp
    ${PROJECT_SOURCE_DIR}/src/Modules/src/Console.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

add_executable(main ${SRC_FILES})


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
