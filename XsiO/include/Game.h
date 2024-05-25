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
    void afiseazaMeniuPrincipal2();
    void incepeJocNou();
    void setareJocNou();
    void ruleazaJoc1();
    void ruleazaJoc2();
    void afiseazaTabla();
    void artaAscii();
    void setari();
    void setariCuloare();
    void info();
    void castig();
    void pierdere();
    void egalitate();
    void centrare(std::string text);
    ~Game();
};

#endif // GAME_H
