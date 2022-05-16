//
// Created by steve on 5/12/2021.
//

#include "board.h"


BattleShip::Board::Board(int row_amount, int column_amount) :
        single_row(column_amount, '*'),
        list_of_rows(row_amount, single_row),
        num_rows(row_amount),
        num_columns(column_amount) {
    // Initializer list
}

void BattleShip::Board::PrintBoard() {
    std::cout << "  ";
    for (int k = 0 ; k < num_columns; k++) {
        std::cout << k << " ";
    }
    std::cout << std::endl;

    for (int i = 0; i < num_rows; i++ ) {
        std::cout << i << " ";
        for (int j = 0; j < num_columns; j++ ) {
            std::cout << list_of_rows[i][j] << ' ';
        }
        std::cout << std::endl;
    }
}

void BattleShip::Board::MarkBoard(int r, int c, char marker) {
    list_of_rows[r][c] = marker;
    // Expect marker to either be a 'X' or 'O'
}


char BattleShip::Board::AtCoord(int r, int c) {
    return list_of_rows[r][c];
    //returns whatever is at the coord, (used to check if there is a ship or has been attacked yet.)
}
