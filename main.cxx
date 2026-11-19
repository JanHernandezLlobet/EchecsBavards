#include "Echiquier.h"
#include "Piece.h"
#include <iostream>

int main() {
    Echiquier echiquier(8, 8, true);
    echiquier.afficher();
    
    Piece* piece1 = new Piece(true, "A1", "X");
    piece1->deplacer("B2");
    echiquier.ajouterPiece(piece1, "E5");
    echiquier.afficher();

    std::cout << piece1->getPosition() << std::endl;
    
    
    return 0;
}