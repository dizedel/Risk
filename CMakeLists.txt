cmake_minimum_required(VERSION 3.12)
project(Risk)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(Risk
        include/Continent.h
        include/Dice.h
        include/Map.h
        include/MapLoader.h
        include/Player.h
        include/stdafx.h
        include/targetver.h
        include/Territory.h
        src/Continent.cpp
        src/Dice.cpp
        src/Main.cpp
        src/Map.cpp
        src/MapLoader.cpp
        src/Player.cpp
        src/stdafx.cpp
        src/Territory.cpp)
