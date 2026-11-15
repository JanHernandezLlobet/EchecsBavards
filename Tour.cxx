#include "Tour.h"

Tour::Tour(bool couleur, std::string position) : Piece(couleur, position, "T"){
    cout << "Tour " + position + " cree" << endl;
}

void Tour::messageMort(){
    std::cout << "La tour en " + getPosition() + " est morte" << std::endl;
}

Tour::~Tour(){
    messageMort();
}
