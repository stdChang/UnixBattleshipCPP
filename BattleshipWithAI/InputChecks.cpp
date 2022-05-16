//
// Created by steve on 5/16/2021.
//

#include "InputChecks.h"



bool BattleShip::get_valid_coords(int& r, int& c, BattleShip::Player& currPlayer, BattleShip::Ship& currShip) {  // Adapted form Professor's Invalid input
    std::string line;
    std::cout << currPlayer.GetName() << ", enter the row and column you want to place " << currShip.ShipName << ", which is " << currShip.ShipHealth << " long, at with a space in between row and col: ";
    std::getline(std::cin, line); // Gets the lines and puts into sstream
    std::stringstream input_stream(line);
    int r_input = -1;
    int c_input = -1;
    input_stream >> r_input >> c_input;
    if (input_stream) {
        std::string leftover;  // scans for leftover items
        input_stream >> leftover;
        if (not input_stream && r_input >= 0 && c_input >=0) {
            r = r_input;
            c = c_input;
            return true;
        }
        else {
            return false;
        }
    }
}

void BattleShip::get_valid_orientation(char& orientation, int& r, int& c, BattleShip::Player& currPlayer, BattleShip::Ship& currShip) {  // Adapted form Professor's Invalid input
    std::string line;
    bool validInputFound = false;
    while (!validInputFound) { //loop until good answer is given
        std::cout << currPlayer.GetName() << ", do you want to place " << currShip.ShipName << " horizontally or vertically?" << std::endl;
        std::cout << "Enter h for horizontal or v for vertical\nYour choice: ";
        std::getline(std::cin, line);
        std::stringstream input_stream(line);
        char answer;
        input_stream >> answer;
        if (input_stream) {
            std::string leftover;  // scans for leftover items
            input_stream >> leftover;
            if (not input_stream && (tolower(answer) == 'h' || tolower(answer) == 'v') ) {
                orientation = answer;
                validInputFound = get_valid_coords(r, c, currPlayer, currShip);
                // Gets coords after orientation.
            }
        }
    }
}

bool BattleShip::CheckLegalPlacement(char orientation, int r, int c, BattleShip::Player& currPlayer, BattleShip::Ship& currShip, int total_rows, int total_columns, BattleShip::Board PlacementBoard ) {
    if (tolower(orientation) == 'v' && c >= 0 && c < total_columns && r >= 0 && (r + currShip.ShipHealth - 1) < total_rows) {
        for(int i = 0; i < currShip.ShipHealth; i++) {
            if (PlacementBoard.AtCoord(r + i, c) != '*') {
                // If ship is already existing there.
                return false;
            }
        }
        return true;
    }
    else if (tolower(orientation) == 'h' && c >= 0 && (c + currShip.ShipHealth - 1) < total_columns && r >= 0 && r < total_rows) {
        for(int i = 0; i < currShip.ShipHealth; i++) {
            if (PlacementBoard.AtCoord(r , c + i) != '*') {
                // If ship is already existing there.
                return false;
            }
        }
        return true;
    }
    else {
        return false;
    }
}

bool BattleShip::validFire(int& r, int& c, BattleShip::Player& currPlayer, BattleShip::Player& EnemyPlayer) {  // Adapted form Professor's Invalid input
    std::string line;
    std::getline(std::cin, line);
    std::stringstream input_stream(line);
    int r_input = -1;
    int c_input = -1;
    bool LegalFire = false;
    input_stream >> r_input >> c_input;
    if (input_stream) {
        std::string leftover;  // scans for leftover items
        input_stream >> leftover;
        if (r_input >= 0 && r_input < (*(currPlayer.firing_board)).num_rows && c_input >= 0 && c_input < (*(currPlayer.firing_board)).num_columns) {
            LegalFire = isLegalFire(r_input, c_input, currPlayer);
        }
        if (not input_stream && r_input >= 0 && c_input >= 0 && LegalFire) {
            r = r_input;
            c = c_input;
            return true;
        }
        else {
            return false;
        }
    } else {
        return false;
    }
}

bool BattleShip::isLegalFire(int r, int c, BattleShip::Player& currPlayer) {
    if ( (*(currPlayer.firing_board)).AtCoord(r, c) == '*') {
        return true;
    }
    else {
        return false;
    }
}





