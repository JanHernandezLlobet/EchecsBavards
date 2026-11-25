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

std::vector<std::vector<std::pair<int, int>>> Fou::getDeplacementsPossibles(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    int droite = x;
    int gauche = 9-x;
    int haut = 9-y;
    int bas = y;
    for(int i = 0; i < 4; i++){
        deplacements.push_back(std::vector<std::pair<int, int>>());
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