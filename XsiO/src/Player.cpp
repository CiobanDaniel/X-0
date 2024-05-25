#include "Player.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

void Player::centru(std::string text) // Centreaza textul in consola
{
    // Va centra textul doar daca lungimea textului e mai mica decat lungimea consolei
    // Altfel va afisa textul asa cum e
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
    PCONSOLE_SCREEN_BUFFER_INFO informatiiEcran = new CONSOLE_SCREEN_BUFFER_INFO(); // Creaza un pointer catre informatia ecranului consolei
                                                                                // care arata catre informatia termporara a ecranului.
    GetConsoleScreenBufferInfo(hConsole, informatiiEcran); // Salveaza informatia ecranului consolei in pointerul lpScreenInfo.
    COORD dimensiuneNoua = informatiiEcran->dwSize; // Afla lungimea consolei
    if (dimensiuneNoua.X > text.size())
    {
        int positieNoua = ((dimensiuneNoua.X - text.size()) / 2); // Calculeaza numarul de spatii pentru a centra textul respectiv.
        for (int i = 0; i < positieNoua; i++) std::cout << " "; // Afiseaza spatiile
    }
    std::cout << text << std::endl; // Prints the text centered :]
}

std::pair<int, int> Player::introducereMutare() // Permite jucatorului uman sa introduca o mutare
{
    int rand, coloana;
    centru("Introdu randul: ");
    do
    {
        rand = getch();
        if (rand == 'A' || rand == 'a')
        {
            return {4, 4};
        }
        if (rand == 'S' || rand == 's')
        {
            return {3, 3};
        }
    }
    while(rand != '1' && rand != '2' && rand != '3');
    centru("Introdu coloana: ");
    do
    {
        coloana = getch();
        if (coloana == 'A' || coloana == 'a')
        {
            return {4, 4};
        }
        if (coloana == 'S' || coloana == 's')
        {
            return {3, 3};
        }
    }
    while(coloana != '1' && coloana != '2' && coloana != '3');
    return {rand-'0'-1, coloana-'0'-1};
}
