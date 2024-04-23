#ifndef TABLE_H
#define TABLE_H

#include <vector>

class Table
{
private:
    std::vector<std::vector<int>> tablaGoala;
    std::vector<std::vector<int>> tabla;
    std::vector<std::vector<int>> miscariValide;


public:
    Table();
    Table (const Table& old);
    std::vector<std::vector<int>> getTabla() const;
    bool esteMutareValida(int linie, int coloana);
    void plaseazaMutare(int linie, int coloana, int jucator);
    bool esteCastig(int jucator);
    bool esteEgalitate();
    void generareInitializareValide();
    void generareTablaGoala();
    ~Table();
};

#endif // TABLE_H
