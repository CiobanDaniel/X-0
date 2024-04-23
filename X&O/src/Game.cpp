#include "Game.h"
#include "Table.h"
#include "Player.h"
#include "Computer.h"
#include <iostream>

Game::Game() {}

Game::~Game() {}

void Game::afiseazaTabla()
{
    std::vector<std::vector<int>> matrice = tabla->getTabla();
    std::cout << "Tabla de joc:\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (matrice[i][j] == 0)
            {
                std::cout << "- ";
            }
            else if (matrice[i][j] == 1)
            {
                std::cout << simbolJucator1 << " ";
            }
            else
            {
                std::cout << simbolJucator2 << " ";
            }
        }
        std::cout << std::endl;
    }
}

void Game::afiseazaMeniuPrincipal()
{
    std::cout << "1. Incepe joc nou\n";
    std::cout << "2. Incheie aplicatia\n";
}

int Game::citesteOptiune()
{
    int optiune;
    std::cin >> optiune;
    while (optiune != 1 && optiune != 2)
    {
        std::cout << "Optiune invalida! Introduceti 1 sau 2: ";
        std::cin >> optiune;
    }
    return optiune;
}

void Game::ruleazaJoc1()
{
    bool jocIncheiat = false;
    bool mutareValida;
    std::pair<int, int> mutare;

    while (!jocIncheiat)
    {
        afiseazaTabla();

        std::cout << "Este randul jucatorului " << simbolJucator1 << std::endl;
        mutare = jucator1->introducereMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        while (!mutareValida)
        {
            std::cout << "Mutare invalida! Incercati din nou." << std::endl;
            mutare = jucator1->introducereMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 1);
        if (tabla->esteCastig(1))
        {
            std::cout << "Jucatorul " << simbolJucator1 << " a castigat!" << std::endl;
            jocIncheiat = true;
            break;
        }
        if (tabla->esteEgalitate())
        {
            std::cout << "Jocul s-a incheiat cu remiza!" << std::endl;
            jocIncheiat = true;
            break;
        }

        afiseazaTabla();

        std::cout << "Este randul jucatorului " << simbolJucator2 << std::endl;
        mutare = jucator2->generareMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        while (!mutareValida)
        {
            std::cout << "Mutare invalida! Incercati din nou." << std::endl;
            mutare = jucator2->generareMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 2);
        if (tabla->esteCastig(2))
        {
            std::cout << "Jucatorul " << simbolJucator2 << " a castigat!" << std::endl;
            jocIncheiat = true;
            break;
        }
        if (tabla->esteEgalitate())
        {
            std::cout << "Jocul s-a incheiat cu remiza!" << std::endl;
            jocIncheiat = true;
            break;
        }
    }
}

void Game::ruleazaJoc2()
{
    bool jocIncheiat = false;
    bool mutareValida;
    std::pair<int, int> mutare;

    while (!jocIncheiat)
    {
        afiseazaTabla();

        std::cout << "Este randul jucatorului " << simbolJucator2 << std::endl;
        mutare = jucator2->generareMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        while (!mutareValida)
        {
            std::cout << "Mutare invalida! Incercati din nou." << std::endl;
            mutare = jucator2->generareMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 2);
        if (tabla->esteCastig(2))
        {
            std::cout << "Jucatorul " << simbolJucator2 << " a castigat!" << std::endl;
            jocIncheiat = true;
            break;
        }
        if (tabla->esteEgalitate())
        {
            std::cout << "Jocul s-a incheiat cu remiza!" << std::endl;
            jocIncheiat = true;
            break;
        }

        afiseazaTabla();

        std::cout << "Este randul jucatorului " << simbolJucator1 << std::endl;
        mutare = jucator1->introducereMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        while (!mutareValida)
        {
            std::cout << "Mutare invalida! Incercati din nou." << std::endl;
            mutare = jucator1->introducereMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 1);
        if (tabla->esteCastig(1))
        {
            std::cout << "Jucatorul " << simbolJucator1 << " a castigat!" << std::endl;
            jocIncheiat = true;
            break;
        }
        if (tabla->esteEgalitate())
        {
            std::cout << "Jocul s-a incheiat cu remiza!" << std::endl;
            jocIncheiat = true;
            break;
        }
    }
}

void Game::incepeJocNou()
{
    std::cout << "Alege cine va incepe:\n";
    std::cout << "1. Jucatorul uman\n";
    std::cout << "2. Calculatorul\n";
    std::cout << "3. Inapoi la meniul principal\n";
    int optiune;
    std::cin >> optiune;

    switch (optiune)
        {
        case 1:
            simbolJucator1 = 'X';
            simbolJucator2 = 'O';
            ruleazaJoc1();
            break;
        case 2:
            simbolJucator1 = 'O';
            simbolJucator2 = 'X';
            ruleazaJoc2();
            break;
        case 3:
            break;
        default:
            std::cout << "Optiune invalida!\n";
        }
}

void Game::setareJocNou()
{
    tabla = new Table();
    incepeJocNou();
}

void Game::ruleaza()
{
    int optiune;
    jucator1 = new Player();
    jucator2 = new Computer();
    do
    {
        afiseazaMeniuPrincipal();
        optiune = citesteOptiune();
        switch (optiune)
        {
        case 1:
            setareJocNou();
            break;
        case 2:
            std::cout << "La revedere!\n";
            break;
        default:
            std::cout << "Optiune invalida!\n";
        }
    }
    while (optiune != 2);
}
