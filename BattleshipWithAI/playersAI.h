//
// Created by steve on 5/24/2021.
//

#ifndef BATTLESHIP_PLAYERSAI_H
#define BATTLESHIP_PLAYERSAI_H
#include <string>
#include <utility>
#include <vector>
#include "players.h"
#include <random>
#include "InputChecks.h"

namespace BattleShip {
    class AI : public Player {
    public:
        static std::mt19937 generator;
        AI(std::map<char, int> ship_list);
        int GetPlayerType() override;
        void SetName(int player_num) override;
        void SetupAIShips(int ships, BattleShip::Board& ai_placement, BattleShip::Board& ai_firing, int total_rows, int total_columns);
        int GetAI_type() override;
        virtual void SetupPlacesToShoot(BattleShip::Board EnemyPlacementBoard) = 0;
        char GenerateOrientation(std::mt19937& generator);
        void GenerateCoordsToPlaceShip(std::mt19937& generator, int& r, int& c, int total_rows, int total_columns, char orientation, int ship_size);
        virtual void GetPlaceToShoot(int& r, int& c) = 0;

    protected:
        int AI_type = 0;
        std::vector<std::pair<int, int>> PlacesToShoot;

    private:
        static int AI_number;

    };
}
#endif //BATTLESHIP_PLAYERSAI_H
