#include "Game.h"
#include "Table.h"
#include "Player.h"
#include "Computer.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <unistd.h>

Game::Game() {}

Game::~Game()
{
    delete jucator1;
    delete jucator2;
    delete tabla;
}

void Game::centrare(std::string text)
{
    // Va centra textul doar daca lungimea textului e mai mica decat lungimea consolei
    // Altfel va afisa textul asa cum e
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Creaza un pointer catre informatia ecranului consolei
    // care arata catre informatia termporara a ecranului.
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo); // Salveaza informatia ecranului consolei in pointerul lpScreenInfo.
    COORD NewSBSize = lpScreenInfo->dwSize; // Afla lungimea consolei
    if (NewSBSize.X > text.size())
    {
        int newpos = ((NewSBSize.X - text.size()) / 2); // Calculeaza numarul de spatii pentru a centra textul respectiv.
        for (int i = 0; i < newpos; i++) std::cout << " "; // Afiseaza spatiile
    }
    std::cout << text << std::endl; // Prints the text centered :]
}

void Game::castig()
{
    int optiune;
    do
    {
        system("cls");
        afiseazaTabla();
        centrare("Felicitari! Ai castigat! ^w^\n");
        centrare("Ce doresti sa faci acum?");
        afiseazaMeniuPrincipal2();
        optiune = getch();
        switch (optiune)
        {
        case '1':
            ruleaza();
            break;
        case '2':
            setareJocNou();
            break;
        case '3':
            setari();
            break;
        case '4':
            system("cls");
            std::cout << "\n\n";
            centrare("La revedere!");
            exit(0);
            break;
        default:
            break;
        }
    }
    while (optiune != '4');
}
void Game::pierdere()
{
    int optiune;
    do
    {
        system("cls");
        afiseazaTabla();
        centrare("Off... Ai pierdut... -_-\n");
        centrare("Ce doresti sa faci acum?");
        afiseazaMeniuPrincipal2();
        optiune = getch();
        switch (optiune)
        {
        case '1':
            ruleaza();
            break;
        case '2':
            setareJocNou();
            break;
        case '3':
            setari();
            break;
        case '4':
            system("cls");
            std::cout << "\n\n";
            centrare("La revedere!");
            exit(0);
            break;
        default:
            break;
        }
    }
    while (optiune != '4');
}
void Game::egalitate()
{
    int optiune;
    do
    {
        system("cls");
        afiseazaTabla();
        centrare("Egalitate! Atat de aproape! 0o0\n");
        centrare("Ce doresti sa faci acum?");
        afiseazaMeniuPrincipal2();
        optiune = getch();
        switch (optiune)
        {
        case '1':
            ruleaza();
            break;
        case '2':
            setareJocNou();
            break;
        case '3':
            setari();
            break;
        case '4':
            system("cls");
            std::cout << "\n\n";
            centrare("La revedere!");
            exit(0);
            break;
        default:
            break;
        }
    }
    while (optiune != '4');
}

void Game::afiseazaTabla()
{
    std::vector<std::vector<int>> matrice = tabla->getTabla();
    std::string mesaj1 = "Semnul tau este: ";
    mesaj1 += simbolJucator1;
    std::string mesaj2 = "Semnul inamicului este: ";
    mesaj2 += simbolJucator2;
    centrare(mesaj1);
    centrare(mesaj2);
    centrare("Tabla de joc:");
    std::string linie = "";
    char poz[3];

    centrare("    1     2     3  ");
    centrare(" ___________________");
    for (int i = 0; i < 3; i++)
    {
        linie = "";
        for (int k = 0; k < 3; k++)
        {
            if (matrice[i][k] == 0)
                poz[k] = '-';
            if (matrice[i][k] == 1)
                poz[k] = simbolJucator1;
            if (matrice[i][k] == 2)
                poz[k] = simbolJucator2;
        }
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
            {
                centrare("  |     |     |     |");
            }
            else if (j == 1)
            {
                linie += std::to_string(i + 1);
                linie += " |  ";
                linie += poz[0];
                linie += "  |  ";
                linie += poz[1];
                linie += "  |  ";
                linie += poz[2];
                linie += "  |";
                centrare(linie);
            }
            else if (j == 2)
            {
                centrare("  |_____|_____|_____|");
            }
        }
    }
}

void Game::afiseazaMeniuPrincipal()
{
    centrare("1. Incepe un joc nou");
    centrare("2. Setari");
    centrare("3. Paraseste aplicatia");
}

void Game::afiseazaMeniuPrincipal2()
{
    centrare("1. Meniul principal");
    centrare("2. Incepe un joc nou");
    centrare("3. Setari");
    centrare("4. Paraseste aplicatia");
}

void Game::ruleazaJoc1()
{
    bool jocIncheiat = false;
    bool mutareValida;
    std::pair<int, int> mutare;

    while (!jocIncheiat)
    {
        system("cls");
        afiseazaTabla();

        centrare("Este randul tau!");
        mutare = jucator1->introducereMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        while (!mutareValida)
        {
            system("cls");
            afiseazaTabla();
            centrare("Mutare invalida! Incearca din nou.");
            mutare = jucator1->introducereMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 1);
        if (tabla->esteCastig(1))
        {
            jocIncheiat = true;
            castig();
            break;
        }
        if (tabla->esteEgalitate())
        {
            jocIncheiat = true;
            egalitate();
            break;
        }
        system("cls");
        afiseazaTabla();

        centrare("Este randul inamicului! Asteapta!");
        mutare = jucator2->generareMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        sleep(1);
        while (!mutareValida)
        {
            mutare = jucator2->generareMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 2);

        if (tabla->esteCastig(2))
        {
            jocIncheiat = true;
            pierdere();
            break;
        }
        if (tabla->esteEgalitate())
        {
            jocIncheiat = true;
            egalitate();
            break;
        }
    }
    system("cls");
}

void Game::ruleazaJoc2()
{
    bool jocIncheiat = false;
    bool mutareValida;
    std::pair<int, int> mutare;

    while (!jocIncheiat)
    {
        system("cls");
        afiseazaTabla();

        centrare("Este randul inamicului! Asteapta!");
        mutare = jucator2->generareMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        sleep(1);
        while (!mutareValida)
        {
            mutare = jucator2->generareMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 2);
        if (tabla->esteCastig(2))
        {
            jocIncheiat = true;
            pierdere();
            break;
        }
        if (tabla->esteEgalitate())
        {
            jocIncheiat = true;
            egalitate();
            break;
        }
        system("cls");
        afiseazaTabla();

        centrare("Este randul tau!");
        mutare = jucator1->introducereMutare();
        mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        while (!mutareValida)
        {
            system("cls");
            afiseazaTabla();
            centrare("Mutare invalida! Incercati din nou.");
            mutare = jucator1->introducereMutare();
            mutareValida = tabla->esteMutareValida(mutare.first, mutare.second);
        }
        tabla->plaseazaMutare(mutare.first, mutare.second, 1);
        if (tabla->esteCastig(1))
        {
            jocIncheiat = true;
            castig();
            break;
        }
        if (tabla->esteEgalitate())
        {
            jocIncheiat = true;
            egalitate();
            break;
        }
    }
    system("cls");
}

void Game::incepeJocNou()
{
    system("cls");
    centrare("db   db db    db .88b  d88.  .d8b.  d8b   db      db    db .d8888. ");
    centrare("88   88 88    88 88'YbdP`88 d8' `8b 888o  88      88    88 88'  YP ");
    centrare("88ooo88 88    88 88  88  88 88ooo88 88V8o 88      Y8    8P `8bo.   ");
    centrare("88~~~88 88    88 88  88  88 88~~~88 88 V8o88      `8b  d8'   `Y8b. ");
    centrare("88   88 88b  d88 88  88  88 88   88 88  V888       `8bd8'  db   8D ");
    centrare("YP   YP ~Y8888P' YP  YP  YP YP   YP VP   V8P         YP    `8888Y' ");
    centrare("                                                                   ");
    centrare(" .o88b.  .d88b.  .88b  d88. d8888b. db    db d888888b d88888b d8888b. ");
    centrare("d8P  Y8 .8P  Y8. 88'YbdP`88 88  `8D 88    88 `~~88~~' 88'     88  `8D ");
    centrare("8P      88    88 88  88  88 88oodD' 88    88    88    88ooooo 88oobY' ");
    centrare("8b      88    88 88  88  88 88~~~   88    88    88    88~~~~~ 88`8b   ");
    centrare("Y8b  d8 `8b  d8' 88  88  88 88      88b  d88    88    88.     88 `88. ");
    centrare(" `Y88P'  `Y88P'  YP  YP  YP 88      ~Y8888P'    YP    Y88888P 88   YD ");
    std::cout << "\n\n";
    centrare("Alege cine va incepe:");
    centrare("1. Jucatorul uman");
    centrare("2. Calculatorul");
    centrare("3. Return");
    int optiune;
    optiune = getch();
    switch (optiune)
    {
    case '1':
        simbolJucator1 = 'X';
        simbolJucator2 = 'O';
        ruleazaJoc1();
        break;
    case '2':
        simbolJucator1 = 'O';
        simbolJucator2 = 'X';
        ruleazaJoc2();
        break;
    case '3':
        return;
        break;
    default:
        break;
    }
}

void Game::setareJocNou()
{
    tabla = new Table();
    incepeJocNou();
}

void Game::artaAscii()
{
    centrare("ooooooo  ooooo        .oo.            .oooooo.   ");
    centrare(" `8888    d8'       .88' `8.         d8P'  `Y8b  ");
    centrare("   Y888..8P         88.  .8'        888      888 ");
    centrare("    `8888'          `88.8P          888      888 ");
    centrare("   .8PY888.          d888[.8'       888      888 ");
    centrare("  d8'  `888b        88' `88.        `88b    d88' ");
    centrare("o888o  o88888o      `bodP'`88.       `Y8bood8P'  ");
    std::cout << "\n\n";
}

void Game::setariCuloare()
{
    int c;
    do
    {
        system("cls");
        centrare("Alege tematica aplicatiei:");
        centrare("1. Default");
        centrare("2. Albastru");
        centrare("3. Rosu");
        centrare("4. Verde");
        centrare("5. Return");
        c = getch();
        switch (c)
        {
        case '1':
            system("Color 07");
            break;
        case '2':
            system("Color 71");
            break;
        case '3':
            system("Color 74");
            break;
        case '4':
            system("Color 72");
            break;
        case '5':
            return;
            break;
        default:
            break;
        }
    }
    while(c != 5);
}

void Game::info()
{
    system("cls");
    std::cout << "\n";
    centrare("Titlu proiect: X&O impotriva calculatorului");
    centrare("Disciplina: Programare orientata pe obiecte (PROIECT)");
    centrare("Student: Cioban Daniel");
    centrare("Grupa: 3121A");
    centrare("Facultatea: FIESC");
    centrare("Specializarea: Calculatoare");
    centrare("An universitar: 2023-2024\n");
    centrare("--Apasa orice pentru a reveni--");
    getch();

}

void Game::setari()
{
    int o;
    do
    {
        system("cls");
        std::cout << "\n\n";
        centrare("--SETARI--");
        centrare("1. Tematica");
        centrare("2. Info");
        centrare("3. Return");
        o = getch();
        switch (o)
        {
        case '1':
            setariCuloare();
            break;
        case '2':
            info();
            break;
        case '3':
            return;
            break;
        default:
            break;
        }
    }
    while(o != 3);
}

void Game::ruleaza()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);

    int optiune;
    jucator1 = new Player();
    jucator2 = new Computer();
    do
    {
        system("cls");
        artaAscii();
        afiseazaMeniuPrincipal();
        optiune = getch();
        switch (optiune)
        {
        case '1':
            setareJocNou();
            break;
        case '2':
            setari();
            break;
        case '3':
            system("cls");
            std::cout << "\n\n";
            centrare("La revedere!");
            exit(0);
            break;
        default:
            break;
        }
    }
    while (optiune != '3');
}
