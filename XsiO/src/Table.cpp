#include "Table.h"
#include <vector>

Table::Table() : tabla(3, std::vector<int>(3, 0)), tablaGoala(3, std::vector<int>(3, 0)) {}

Table::~Table() {}

Table::Table (const Table& old)
  {
   tabla = tablaGoala;
  }

std::vector<std::vector<int>> Table::getTabla() const
{
    return tabla;
}

bool Table::esteMutareValida(int linie, int coloana) {
    // Verificăm dacă poziția specificată se află în limitele matricei
    if (linie < 0 || linie >= 3 || coloana < 0 || coloana >= 3) {
        return false; // Poziție în afara matricei
    }
    // Verificăm dacă poziția specificată este liberă
    return tabla[linie][coloana] == 0;
}

void Table::plaseazaMutare(int linie, int coloana, int jucator)
{
    tabla[linie][coloana] = jucator;
}

bool Table::esteCastig(int jucator) {
    // Verificăm liniile și coloanele pentru o configurație de câștig
    for (int i = 0; i < 3; ++i) {
        if (tabla[i][0] == jucator && tabla[i][1] == jucator && tabla[i][2] == jucator) {
            return true; // Câștig pe linie
        }
        if (tabla[0][i] == jucator && tabla[1][i] == jucator && tabla[2][i] == jucator) {
            return true; // Câștig pe coloană
        }
    }
    // Verificăm diagonalele pentru o configurație de câștig
    if ((tabla[0][0] == jucator && tabla[1][1] == jucator && tabla[2][2] == jucator) ||
        (tabla[0][2] == jucator && tabla[1][1] == jucator && tabla[2][0] == jucator)) {
        return true; // Câștig pe diagonală
    }
    return false; // Nu există o configurație de câștig
}

bool Table::esteEgalitate() {
    // Verificăm dacă tabla este completă fără o configurație de câștig
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tabla[i][j] == 0) {
                return false; // Există cel puțin o celulă liberă
            }
        }
    }
    return true; // Toate celulele sunt ocupate fără o configurație de câștig
}
