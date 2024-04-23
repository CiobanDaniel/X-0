#ifndef GAME_H
#define GAME_H

#include "Table.h"
#include "Player.h"
#include "Computer.h"

class Game
{
    private:
    Table* tabla;
    Player* jucator1;
    Computer* jucator2;
    char simbolJucator1;
    char simbolJucator2;

public:
    Game();
    void ruleaza();
    void afiseazaMeniuPrincipal();
    int citesteOptiune();
    void incepeJocNou();
    void setareJocNou();
    void ruleazaJoc1();
    void ruleazaJoc2();
    void afiseazaTabla();
    ~Game();
};

#endif // GAME_H
