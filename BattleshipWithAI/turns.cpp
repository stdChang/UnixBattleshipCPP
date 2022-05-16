//
// Created by steve on 5/17/2021.
//

#include "turns.h"


void BattleShip::PrintTwoBoards(BattleShip::Player& currPlayer){
    std::cout << currPlayer.GetName() << "'s Firing Board" << std::endl;
    (*(currPlayer.firing_board)).PrintBoard();
    std::cout << std::endl << std::endl;
    std::cout << currPlayer.GetName() << "'s Placement Board" << std::endl;
    (*(currPlayer.placement_board)).PrintBoard();
}

bool BattleShip::GetMoveInput(BattleShip::Player& currPlayer, BattleShip::Player& EnemyPlayer, int& r, int& c) {
    std::cout << currPlayer.GetName() << ", where would you like to fire?\nEnter your attack coordinate in the form row col: ";
    return BattleShip::validFire(r, c, currPlayer, EnemyPlayer);
}

void BattleShip::FireTheShot(BattleShip::Player& currPlayer, BattleShip::Player& EnemyPlayer, int r, int c) {
    BattleShip::Board& EnemyPlacementBoard = *(EnemyPlayer.placement_board);
    BattleShip::Board& AllyFiringBoard = *(currPlayer.firing_board);
    char ShipHit = '*';
    int ShipRemainingHealth = 99;
    if (EnemyPlacementBoard.AtCoord(r, c) != '*') { // a hit
        ShipHit = EnemyPlacementBoard.AtCoord(r, c);
        EnemyPlacementBoard.MarkBoard(r, c, 'X');
        AllyFiringBoard.MarkBoard(r, c, 'X');
        BattleShip::PrintTwoBoards(currPlayer);
        std::cout << currPlayer.GetName() << " hit " << EnemyPlayer.GetName() << "'s " << ShipHit << "!" << std::endl << std::endl;
        // small section for hunt and destroy AI
        if (currPlayer.GetPlayerType() == 1 && currPlayer.GetAI_type() == 3) {
            currPlayer.PrioritizeThisArea(r, c, *(currPlayer.firing_board));
        }
        ShipRemainingHealth = EnemyPlayer.DamageTargetedShip(ShipHit); // Check for ship's full destruction
        if (ShipRemainingHealth == 0) {
            EnemyPlayer.deductShip();
            std::cout << currPlayer.GetName() << " destroyed " << EnemyPlayer.GetName() << "'s " << ShipHit << "!" << std::endl;
        }
    } else {
        EnemyPlacementBoard.MarkBoard(r, c, 'O');
        AllyFiringBoard.MarkBoard(r, c, 'O');
        BattleShip::PrintTwoBoards(currPlayer);
        std::cout << "Missed." << std::endl << std::endl;
    }
}

bool BattleShip::checkForWinner(BattleShip::Player &currPlayer, BattleShip::Player &EnemyPlayer) {
    if (EnemyPlayer.GetRemainingShips() == 0) {
        return BattleShip::Victory(currPlayer);
    } else {
        return false;
    }
}

bool BattleShip::Victory(BattleShip::Player& currPlayer) {
   std::cout << std::endl;
    std::cout << currPlayer.GetName() << " won the game!" << std::endl;
    exit(0);
    return true;
}

void BattleShip::playHumanTurn(BattleShip::Human& currPlayer, BattleShip::Player& enemyPlayer, bool& GameOver) {
    int r = -1;
    int c = -1;
    bool TargetFound = false;
    while(!TargetFound){
        BattleShip::PrintTwoBoards(currPlayer);
        TargetFound = GetMoveInput(currPlayer, enemyPlayer, r, c);
    }
    FireTheShot(currPlayer, enemyPlayer, r, c);
    GameOver = BattleShip::checkForWinner(currPlayer, enemyPlayer);
}

void BattleShip::playAiTurn(BattleShip::AI& currPlayer, BattleShip::Player& enemyPlayer, bool& GameOver) {
    int r = -1;
    int c = -1;
    currPlayer.GetPlaceToShoot(r, c);
    FireTheShot(currPlayer, enemyPlayer, r, c);
    GameOver = BattleShip::checkForWinner(currPlayer, enemyPlayer);
}

void BattleShip::initHumanVsHumanGame(BattleShip::Human& currPlayer, BattleShip::Human& enemyPlayer) {
    bool GameOver = false;
    BattleShip::playHumanTurn(currPlayer, enemyPlayer, GameOver);
    std::swap(currPlayer,enemyPlayer);

    while(!GameOver) {
        BattleShip::playHumanTurn(currPlayer, enemyPlayer, GameOver);
        std::swap(currPlayer,enemyPlayer);
    }
}

void BattleShip::initAiVsAiGame(BattleShip::AI& Player1, BattleShip::AI& Player2) {
    bool GameOver = false;
    BattleShip::playAiTurn(Player1, Player2, GameOver);

    while(!GameOver) {
        BattleShip::playAiTurn(Player2, Player1, GameOver);
        BattleShip::playAiTurn(Player1, Player2, GameOver);
    }
}