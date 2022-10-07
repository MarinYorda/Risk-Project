cmake_minimum_required(VERSION 3.23)
project(Risk_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(Cards)
include_directories(Map)
include_directories(Player)

add_executable(Risk_Project
        Cards/Cards.cpp
        Cards/Cards.h
        Cards/CardsDriver.cpp
        Cards/CardsDriver.h
        Map/map.cpp
        Map/map.h
        Map/mapDriver.cpp
        Player/Player.cpp
        Player/Player.h
        Player/PlayerDriver.cpp
        GameEngine/GameEngine.cpp
        GameEngine/GameEngine.h
        GameEngine/GameEngineDriver.cpp
        GameEngine/GameEngineDriver.h
        helloteam.cpp)
