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
    const int lx[8] = { 1,  1,  0, -1, -1, -1,  0,  1};
    const int ly[8] = { 0,  1,  1,  1,  0, -1, -1, -1};

    for (int i = 0; i < 8; ++i) {
        if (x + lx[i] >= 0 && x + lx[i] < 8 && y + ly[i] >= 0 && y + ly[i] < 8) {
            deplacements.push_back({{x + lx[i], y + ly[i]}});
        }
    }
    return deplacements;
}