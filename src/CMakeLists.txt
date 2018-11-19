cmake_minimum_required(VERSION 3.12)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src
        game/Attack.cpp
        game/Fortify.cpp
        game/Reinforce.cpp
        Card.cpp
        Continent.cpp
        Deck.cpp
        Dice.cpp
        Hand.cpp
        Main.cpp
        MainGame.cpp
        Map.cpp
        MapCreatorTester.cpp
        MapLoader.cpp
        Player.cpp
        stdafx.cpp
        Territory.cpp)
