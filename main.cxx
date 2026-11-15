#include "Echiquier.h"
#include "Piece.h"
#include <iostream>

int main() {
    Echiquier echiquier(8, 8, true);
    echiquier.afficher();
    
    Piece piece1(true, "A1");
    piece1.deplacer("B2");
    std::cout << piece1.getPosition() << std::endl;
    
    
    return 0;
}