#include "Roi.h"

Roi::Roi(bool couleur, std::string position) : Piece(couleur, position, TypePiece::ROI){
    cout << "Roi " + position + " cree" << endl;
}

void Roi::messageMort(TypePiece typePiece){
    std::cout << "Le roi en " + getPosition() + " est mort" << std::endl;
}

Roi::~Roi(){
}

std::vector<std::vector<std::pair<int, int>>> Roi::getDeplacementsPossibles(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    deplacements.push_back({{x+1, y+1}});
    deplacements.push_back({{x+1, y-1}});
    deplacements.push_back({{x-1, y+1}});
    deplacements.push_back({{x-1, y-1}});
    deplacements.push_back({{x+1, y}});
    deplacements.push_back({{x-1, y}});
    deplacements.push_back({{x, y+1}});
    deplacements.push_back({{x, y-1}});
    return deplacements;
}