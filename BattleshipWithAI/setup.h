//
// Created by steve on 5/24/2021.
//

#ifndef BATTLESHIP_SETUP_H
#define BATTLESHIP_SETUP_H
#include <iostream>
#include "board.h"
#include "ships.h"
#include "players.h"
#include "fileReading.h"
#include "InputChecks.h"
#include "turns.h"
#include "playersHuman.h"
#include "playersAI.h"

namespace BattleShip {
    void HumanSetup(BattleShip::Human& HumanPlayer, int player_num, int ships, BattleShip::Board& p1_placement, BattleShip::Board& p1_firing, int total_rows, int total_columns ); // Assuming two boards and a human has been created.
    int AskGameChoice();
    int AskAiChoice();

}
#endif //BATTLESHIP_SETUP_H
