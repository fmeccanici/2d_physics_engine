cmake_minimum_required(VERSION 2.8)
project(2d_physics_engine)

set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

include_directories(include)

set(SOURCES_FILES src/main.cpp src/vector2d.cpp src/aabb.cpp src/circle.cpp)

add_executable(main ${SOURCES_FILES})


