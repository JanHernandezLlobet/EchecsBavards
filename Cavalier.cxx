#include "Cavalier.h"

Cavalier::Cavalier(bool couleur, std::string position) : Piece(couleur, position, TypePiece::CAVALIER){
    cout << "Cavalier " + position + " cree" << endl;
}

void Cavalier::messageMort(TypePiece typePiece){
    if(typePiece == TypePiece::PION) {
        std::cout << "Pion: Même sur un cheval tu n'es pas de taille!" << std::endl;
        std::cout << "Cavalier: oh noo…" << std::endl;
    } else if (typePiece == TypePiece::CAVALIER) {
        std::cout << "Cavalier: betrayed by my owns..." << std::endl;
        std::cout << "Cavalier: as the french would say, \"cheh\"" << std::endl;
    } else if (typePiece == TypePiece::FOU) {
        std::cout << "Fou: C'est ta fin, barbare." << std::endl;
        std::cout << "Cavalier: I don't even huderstand you dude." << std::endl;
    } else if (typePiece == TypePiece::TOUR) {
        std::cout << "Tour: kkkkrrrkkk! kkrkrkrkkkkk!" << std::endl;
        std::cout << "Cavalier: Oh sh*t what the f*ck!" << std::endl;
    } else if (typePiece == TypePiece::REINE) {
        std::cout << "Reine: God save the queen!" << std::endl;
        std::cout << "Cavalier: No way! Mao!" << std::endl;
    } else if (typePiece == TypePiece::ROI) {
        std::cout << "Cavalier: The fat king got me!" << std::endl;
        std::cout << "Roi: Que m'as tu appellé ?!" << std::endl;
    }
    std::cout << "Le cavalier en " + getPosition() + " est mort" << std::endl;
}

Cavalier::~Cavalier(){
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