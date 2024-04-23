#include "Computer.h"
#include <cstdlib>
#include <ctime>
#include "Table.h"
Computer::Computer(){}

std::pair<int, int> Computer::generareMutare() {
    std::srand(std::time(nullptr));
    int linie = std::rand() % 3;
    int coloana = std::rand() % 3;
    Table* tabla;
    while (!tabla->esteMutareValida(linie, coloana)) {
        linie = std::rand() % 3;
        coloana = std::rand() % 3;
    }

    return std::make_pair(linie, coloana);
}
