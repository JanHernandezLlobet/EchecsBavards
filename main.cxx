#ifdef _WIN32
#include <windows.h>
#endif
#include "Echiquier.h"
#include "Piece.h"
#include <iostream>


int main() {
#ifdef _WIN32
    // Active le support des codes couleurs ANSI sous Windows
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
#endif



    Echiquier echiquier(8, 8, true);

    std::vector<std::tuple<std::string, TypePiece, bool>> posInitiale = {
        {"A1", TypePiece::TOUR,     true},
        {"B1", TypePiece::CAVALIER, true},
        {"C1", TypePiece::FOU,      true},
        {"D1", TypePiece::REINE,    true},
        {"E1", TypePiece::ROI,      true},
        {"F1", TypePiece::FOU,      true},
        {"G1", TypePiece::CAVALIER, true},
        {"H1", TypePiece::TOUR,     true},
        {"A2", TypePiece::PION,     true},
        {"B2", TypePiece::PION,     true},
        {"C2", TypePiece::PION,     true},
        {"D2", TypePiece::PION,     true},
        {"E2", TypePiece::PION,     true},
        {"F2", TypePiece::PION,     true},
        {"G2", TypePiece::PION,     true},
        {"H2", TypePiece::PION,     true},
        {"A7", TypePiece::PION,     false},
        {"B7", TypePiece::PION,     false},
        {"C7", TypePiece::PION,     false},
        {"D7", TypePiece::PION,     false},
        {"E7", TypePiece::PION,     false},
        {"F7", TypePiece::PION,     false},
        {"G7", TypePiece::PION,     false},
        {"H7", TypePiece::PION,     false},
        {"A8", TypePiece::TOUR,     false},
        {"B8", TypePiece::CAVALIER, false},
        {"C8", TypePiece::FOU,      false},
        {"D8", TypePiece::REINE,    false},
        {"E8", TypePiece::ROI,      false},
        {"F8", TypePiece::FOU,      false},
        {"G8", TypePiece::CAVALIER, false},
        {"H8", TypePiece::TOUR,     false}
    };
    std::cout << "Roi blanc : \u2654 | Dame blanche : \u2655\n";
    echiquier.generer(posInitiale);
    echiquier.afficher_alternatif_petit();
    echiquier.afficher_alternatif_grand();
    echiquier.boucle();

    return 0;
}