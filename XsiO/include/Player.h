#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
    public:
        Player() {};
        std::pair<int, int> introducereMutare();
        ~Player() {}
        void centru(std::string text);
};

#endif // PLAYER_H
