#include "Fou.h"

Fou::Fou(bool couleur, std::string position) : Piece(couleur, position, "F"){
    cout << "Fou " + position + " cree" << endl;
}

void Fou::messageMort(){
    std::cout << "Le fou en " + getPosition() + " est mort" << std::endl;
}

Fou::~Fou(){
    messageMort();
}
