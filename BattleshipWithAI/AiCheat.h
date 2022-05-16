//
// Created by steve on 5/26/2021.
//

#ifndef BATTLESHIP_AICHEAT_H
#define BATTLESHIP_AICHEAT_H
#include "playersAI.h"

namespace BattleShip {
    class AiCheater : public AI {
    public:
        AiCheater(std::map<char, int> ship_list);
        void SetupPlacesToShoot(BattleShip::Board EnemyPlacementBoard) override;
        void GetPlaceToShoot(int& r, int& c) override;
    };
}

#endif //BATTLESHIP_AICHEAT_H
