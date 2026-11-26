#include "Pion.h"

Pion::Pion(bool couleur, std::string position) : Piece(couleur, position, TypePiece::PION) {
    this->premierCoupFait = false;
    cout << "Pion " + position + " cree" << endl;
}

void Pion::messageMort(TypePiece typePiece) {
    std::cout << "Le pion en " + getPosition() + " est mort" << std::endl;
}

Pion::~Pion() {
}

bool Pion::getCouleur() {
    return this->couleur;
}

std::vector<std::vector<std::pair<int, int> > > Pion::getDeplacementsPossibles(int x, int y) {
    std::vector<std::vector<std::pair<int, int> > > deplacements;
    for (int i = 0; i < 2; i++) {
        deplacements.push_back(std::vector<std::pair<int, int> >());
    }
    if (this->getCouleur()) {
        if (y + 1 >= 0 && y + 1 < 8) deplacements.at(0).push_back({x, y + 1});
        if (y + 2 >= 0 && y + 2 < 8) deplacements.at(0).push_back({x, y + 2});
        if (x + 1 >= 0 && x + 1 < 8 && y + 1 >= 0 && y + 1 < 8) deplacements.at(1).push_back({x + 1, y + 1});
        if (x - 1 >= 0 && x - 1 < 8 && y + 1 >= 0 && y + 1 < 8) deplacements.at(1).push_back({x - 1, y + 1});
    } else {
        if (y - 1 >= 0 && y - 1 < 8) deplacements.at(0).push_back({x, y - 1});
        if (y - 2 >= 0 && y - 2 < 8) deplacements.at(0).push_back({x, y - 2});
        if (x + 1 >= 0 && x + 1 < 8 && y - 1 >= 0 && y - 1 < 8) deplacements.at(1).push_back({x + 1, y - 1});
        if (x - 1 >= 0 && x - 1 < 8 && y - 1 >= 0 && y - 1 < 8) deplacements.at(1).push_back({x - 1, y - 1});
    }
    return deplacements;
}
