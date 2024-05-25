#ifndef TABLE_H
#define TABLE_H

#include <vector>

class Table
{
private:
    std::vector<std::vector<int>> tablaGoala;
    std::vector<std::vector<int>> tabla;

public:
    std::vector<int> miscariValide;
    Table(); // Initializeaza o tabla goala. Constructorul clasei
    Table (const Table& old); // Reseteaza tabla de joc. Constructorul cu argument
    std::vector<std::vector<int>> getTabla() const; // Returneaza tabla de joc
    bool esteMutareValida(int linie, int coloana); // Verifica daca mutarea este valida
    void plaseazaMutare(int linie, int coloana, int jucator); // Plaseaza in tabla de joc o miscare
    bool esteCastig(int jucator); // Verifica daca este castig
    bool esteEgalitate(); // Verifica daca este egalitate
    ~Table(); // Destructorul clasei
};

#endif // TABLE_H
