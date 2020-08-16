cmake_minimum_required(VERSION 2.8)
project(2d_physics_engine)

set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

include_directories(include)

set(SOURCES_FILES src/world.cpp src/vector2d.cpp src/rectangle.cpp src/circle.cpp src/constants.cpp src/rigid_body.cpp)
add_executable(main ${SOURCES_FILES})
add_executable(test_vector2d src/test_vector2d.cpp src/vector2d.cpp)

target_link_libraries(main sfml-graphics sfml-window sfml-system)
target_link_libraries(test_vector2d cppunit)


