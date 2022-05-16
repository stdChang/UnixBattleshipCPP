//
// Created by steve on 5/26/2021.
//

#include "AiCheat.h"

BattleShip::AiCheater::AiCheater(std::map<char, int> ship_list) : BattleShip::AI(ship_list) {
    AI_type = 1;
}

void BattleShip::AiCheater::SetupPlacesToShoot(BattleShip::Board EnemyPlacementBoard) {

    std::pair<int, int> coord;
    for (int r = 0; r < EnemyPlacementBoard.num_rows; r++) {
        for (int c = 0; c < EnemyPlacementBoard.num_rows; c++) {
            if ( EnemyPlacementBoard.AtCoord(r, c) != '*') {
                // Scans only areas where there is a ship
                coord.first = r;
                coord.second = c;
                PlacesToShoot.push_back(coord);
                //Sends coord to our Places to Shoot.
            }
        }
    }
}

void BattleShip::AiCheater::GetPlaceToShoot(int& r, int& c) {
    r = (PlacesToShoot[0]).first;
    c = (PlacesToShoot[0]).second;
    PlacesToShoot.erase(PlacesToShoot.begin());
}