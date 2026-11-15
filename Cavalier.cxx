#include "Cavalier.h"

Cavalier::Cavalier(bool couleur, std::string position) : Piece(couleur, position, "C"){
    cout << "Cavalier " + position + " cree" << endl;
}

void Cavalier::messageMort(){
    std::cout << "Le cavalier en " + getPosition() + " est mort" << std::endl;
}

Cavalier::~Cavalier(){
    messageMort();
}
