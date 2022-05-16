//
// Created by steve on 5/15/2021.
//

#ifndef BATTLESHIP_FILEREADING_H
#define BATTLESHIP_FILEREADING_H
#include <iostream>
#include <fstream>
#include <string>
#include <map>


namespace BattleShip {
    std::map<char, int> open_file(char* fileName, int & num_rows, int & num_columns, int & num_ships);
}

#endif //BATTLESHIP_FILEREADING_H
