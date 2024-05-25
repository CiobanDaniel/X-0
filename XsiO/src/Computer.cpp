#include "Computer.h"
#include <cstdlib>
#include <ctime>
#include "Table.h"

Computer::Computer() {} // Constructorul clasei

std::pair<int, int> Computer::generareMutare() // Genereaza mutarea computerului
{
    std::srand(std::time(nullptr));
    int linie = std::rand() % 3;
    int coloana = std::rand() % 3;
    Table* tabla;
    while (!tabla->esteMutareValida(linie, coloana))
    {
        linie = std::rand() % 3;
        coloana = std::rand() % 3;
    }

    return std::make_pair(linie, coloana);
}

std::pair<int, int> Computer::generareMutare2(std::vector<int>& miscariValide) // Genereaza mutarea computerului dar mai inteligent putin
{
    std::srand(std::time(nullptr));
    int dimensiune = miscariValide.size();
    int elemente = miscariValide[std::rand() % dimensiune];

    if (elemente == 1)
    {
        return std::make_pair(0, 0);
    } else if (elemente == 2)
    {
        return std::make_pair(0, 1);
    } else if (elemente == 3)
    {
        return std::make_pair(0, 2);
    } else if (elemente == 4)
    {
        return std::make_pair(1, 0);
    } else if (elemente == 5)
    {
        return std::make_pair(1, 1);
    } else if (elemente == 6)
    {
        return std::make_pair(1, 2);
    } else if (elemente == 7)
    {
        return std::make_pair(2, 0);
    } else if (elemente == 8)
    {
        return std::make_pair(2, 1);
    } else if (elemente == 9)
    {
        return std::make_pair(2, 2);
    }
}
