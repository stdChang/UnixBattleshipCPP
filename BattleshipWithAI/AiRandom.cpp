//
// Created by steve on 5/27/2021.
//

#include "AiRandom.h"

BattleShip::AiRandom::AiRandom(std::map<char, int> ship_list) : BattleShip::AI(ship_list){
    AI_type = 2;
}

void BattleShip::AiRandom::SetupPlacesToShoot(BattleShip::Board EnemyPlacementBoard) {
    std::pair<int, int> coord;
    // Very traditional, Sets up places to shoot. row by row, column by column
    for (int r = 0; r < EnemyPlacementBoard.num_rows; r++) {
        for (int c = 0; c < EnemyPlacementBoard.num_columns; c++) {
            coord.first = r;
            coord.second = c;
            PlacesToShoot.push_back(coord);
        }
    }
}

void BattleShip::AiRandom::GetPlaceToShoot(int& r, int& c) {
    //pick random element from place to shoot
    int index = 0;
    index = GetRandomIndex(generator); // Asks generator for random index.
    r = (PlacesToShoot.at(index)).first;
    c = (PlacesToShoot.at(index)).second;
    PlacesToShoot.erase(PlacesToShoot.begin() + index);
}

int BattleShip::AiRandom::GetRandomIndex(std::mt19937& generator) {
    std::uniform_int_distribution<int> dist(0, PlacesToShoot.size() - 1);
    int index = dist(generator);
    return index;

}
