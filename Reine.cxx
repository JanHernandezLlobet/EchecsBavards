#include "Reine.h"

Reine::Reine(bool couleur, std::string position) : Piece(couleur, position, "D"){
    cout << "Reine " + position + " cree" << endl;
}

void Reine::messageMort(){
    std::cout << "La reine en " + getPosition() + " est morte" << std::endl;
}

Reine::~Reine(){
    messageMort();
}
