//
// Created by steve on 5/27/2021.
//

#ifndef BATTLESHIP_AIRANDOM_H
#define BATTLESHIP_AIRANDOM_H
#include "playersAI.h"

namespace BattleShip {
    class AiRandom : public AI{
    public:
        AiRandom(std::map<char, int> ship_list);
        void SetupPlacesToShoot(BattleShip::Board EnemyPlacementBoard) override;
        void GetPlaceToShoot(int& r, int& c) override;

    protected:
        int GetRandomIndex(std::mt19937& generator);
    };
}

#endif //BATTLESHIP_AIRANDOM_H
