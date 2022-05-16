//
// Created by steve on 5/27/2021.
//

#ifndef BATTLESHIP_AIHUNTDESTROY_H
#define BATTLESHIP_AIHUNTDESTROY_H
#include "AiRandom.h"

namespace BattleShip {
    class AiHunter : public AiRandom{
    public:
        AiHunter(std::map<char, int> ship_list);
        void GetPlaceToShoot(int& r, int& c) override;
        void PrioritizeThisArea(int r, int c, BattleShip::Board FiringBoard) override;

    private:
        std::vector<std::pair<int, int>> PriorityPlacesToShoot;

    };
}

#endif //BATTLESHIP_AIHUNTDESTROY_H
