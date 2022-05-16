cmake_minimum_required(VERSION 3.15)
project(Battleship)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp board.cpp board.h ships.cpp ships.h players.cpp players.h fileReading.cpp fileReading.h InputChecks.cpp InputChecks.h turns.cpp turns.h playersHuman.cpp playersHuman.h playersAI.cpp playersAI.h setup.cpp setup.h AiCheat.cpp AiCheat.h AiRandom.cpp AiRandom.h AiHuntDestroy.cpp AiHuntDestroy.h)