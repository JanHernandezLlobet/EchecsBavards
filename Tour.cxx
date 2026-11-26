#include "Tour.h"

Tour::Tour(bool couleur, std::string position) : Piece(couleur, position, TypePiece::TOUR){
    cout << "Tour " + position + " cree" << endl;
}

void Tour::messageMort(TypePiece typePiece){
    std::cout << "La tour en " + getPosition() + " est morte" << std::endl;
}

Tour::~Tour(){
}

std::vector<std::vector<std::pair<int, int>>> Tour::getDeplacementsPossibles(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    int droite = x;
    int gauche = 9-x;
    int haut = 9-y;
    int bas = y;
    for(int i = 0; i < 4; i++){
        deplacements.push_back(std::vector<std::pair<int, int>>());
    }
    for(int i = x; i < 8; i++){
        deplacements.at(0).push_back({i, y});
    }
    for(int i = x; i >= 0; i--){
        deplacements.at(1).push_back({i, y});
    }
    for(int i = y; i < 8; i++){
        deplacements.at(2).push_back({x, i});
    }
    for(int i = y; i >= 0; i--){
        deplacements.at(3).push_back({x, i});
    }
    return deplacements;
}