//
// Created by steve on 5/17/2021.
//

#ifndef BATTLESHIP_TURNS_H
#define BATTLESHIP_TURNS_H
#include "board.h"
#include "ships.h"
#include "players.h"
#include "InputChecks.h"
#include <cstdlib>
#include <utility>
#include "playersHuman.h"
#include "playersAI.h"
#include "AiRandom.h"
#include "AiHuntDestroy.h"
#include "AiCheat.h"
#include "turns.h"
namespace BattleShip {
    void PrintTwoBoards(BattleShip::Player& currPlayer);
    bool GetMoveInput(BattleShip::Player& currPlayer, BattleShip::Player& EnemyPlayer, int& r, int& c);
    void FireTheShot(BattleShip::Player& currPlayer, BattleShip::Player& EnemyPlayer, int r, int c);
    bool checkForWinner(BattleShip::Player& currPlayer, BattleShip::Player& EnemyPlayer);
    bool Victory(BattleShip::Player& currPlayer);
    void playHumanTurn(BattleShip::Human& currPlayer, BattleShip::Player& enemyPlayer, bool& GameOver);
    void initHumanVsHumanGame(BattleShip::Human& currPlayer, BattleShip::Human& enemyPlayer);
    void playAiTurn(BattleShip::AI& currPlayer, BattleShip::Player& enemyPlayer, bool& GameOver);
    void initAiVsAiGame(BattleShip::AI& Player1, BattleShip::AI& Player2);


}

#endif //BATTLESHIP_TURNS_H
