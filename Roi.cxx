#include "Roi.h"

Roi::Roi(bool couleur, std::string position) : Piece(couleur, position, TypePiece::ROI){
    cout << "Roi " + position + " cree" << endl;
}

void Roi::messageMort(TypePiece typePiece){
    if(typePiece == TypePiece::PION){
        std::cout << "Roi: Que se passe-t-il içi ?" << std::endl;
        std::cout << "Pion: Vive la révolution! Coupons lui la tête!" << std::endl;
    } else if(typePiece == TypePiece::CAVALIER){
        std::cout << "Roi: Un chevalier ? C'est un peu trop pour moi." << std::endl;
        std::cout << "Cavalier: im just farming aura." << std::endl;
    } else if(typePiece == TypePiece::FOU){
        std::cout << "Roi: Comment oses-tu ?" << std::endl;
        std::cout << "Fou: Le seigneur l'exige." << std::endl;
    } else if(typePiece == TypePiece::TOUR){
        std::cout << "Roi: Qui est-tu ?" << std::endl;
        std::cout << "Tour: Krkrkkkk!!" << std::endl;
    } else if(typePiece == TypePiece::REINE){
        std::cout << "Roi: Bonjour gente femme." << std::endl;
        std::cout << "Reine: Tu ne m'auras pas avec tes mots, c'est la fin!" << std::endl;
    } else if(typePiece == TypePiece::ROI){
        std::cout << "Roi: Euh on fait quoi du coup ? chifoumi ?" << std::endl;
        std::cout << "Roi: Allons boire un coup et oublions tout ça." << std::endl;
    }
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