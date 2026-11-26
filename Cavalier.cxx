#include "Cavalier.h"

Cavalier::Cavalier(bool couleur, std::string position) : Piece(couleur, position, TypePiece::CAVALIER){
    cout << "Cavalier " + position + " cree" << endl;
}

void Cavalier::messageMort(){
    std::cout << "Le cavalier en " + getPosition() + " est mort" << std::endl;
}

Cavalier::~Cavalier(){
    messageMort();
}

std::vector<std::vector<std::pair<int, int>>> Cavalier::getDeplacementsCavalier(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    deplacements.push_back({{x+1, y+2}});
    deplacements.push_back({{x+1, y-2}});
    deplacements.push_back({{x-1, y+2}});
    deplacements.push_back({{x-1, y-2}});
    deplacements.push_back({{x+2, y+1}});
    deplacements.push_back({{x+2, y-1}});
    deplacements.push_back({{x-2, y+1}});
    deplacements.push_back({{x-2, y-1}});
    return deplacements;
}

std::vector<std::vector<std::pair<int, int>>> Cavalier::getDeplacementsPossibles(int x, int y){
    return getDeplacementsCavalier(x, y);
}