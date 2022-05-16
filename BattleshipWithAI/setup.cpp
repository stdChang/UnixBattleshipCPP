//
// Created by steve on 5/24/2021.
//

#include "setup.h"

int BattleShip::AskGameChoice(){
    int choice = 69;
    bool goodChoice = false;
    while(!goodChoice) {
        std::cout << "What type of game do you want to play?\n1. Human vs Human\n2. Human vs AI\n3. AI vs AI\nYour choice: ";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream input_stream(line);
        input_stream >> choice;
        if (input_stream) {
            std::string leftover;  // scans for leftover items
            input_stream >> leftover;
            if (not input_stream && choice <= 3 && choice >= 1) {
                goodChoice = true;
                return choice;
            }
        }
    }
    return 0;
}

int BattleShip::AskAiChoice(){
    int choice = 69;
    bool goodChoice = false;
    while(!goodChoice) {
        std::cout << "What AI do you want?\n1. Cheating AI\n2. Random AI\n3. Hunt Destroy AI\nYour choice: ";
        std::string line;
        std::getline(std::cin, line);
        std::stringstream input_stream(line);
        input_stream >> choice;
        if (input_stream) {
            std::string leftover;  // scans for leftover items
            input_stream >> leftover;
            if (not input_stream && choice <= 3 && choice >= 1) {
                goodChoice = true;
                return choice;
            }
        }
    }
    return 0;
}

void BattleShip::HumanSetup(BattleShip::Human& HumanPlayer, int player_num, int ships, BattleShip::Board& p1_placement, BattleShip::Board& p1_firing, int total_rows, int total_columns ) {
    HumanPlayer.SetName(player_num); // player_num
    HumanPlayer.SetRemainingShips(ships);
    p1_placement.PrintBoard();
    for (auto& ship : HumanPlayer.GetOwnedShips()) {
        int r = -1;
        int c = -1;
        char orientation = 'X';
        bool setup_is_complete = false;
        bool legalPlacement = false;
        while (!setup_is_complete) {
            // Get input and verify it for horizontal or vertical (pass by reference a char variable for orientation, r for rows, c for columns)
            // Loops until it gets a good orientation and (r,c) in consecutive order (remember, if given bad coords, go back to orientation question)
            // (while loop in this function so it won't leave till valid)
            BattleShip::get_valid_orientation(orientation, r, c, HumanPlayer, ship);

            // Now we assumed that functions worked, we have a valid orientation, r, c on our hands
            // Take our orientation, r, c and try to test for valid move. (another separate function that returns bool) CheckLegalPlacement()
            // if CheckLegalPlacement() is true, Place our ship, then set setup_is_complete = true.
            // Else, it's gonna restart from the beginning anyways.
            legalPlacement = CheckLegalPlacement(orientation, r, c, HumanPlayer, ship, total_rows, total_columns, p1_placement );
            if (legalPlacement) {
                ship.PlaceShip(r, c, orientation, p1_placement);
                setup_is_complete = true;
            }

        }
        //print the updated board for that player after while loop
        p1_placement.PrintBoard();
        //then iterates to the next ship.
    }
    HumanPlayer.SetBoards(&p1_placement, &p1_firing); //Give the updated board and firing board to Player 1

}

