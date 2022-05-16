//
// Created by steve on 5/27/2021.
//

#include "AiHuntDestroy.h"
BattleShip::AiHunter::AiHunter(std::map<char, int> ship_list) : AiRandom(ship_list) {
    AI_type = 3;
}

void BattleShip::AiHunter::PrioritizeThisArea(int r, int c, BattleShip::Board AiFiringBoard) {
    std::pair<int, int> coord;
    bool duplicate = false;
    //conditionals for Left, Top, Right, Bot
    if (r >= 0 && r < AiFiringBoard.num_rows && (c - 1) >= 0 && (c - 1) < AiFiringBoard.num_columns && AiFiringBoard.AtCoord(r, c - 1) == '*') {
        duplicate = false; // Reset the bool
        coord.first = r;
        coord.second = c - 1;
        for(auto pair : PriorityPlacesToShoot) {
            if (pair.first == coord.first && pair.second == coord.second) {
                duplicate = true;
            }
        }
        if (not duplicate) {
            PriorityPlacesToShoot.push_back(coord);
        }
    }
    if (r - 1 >= 0 && r - 1 < AiFiringBoard.num_rows && c >= 0 && c < AiFiringBoard.num_columns && AiFiringBoard.AtCoord(r - 1, c) == '*') {
        duplicate = false;
        coord.first = r - 1;
        coord.second = c;
        for(auto pair : PriorityPlacesToShoot) {
            if (pair.first == coord.first && pair.second == coord.second) {
                duplicate = true;
            }
        }
        if (not duplicate) {
            PriorityPlacesToShoot.push_back(coord);
        }
    }
    if (r >= 0 && r < AiFiringBoard.num_rows && (c + 1) >= 0 && (c + 1) < AiFiringBoard.num_columns && AiFiringBoard.AtCoord(r, c + 1) == '*') {
        duplicate = false;
        coord.first = r;
        coord.second = c + 1;
        for(auto pair : PriorityPlacesToShoot) {
            if (pair.first == coord.first && pair.second == coord.second) {
                duplicate = true;
            }
        }
        if (not duplicate) {
            PriorityPlacesToShoot.push_back(coord);
        }
    }
    if (r + 1 >= 0 && r + 1 < AiFiringBoard.num_rows && c >= 0 && c < AiFiringBoard.num_columns && AiFiringBoard.AtCoord(r + 1, c) == '*') {
        duplicate = false;
        coord.first = r + 1;
        coord.second = c;
        for(auto pair : PriorityPlacesToShoot) {
            if (pair.first == coord.first && pair.second == coord.second) {
                duplicate = true;
            }
        }
        if (not duplicate) {
            PriorityPlacesToShoot.push_back(coord);
        }
    }
    // Checks if their is already a pair in the non-priority vector, deletes it if found.
    for (auto pair : PriorityPlacesToShoot) {
        auto itr = PlacesToShoot.begin();
        for(itr = PlacesToShoot.begin(); itr < PlacesToShoot.end(); itr++) {
            if (pair.first == (*itr).first && pair.second == (*itr).second) {
                PlacesToShoot.erase(itr);
            }
        }
    }
}

void BattleShip::AiHunter::GetPlaceToShoot(int& r, int& c) {
    if (!PriorityPlacesToShoot.empty()) {
        r = (PriorityPlacesToShoot.at(0)).first;
        c = (PriorityPlacesToShoot.at(0)).second;
        PriorityPlacesToShoot.erase(PriorityPlacesToShoot.begin());
    }
    // checks if Priority places has any coords to shoot at first, then continues to random otherwise.
    else {
        //pick random element from place to shoot
        int index = 0;
        index = GetRandomIndex(generator);
        r = (PlacesToShoot.at(index)).first;
        c = (PlacesToShoot.at(index)).second;
        PlacesToShoot.erase(PlacesToShoot.begin() + index);
    }
}

