cmake_minimum_required(VERSION 3.12)
project(Risk)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Risk
        src/Continent.cpp
        src/Dice.cpp
        src/Main.cpp
        src/Map.cpp
        src/MapLoader.cpp
        src/stdafx.cpp
        src/Territory.cpp
<<<<<<< HEAD
<<<<<<< HEAD
        src/Card.cpp
        src/Deck.cpp
        src/Hand.cpp)
=======
        src/Player.cpp include/Player.h)
>>>>>>> origin/Restructuring
=======
        src/Player.cpp include/Player.h)
>>>>>>> Fix dice code format and start player
