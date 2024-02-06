add_executable(drone main.cpp)
  
add_subdirectory(Modules)


target_link_libraries(drone
  PRIVATE
    Modules
  )