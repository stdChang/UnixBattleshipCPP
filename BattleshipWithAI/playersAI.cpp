//
// Created by steve on 5/24/2021.
//

#include "playersAI.h"

int BattleShip::AI::GetPlayerType() {
    return 1; // 1 meaning Ai
}

void BattleShip::AI::SetName(int player_num) {
    AI_number += 1;
    std::string given_name = "AI " + std::to_string(AI_number); // Checks the static member to create Ai name.
    PlayerName = given_name;
}

int BattleShip::AI::GetAI_type(){
    return AI_type;
}

char BattleShip::AI::GenerateOrientation(std::mt19937& generator) {
    std::uniform_int_distribution<int> dist(0, 1);
    int num = dist(generator); // Receives from Generator either 0 or 1
    if (num == 0) {
        return 'h';
    } else {
        return 'v';
    }
}

void BattleShip::AI::GenerateCoordsToPlaceShip(std::mt19937& generator, int& r, int& c, int total_rows, int total_columns, char orientation, int ship_size){

    if (orientation == 'h') { // If horizontal create a specific distribution to generate number
        std::uniform_int_distribution<int> pickR(0, total_rows - 1);
        r = pickR(generator);
        std::uniform_int_distribution<int> pickC(0, total_columns - ship_size);
        c = pickC(generator);
    } else { // Else, vertical create a specific distribution to generate number
        std::uniform_int_distribution<int> pickR(0, total_rows - ship_size);
        r = pickR(generator);
        std::uniform_int_distribution<int> pickC(0, total_columns - 1);
        c = pickC(generator);
    }
}

void BattleShip::AI::SetupAIShips(int ships, BattleShip::Board& ai_placement, BattleShip::Board& ai_firing, int total_rows, int total_columns) {
        this->SetRemainingShips(ships);
        for (auto& ship : this->GetOwnedShips()) {
            int r = -1;
            int c = -1;
            char orientation = 'X';
            bool setup_is_complete = false;
            bool legalPlacement = false;
            while (!setup_is_complete) {
                //get orientation + moves

                orientation = this->GenerateOrientation(generator);
                this->GenerateCoordsToPlaceShip(generator, r, c, total_rows, total_columns, orientation, ship.ShipHealth); // Moves
                legalPlacement = CheckLegalPlacement(orientation, r, c, *this, ship, total_rows, total_columns, ai_placement );
                if (legalPlacement) {
                    ship.PlaceShip(r, c, orientation, ai_placement);
                    setup_is_complete = true;
                }

            }
            //print the updated board for that player after while loop
            std::cout << this->GetName() << "'s Board" << std::endl;
            ai_placement.PrintBoard();
            std::cout << std::endl;
            //then iterates to the next ship.
        }
        this->SetBoards(&ai_placement, &ai_firing);
}


BattleShip::AI::AI(std::map<char, int> ship_list) : BattleShip::Player(ship_list) {

}