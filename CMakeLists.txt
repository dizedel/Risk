cmake_minimum_required(VERSION 3.12)
project(Risk)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/game)
include_directories(src)

add_executable(Risk
        include/game/Fortify.h
        include/game/Reinforce.h
        include/Card.h
        include/Continent.h
        include/Deck.h
        include/Dice.h
        include/Hand.h
        include/MainGame.h
        include/Map.h
        include/MapLoader.h
        include/Player.h
        include/stdafx.h
        include/targetver.h
        include/Territory.h
        src/game/Fortify.cpp
        src/game/Reinforce.cpp
        src/Card.cpp
        src/Continent.cpp
        src/Deck.cpp
        src/Dice.cpp
        src/Hand.cpp
        src/Main.cpp
        src/MainGame.cpp
        src/Map.cpp
        src/MapCreatorTester.cpp
        src/MapLoader.cpp
        src/Player.cpp
        src/stdafx.cpp
        include/stdafx.h
        src/Territory.cpp src/game/Attack.cpp include/game/Attack.h src/strategy/Strategy.cpp include/strategy/Strategy.h src/strategy/HumanPlayer.cpp include/strategy/HumanPlayer.h src/strategy/BenevolentPlayer.cpp include/strategy/BenevolentPlayer.h src/strategy/AggressivePlayer.cpp include/strategy/AggressivePlayer.h src/driver/Main2.cpp)
