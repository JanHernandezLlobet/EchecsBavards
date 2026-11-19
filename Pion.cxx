#include "Pion.h"

Pion::Pion(bool couleur, std::string position) : Piece(couleur, position, "P"){
    this->premierCoupFait = false;
    cout << "Pion " + position + " cree" << endl;
}

void Pion::messageMort(){
    std::cout << "Le pion en " + getPosition() + " est mort" << std::endl;
}

Pion::~Pion(){
    messageMort();
}
