add_library(Modules "")

target_sources(Modules
  PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/Console.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Drone.cpp
    ${CMAKE_CURRENT_LIST_DIR}/Map.cpp
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/Console.h
    ${CMAKE_CURRENT_LIST_DIR}/Drone.h
    ${CMAKE_CURRENT_LIST_DIR}/Map.h

  )
target_include_directories(Modules
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )