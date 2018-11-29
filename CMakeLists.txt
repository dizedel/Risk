cmake_minimum_required(VERSION 3.12)
project(Risk)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)
include_directories(include/game)
include_directories(include/Pattern)
include_directories(include/strategy)
include_directories(src)

add_executable(Risk
        include/game/Attack.h
        include/game/Fortify.h
        include/game/Reinforce.h
        include/Pattern/GameStats.h
        include/Pattern/Observer.h
        include/Pattern/PlayerView.h
        include/Pattern/Subject.h
        include/strategy/AggressivePlayer.h
        include/strategy/BenevolentPlayer.h
        include/strategy/HumanPlayer.h
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
        include/Strategy.h
        include/targetver.h
        include/Territory.h
        src/driver/Main2.cpp
        src/game/Attack.cpp
        src/game/Fortify.cpp
        src/game/Reinforce.cpp
        src/pattern/GameStats.cpp
        src/pattern/Observer.cpp
        src/pattern/PlayerView.cpp
        src/pattern/Subject.cpp
        src/strategy/AggressivePlayer.cpp
        src/strategy/BenevolentPlayer.cpp
        src/strategy/HumanPlayer.cpp
        src/strategy/Strategy.cpp
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
        src/Territory.cpp include/tournament.h src/tournament.cpp)
