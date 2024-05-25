#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include "Table.h"

class Computer
{

public:
    Computer(); // Constructorul clasei
    std::pair<int, int> generareMutare(); // Genereaza mutarea computerului
    std::pair<int, int> generareMutare2(std::vector<int>& miscariValide); // Genereaza mutarea computerului dar mai inteligent putin
};

#endif // COMPUTER_H
