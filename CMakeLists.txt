cmake_minimum_required(VERSION 3.12)
project(Risk)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(src)

add_executable(Risk
        include/Card.h
        include/Continent.h
        include/Deck.h
        include/Dice.h
        include/Hand.h
        include/Map.h
        include/MapLoader.h
        include/Player.h
        include/stdafx.h
        include/targetver.h
        include/Territory.h
        src/Card.cpp
        src/Continent.cpp
        src/Deck.cpp
        src/Dice.cpp
        src/Hand.cpp
        src/Main.cpp
        src/Map.cpp
        src/MapCreatorTester.cpp
        src/MapLoader.cpp
        src/Player.cpp
        src/stdafx.cpp
<<<<<<< HEAD
        src/Territory.cpp
        src/Card.cpp
        src/Deck.cpp
        src/Hand.cpp
        src/Player.cpp
        src/MainGame.cpp
        include/MainGame.h)
=======
        src/stdafx.h
        src/Territory.cpp)
>>>>>>> c1bc95c756c5067ff0fa0f46a13201c23d3b17ed
