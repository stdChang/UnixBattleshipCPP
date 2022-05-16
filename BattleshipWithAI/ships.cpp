//
// Created by steve on 5/12/2021.
//
#include "board.h"
#include "ships.h"

BattleShip::Ship::Ship() {

}

void BattleShip::Ship::InitializeShip(char name_arg, int health_arg) {
    ShipName = name_arg;
    ShipHealth = health_arg;
    OccupiedSpaces.resize(health_arg);

}

void BattleShip::Ship::PlaceShip(int row, int column, char orientation, BattleShip::Board& PlacementBoard) {
    std::pair<int, int> coordinate(0, 0); //make a pair and insert it to

    if (orientation == 'v' || orientation == 'V') {
        //mark the board at starting coords
        //then mark the board going down
        for(int i = 0; i < ShipHealth; i++) {
            PlacementBoard.MarkBoard(row + i, column, ShipName);
            coordinate.first = row + i;
            coordinate.second = column;
            OccupiedSpaces.push_back(coordinate);
            //save each coord along the way as a pair and insert that pair to the OccupiedSpaces
        }
    }

    else if (orientation == 'h' || orientation == 'H' ) {
        for(int i = 0; i < ShipHealth; i++) {
            PlacementBoard.MarkBoard(row , column + i, ShipName);
            coordinate.first = row;
            coordinate.second = column + i;
            OccupiedSpaces.push_back(coordinate);
        }
    }
}






