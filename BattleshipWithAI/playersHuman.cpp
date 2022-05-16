//
// Created by steve on 5/24/2021.
//

#include "playersHuman.h"

int BattleShip::Human::GetPlayerType() {
    return 0; // 0 meaning Human
}

int BattleShip::Human::GetAI_type() {
    return 0; // 0 meaning not any type of AI
}

void BattleShip::Human::SetName(int player_num) {
    std::string given_name;
    std::cout << "Player " << player_num << " please enter your name: ";
    std::getline(std::cin, given_name);
    PlayerName = given_name;
}

BattleShip::Human::Human(std::map<char, int> ship_list) : BattleShip::Player(ship_list) {

}