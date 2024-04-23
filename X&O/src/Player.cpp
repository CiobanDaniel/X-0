#include "Player.h"
#include <iostream>

std::pair<int, int> Player::introducereMutare()
{
    int rand, coloana;
    std::cout << "Introduceti randul si coloana: ";
    std::cin >> rand >> coloana;
    return {rand-1, coloana-1};
}
