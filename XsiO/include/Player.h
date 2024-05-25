#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

class Player
{
    public:
        Player() {}; // Constructorul clasei
        std::pair<int, int> introducereMutare(); // Permite jucatorului uman sa introduca o mutare
        ~Player() {}; // Destructorul clasei
        void centru(std::string text); // Centreaza textul in consola
};

#endif // PLAYER_H
