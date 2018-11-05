cmake_minimum_required(VERSION 3.12)
project(Risk)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

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

        src/stdafx.h
        src/Territory.cpp
        include/game/Reinforce.h
        src/game/Reinforce.cpp
        src/game/Fortify.cpp
        include/game/Fortify.h)
