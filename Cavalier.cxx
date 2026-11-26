#include "Cavalier.h"

Cavalier::Cavalier(bool couleur, std::string position) : Piece(couleur, position, TypePiece::CAVALIER){
    cout << "Cavalier " + position + " cree" << endl;
}

void Cavalier::messageMort(TypePiece typePiece){
    std::cout << "Le cavalier en " + getPosition() + " est mort" << std::endl;
}

Cavalier::~Cavalier(){
}

std::vector<std::vector<std::pair<int, int>>> Cavalier::getDeplacementsCavalier(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    const int lx[8] = { 1,  2,  2,  1, -1, -2, -2, -1};
    const int ly[8] = { 2,  1, -1, -2, -2, -1,  1,  2};

    for (int i = 0; i < 8; ++i) {
        if (x + lx[i] >= 0 && x + lx[i] < 8 && y + ly[i] >= 0 && y + ly[i] < 8) {
            deplacements.push_back({{x + lx[i], y + ly[i]}});
        }
    }
    return deplacements;
}

std::vector<std::vector<std::pair<int, int>>> Cavalier::getDeplacementsPossibles(int x, int y){
    return getDeplacementsCavalier(x, y);
}