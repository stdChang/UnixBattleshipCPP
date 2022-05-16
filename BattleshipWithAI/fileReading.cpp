//
// Created by steve on 5/15/2021.
//

#include "fileReading.h"


std::map<char, int> BattleShip::open_file(char* fileName, int & num_rows, int & num_columns, int & num_ships) {
    std::map<char, int> ship_list;
    char shipName = 'A';
    int shipLength = 0;
    std::ifstream file;
    file.open(fileName);  // Opens file with string name from command line
    file >> num_rows >> num_columns >> num_ships;
    for(int i = 0; i < num_ships; i++) {
        file >> shipName >> shipLength;
        ship_list.emplace(shipName, shipLength);
    }
    // Records num of rows, columns, and ships
    // Returns a Map of our ships and their names
    return ship_list;
}