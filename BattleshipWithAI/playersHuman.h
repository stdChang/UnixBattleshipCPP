//
// Created by steve on 5/24/2021.
//

#ifndef BATTLESHIP_PLAYERSHUMAN_H
#define BATTLESHIP_PLAYERSHUMAN_H

#include "players.h"


namespace BattleShip {
    class Human : public Player {
    public:
        Human(std::map<char, int> ship_list);
        int GetPlayerType() override;
        int GetAI_type() override;
        void SetName(int player_num) override;
    };
}
#endif //BATTLESHIP_PLAYERSHUMAN_H
