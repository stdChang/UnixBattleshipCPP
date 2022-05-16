//
// Created by steve on 5/15/2021.
//

#ifndef BATTLESHIP_PLAYERS_H
#define BATTLESHIP_PLAYERS_H

#include "players.h"
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "board.h"
#include "ships.h"


namespace BattleShip {

    class Player {
    public:
        Player(std::map<char, int> ship_list);
        Board* placement_board;
        Board* firing_board;
        virtual void SetName(int player_num) = 0;   // Pure Virtual
        std::string GetName();
        void SetRemainingShips(int total_ships);
        void deductShip();
        int GetRemainingShips();
        void SetBoards(Board* given_placement_board, Board* given_firing_board);
        std::vector<BattleShip::Ship> GetOwnedShips();
        int DamageTargetedShip(char ship_name);
        virtual void PrioritizeThisArea(int r, int c, BattleShip::Board FiringBoard);
        virtual int GetPlayerType() = 0; // Pure Virtual
        virtual int GetAI_type() = 0; // Pure Virtual

    protected:
        std::string PlayerName = "Jackie Chan"; // Jackie Chan the coolest man.
        int num_ships_left = 0;
        std::vector<BattleShip::Ship> OwnedShips;

    };

}
#endif //BATTLESHIP_PLAYERS_H
