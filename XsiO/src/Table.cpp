#include "Table.h"
#include <vector>

// Initializeaza o tabla goala. Constructorul clasei
Table::Table() : tabla(3, std::vector<int>(3, 0)), tablaGoala(3, std::vector<int>(3, 0))
{
    miscariValide = std::vector<int>(9,0);
    for (int i = 0; i < 9; i++)
    {
        miscariValide[i] = i + 1;
    }
}

Table::~Table() {} // Destructorul clasei

Table::Table (const Table& old) // Reseteaza tabla de joc. Constructorul cu argument
{
    tabla = tablaGoala;
    for (int i = 0; i < 9; i++)
    {
        miscariValide[i] = i + 1;
    }
}

std::vector<std::vector<int>> Table::getTabla() const // Returneaza tabla de joc
{
    return tabla;
}

bool Table::esteMutareValida(int linie, int coloana) // Verifica daca mutarea este valida
{
    // Verificăm dacă poziția specificată se află în limitele matricei
    if (linie < 0 || linie >= 3 || coloana < 0 || coloana >= 3)
    {
        return false; // Poziție în afara matricei
    }
    // Verificăm dacă poziția specificată este liberă
    return tabla[linie][coloana] == 0;
}

void Table::plaseazaMutare(int linie, int coloana, int jucator) // Plaseaza in tabla de joc o miscare
{
    tabla[linie][coloana] = jucator;

    int x = miscariValide.size();
    for (int i = 0; i < x; i++)
    {
        if (linie == 0 && coloana == 0 && miscariValide[i] == 1)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 0 && coloana == 1 && miscariValide[i] == 2)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 0 && coloana == 2 && miscariValide[i] == 3)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 1 && coloana == 0 && miscariValide[i] == 4)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 1 && coloana == 1 && miscariValide[i] == 5)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 1 && coloana == 2 && miscariValide[i] == 6)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 2 && coloana == 0 && miscariValide[i] == 7)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 2 && coloana == 1 && miscariValide[i] == 8)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
        else if (linie == 2 && coloana == 2 && miscariValide[i] == 9)
        {
            for (int j = i; j < x; j++)
            {
                int a = miscariValide[j+1];
                miscariValide[j] = a;
            }
            miscariValide.resize(x-1);
            break;
        }
    }
}

bool Table::esteCastig(int jucator) // Verifica daca este castig
{
    // Verificăm liniile și coloanele pentru o configurație de câștig
    for (int i = 0; i < 3; ++i)
    {
        if (tabla[i][0] == jucator && tabla[i][1] == jucator && tabla[i][2] == jucator)
        {
            return true; // Câștig pe linie
        }
        if (tabla[0][i] == jucator && tabla[1][i] == jucator && tabla[2][i] == jucator)
        {
            return true; // Câștig pe coloană
        }
    }
    // Verificăm diagonalele pentru o configurație de câștig
    if ((tabla[0][0] == jucator && tabla[1][1] == jucator && tabla[2][2] == jucator) ||
            (tabla[0][2] == jucator && tabla[1][1] == jucator && tabla[2][0] == jucator))
    {
        return true; // Câștig pe diagonală
    }
    return false; // Nu există o configurație de câștig
}

bool Table::esteEgalitate() // Verifica daca este egalitate
{
    // Verificăm dacă tabla este completă fără o configurație de câștig
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (tabla[i][j] == 0)
            {
                return false; // Există cel puțin o celulă liberă
            }
        }
    }
    return true; // Toate celulele sunt ocupate fără o configurație de câștig
}
