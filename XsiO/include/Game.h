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
    Game(); // Constructorul clasei
    void ruleaza(); // Meniul principal al jocului
    void afiseazaMeniuPrincipal(); // Afiseaza meniul principal
    void afiseazaMeniuPrincipal2(); // Afiseaza meniul la terminarea unui joc
    void incepeJocNou(); // Afiseaza meniul pentru a alege care jucator incepe primul
    void setareJocNou(); // Creaza o noua instanta a tablei si apeleaza incepeJocNou()
    void ruleazaJoc1(); // Ruleaza jocul cand jucatorul uman este primul
    void ruleazaJoc2(); // Ruleaza jocul cand computerul este primul jucator
    void afiseazaTabla(); // Afiseaza tabla din timpul jocului cu cateva detalii in plus
    void artaAscii(); // Afiseaza arta ascii din meniul principal
    void setari(); // Afiseaza meniul pentru setari si permite introducerea optiunii
    void setariCuloare(); // Permite alegerea temei jocului dintre cele enumerate
    void info(); // Afiseaza informatii despre proiect
    void castig(); // Ce se afiseaza in caz ca jucatorul uman a castigat
    void pierdere(); // Ce se afiseaza in caz ca jucatorul uman a pierdut
    void egalitate(); // Ce se afiseaza in caz de egalitate
    void centrare(std::string text); // Centreaza textul in consola
    void help(); // Afiseaza informatii despre cum se joaca jocul si cum se utilizeaza aplicatia
    ~Game(); // Destructorul clasei
};

#endif // GAME_H
