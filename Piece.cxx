#include "Piece.h"

#include <string>

Piece::Piece(bool couleur, std::string position, TypePiece type) {
    this->couleur = couleur; // true = blanc, false = noir
    this->position = position;
    this->type = type;
}

void Piece::deplacer(std::string position){
    this->position = position;
}

void Piece::deplacer(int x, int y){
    this->position = std::string(1, static_cast<char>('A' + x)) + std::to_string(y + 1);
}

bool Piece::operator==(Piece &p){
    return (this->position == p.position);
}

void Piece::messageMort(TypePiece typePiece){
    std::cout << "La piece est morte" << std::endl;
}

Piece::~Piece(){
}

TypePiece Piece::getType(){
    return this->type;
}

std::string Piece::getPosition(){
    return this->position;
}

bool Piece::getCouleur(){
    return this->couleur;
}


std::vector<std::vector<std::pair<int, int> > > Piece::getDeplacementsPossibles() {
    int x = this->position[0] - 65;
    int y = this->position[1] - 49;
    return getDeplacementsPossibles(x, y);
}
