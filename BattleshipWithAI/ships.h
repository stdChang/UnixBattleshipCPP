//
// Created by steve on 5/12/2021.
//

#ifndef BATTLESHIP_SHIPS_H
#define BATTLESHIP_SHIPS_H
#include <vector>
#include <utility>
namespace BattleShip {
    class Ship {
        public:
            Ship();
            void PlaceShip(int row, int column, char orientation, BattleShip::Board& PlacementBoard);
            int ShipHealth = 0;
            char ShipName = '*';
            void InitializeShip(char name_arg, int health_arg);

        private:
            std::vector< std::pair<int, int> > OccupiedSpaces;
    };
}
#endif //BATTLESHIP_SHIPS_H
