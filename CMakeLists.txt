cmake_minimum_required(VERSION 3.23)
project(Risk_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(Cards)
include_directories(Player)

add_executable(Risk_Project
        Cards/Cards.cpp
        Cards/Cards.h
        Cards/CardsDriver.cpp
        Cards/CardsDriver.h
        Player/Player.cpp
        Player/Player.h
        helloteam.cpp
        map.cpp
        map.h
        mapDriver.cpp)
