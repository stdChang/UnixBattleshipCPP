//
// Created by steve on 5/16/2021.
//

#ifndef BATTLESHIP_INPUTCHECKS_H
#define BATTLESHIP_INPUTCHECKS_H
#include <string>
#include <iostream>
#include <sstream>
#include "players.h"
#include "ships.h"
#include "board.h"

namespace BattleShip {
    bool get_valid_coords(int& r, int& c, BattleShip::Player& currPlayer, BattleShip::Ship& currShip);
    void get_valid_orientation(char& orientation, int& r, int& c, BattleShip::Player& currPlayer, BattleShip::Ship& currShip);
    bool CheckLegalPlacement(char orientation, int r, int c, BattleShip::Player& currPlayer, BattleShip::Ship& currShip, int total_rows, int total_columns, BattleShip::Board PlacementBoard );
    bool validFire(int& r, int& c, BattleShip::Player& currPlayer, BattleShip::Player& EnemyPlayer);
    bool isLegalFire(int r, int c, BattleShip::Player& currPlayer);
}

#endif //BATTLESHIP_INPUTCHECKS_H
