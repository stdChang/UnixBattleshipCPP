#include <chrono>
#include "board.h"
#include "ships.h"
#include "players.h"
#include "fileReading.h"
#include "turns.h"
#include "setup.h"
#include <random>

int BattleShip::AI::AI_number = 0;
std::mt19937 BattleShip::AI::generator;

int main(int argc, char* argv[]) {
    int total_rows = 0;
    int total_columns = 0;
    int ships = 0;
    int seed = 0;
    int game_choice = 0;
    int ai_choice = 0;

    std::map<char, int> ship_list;
    ship_list = BattleShip::open_file(argv[1], total_rows, total_columns, ships);
    if (argc == 3) {
        seed = atoi(argv[2]);
        BattleShip::AI::generator.seed(seed);
    } else {
        seed = std::chrono::system_clock::now().time_since_epoch().count(); // Seeds with time otherwise
        BattleShip::AI::generator.seed(seed);
    }

    game_choice = BattleShip::AskGameChoice();
    if (game_choice == 1) { //Human game
        BattleShip::Human Player1(ship_list);
        BattleShip::Board p1_placement(total_rows, total_columns);
        BattleShip::Board p1_firing(total_rows, total_columns);
        BattleShip::HumanSetup(Player1, 1, ships, p1_placement, p1_firing, total_rows, total_columns );

        BattleShip::Human Player2(ship_list);
        BattleShip::Board p2_placement(total_rows, total_columns);
        BattleShip::Board p2_firing(total_rows, total_columns);
        BattleShip::HumanSetup(Player2, 2, ships, p2_placement, p2_firing, total_rows, total_columns );
        //Sets up the humans

        BattleShip::initHumanVsHumanGame(Player1, Player2);
    } //Human game
    else if (game_choice == 2) {
        int ai_choice = 0;
        //setup human
        BattleShip::Human Player1(ship_list);
        BattleShip::Board p1_placement(total_rows, total_columns);
        BattleShip::Board p1_firing(total_rows, total_columns);
        BattleShip::HumanSetup(Player1, 1, ships, p1_placement, p1_firing, total_rows, total_columns );

        //setup AI
        //first ask which ai to use
        ai_choice = BattleShip::AskAiChoice();
        //then branch again into 3 choices.
        if (ai_choice == 1) {
            BattleShip::AiCheater Player2(ship_list);
            BattleShip::Board p2_placement(total_rows, total_columns);
            BattleShip::Board p2_firing(total_rows, total_columns);
            Player2.SetName(1);
            // uses AI overridden function to replace "Jackie Chan" with Ai#. Arguments only used when Human vs Human.
            Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
            Player2.SetupPlacesToShoot(p1_placement);

            // Play Game
            bool GameOver = false;
            BattleShip::playHumanTurn(Player1, Player2, GameOver); // Remember that Player1 is human, Player2 is Ai
            while(!GameOver) {
                BattleShip::playAiTurn(Player2, Player1, GameOver);
                BattleShip::playHumanTurn(Player1, Player2, GameOver);
            }
            // Play Game
        }
        else if (ai_choice == 2) {
            BattleShip::AiRandom Player2(ship_list);
            BattleShip::Board p2_placement(total_rows, total_columns);
            BattleShip::Board p2_firing(total_rows, total_columns);
            Player2.SetName(1);
            Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
            Player2.SetupPlacesToShoot(p1_placement);

            // Play Game
            bool GameOver = false;
            BattleShip::playHumanTurn(Player1, Player2, GameOver);
            while(!GameOver) {
                BattleShip::playAiTurn(Player2, Player1, GameOver);
                BattleShip::playHumanTurn(Player1, Player2, GameOver);
            }
            // Play Game
        }
        else if (ai_choice == 3) {
            BattleShip::AiHunter Player2(ship_list);
            BattleShip::Board p2_placement(total_rows, total_columns);
            BattleShip::Board p2_firing(total_rows, total_columns);
            Player2.SetName(1);

            Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
            Player2.SetupPlacesToShoot(p1_placement);

            // Play Game
            bool GameOver = false;
            BattleShip::playHumanTurn(Player1, Player2, GameOver); // Remember that Player1 is human, Player2 is Ai
            while(!GameOver) {
                BattleShip::playAiTurn(Player2, Player1, GameOver);
                BattleShip::playHumanTurn(Player1, Player2, GameOver);
            }
            // Play Game
        }
    }
    else if (game_choice == 3) {
        int ai_choice = 0;
        //setup AI
        //first ask which ai to use
        ai_choice = BattleShip::AskAiChoice();
        //then branch again into 3 choices.
        if (ai_choice == 1) {
            BattleShip::AiCheater Player1(ship_list);
            BattleShip::Board p1_placement(total_rows, total_columns);
            BattleShip::Board p1_firing(total_rows, total_columns);
            Player1.SetName(1);

            Player1.SetupAIShips(ships, p1_placement, p1_firing, total_rows, total_columns);

            ai_choice = 0;
            ai_choice = BattleShip::AskAiChoice();
            //then branch again into 3 choices.
            if (ai_choice == 1) {
                BattleShip::AiCheater Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(2);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            } else if (ai_choice == 2) {
                BattleShip::AiRandom Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(1);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            } else if (ai_choice == 3) {
                BattleShip::AiHunter Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(1);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            }
        } else if (ai_choice == 2) {
            BattleShip::AiRandom Player1(ship_list);
            BattleShip::Board p1_placement(total_rows, total_columns);
            BattleShip::Board p1_firing(total_rows, total_columns);
            Player1.SetName(1);

            Player1.SetupAIShips(ships, p1_placement, p1_firing, total_rows, total_columns);

            ai_choice = 0;
            ai_choice = BattleShip::AskAiChoice();
            //then branch again into 3 choices.
            if (ai_choice == 1) {
                BattleShip::AiCheater Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(2);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            } else if (ai_choice == 2) {
                BattleShip::AiRandom Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(1);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            } else if (ai_choice == 3) {
                BattleShip::AiHunter Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(1);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            }
        } else if (ai_choice == 3) {
            BattleShip::AiHunter Player1(ship_list);
            BattleShip::Board p1_placement(total_rows, total_columns);
            BattleShip::Board p1_firing(total_rows, total_columns);
            Player1.SetName(1);

            Player1.SetupAIShips(ships, p1_placement, p1_firing, total_rows, total_columns);

            ai_choice = 0;
            ai_choice = BattleShip::AskAiChoice();
            //then branch again into 3 choices.
            if (ai_choice == 1) {
                BattleShip::AiCheater Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(2);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            } else if (ai_choice == 2) {
                BattleShip::AiRandom Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(1);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            } else if (ai_choice == 3) {
                BattleShip::AiHunter Player2(ship_list);
                BattleShip::Board p2_placement(total_rows, total_columns);
                BattleShip::Board p2_firing(total_rows, total_columns);
                Player2.SetName(1);

                Player2.SetupAIShips(ships, p2_placement, p2_firing, total_rows, total_columns);
                Player1.SetupPlacesToShoot(p2_placement);
                Player2.SetupPlacesToShoot(p1_placement);
                BattleShip::initAiVsAiGame(Player1, Player2);
            }
        }
    }
    return 0;
}

