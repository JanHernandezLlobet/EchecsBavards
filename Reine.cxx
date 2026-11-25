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

std::vector<std::vector<std::pair<int, int>>> Reine::getDeplacementsPossibles(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    int droite = x;
    int gauche = 9-x;
    int haut = 9-y;
    int bas = y;
    for(int i = 0; i < 8; i++){
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
    for(int i = 0; i < std::min(droite, haut); i++){
        deplacements.at(4).push_back({x+i, y+i});
    }
    for(int i = 0; i < std::min(gauche, haut); i++){
        deplacements.at(5).push_back({x-i, y+i});
    }
    for(int i = 0; i < std::min(droite, bas); i++){
        deplacements.at(6).push_back({x+i, y-i});
    }
    for(int i = 0; i < std::min(gauche, bas); i++){
        deplacements.at(7).push_back({x-i, y-i});
    }
    return deplacements;
}