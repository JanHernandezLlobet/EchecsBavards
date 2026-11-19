#include "Roi.h"

Roi::Roi(bool couleur, std::string position) : Piece(couleur, position, "R"){
    cout << "Roi " + position + " cree" << endl;
}

void Roi::messageMort(){
    std::cout << "Le roi en " + getPosition() + " est mort" << std::endl;
}

Roi::~Roi(){
    messageMort();
}
