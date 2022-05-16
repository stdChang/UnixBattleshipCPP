//
// Created by steve on 5/12/2021.
//

#ifndef BATTLESHIP_BOARD_H
#define BATTLESHIP_BOARD_H
#include <vector>
#include <iostream>
namespace BattleShip {
    class Board {
        public:
            Board(int row_amount, int column_amount);
            int num_rows;
            int num_columns;
            void PrintBoard();
            void MarkBoard(int r, int c, char marker);
            char AtCoord(int r, int c);

        private:
            std::vector<char> single_row;  // array creator (columns)
            std::vector<std::vector<char>> list_of_rows; // array creator (rows)
    };
}
#endif //BATTLESHIP_BOARD_H
