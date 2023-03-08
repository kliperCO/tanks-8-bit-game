cmake_minimum_required(VERSION 3.24)
project(Tanks)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp sandbox.h view.h Player.cpp Tank.cpp Enemy.cpp Bullet.cpp Texture.h)
add_executable(Tanks ${SOURCE_FILES})
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(Tanks sfml-system sfml-window sfml-graphics sfml-audio sfml-network)