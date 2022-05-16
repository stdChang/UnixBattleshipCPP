//
// Created by steve on 5/15/2021.
//

#include "players.h"



BattleShip::Player::Player(std::map<char, int> ship_list) {
    OwnedShips.resize(ship_list.size()); // List of Ships per Player
    auto itr = ship_list.begin();
    for (auto& ship : OwnedShips) {
        ship.InitializeShip(itr->first, itr->second);
        // Name and Ship size initialized per ship
        itr++;
    }
}

std::string BattleShip::Player::GetName() {
    return PlayerName;
}

void BattleShip::Player::SetRemainingShips(int total_ships) {
    num_ships_left = total_ships; // Initializes Player's ships
}
void BattleShip::Player::deductShip() {
    num_ships_left -= 1;
    // Ship is 'destroyed'
}

int BattleShip::Player::GetRemainingShips() {
    return num_ships_left;
}

void BattleShip::Player::SetBoards(Board *given_placement_board, Board *given_firing_board) {
    placement_board = given_placement_board;
    firing_board = given_firing_board;
    //Gives both boards to one player.
}

void BattleShip::Player::PrioritizeThisArea(int r, int c, BattleShip::Board FiringBoard) {
    return;
}

std::vector<BattleShip::Ship> BattleShip::Player::GetOwnedShips() {
    return OwnedShips;
}

int BattleShip::Player::DamageTargetedShip(char ship_name) {
    int remaining_ship_health = 99;
    for(auto& ship : OwnedShips) {
        if(ship.ShipName == ship_name) {
            ship.ShipHealth -= 1;
            remaining_ship_health = ship.ShipHealth;
        }
    }
    // Hits The ship given their name. deducts the ship's health
    return remaining_ship_health;

}



