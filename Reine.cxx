#include "Reine.h"

Reine::Reine(bool couleur, std::string position) : Piece(couleur, position, TypePiece::REINE){
    cout << "Reine " + position + " cree" << endl;
}

void Reine::messageMort(TypePiece typePiece){
    if(typePiece == TypePiece::PION){
        std::cout << "Reine: Tué par un simple pion... Quelle honte!" << std::endl;
        std::cout << "Pion: morts aux bourges!" << std::endl;
    } else if(typePiece == TypePiece::CAVALIER){
        std::cout << "Cavalier: Oho! Huge jump and i kill you." << std::endl;
        std::cout << "Reine: Quels sont ces mouvements ?!" << std::endl;
    } else if(typePiece == TypePiece::FOU){
        std::cout << "Reine: Comment oses tu ??" << std::endl;
        std::cout << "Fou: Le seigneur l'exige." << std::endl;
    } else if(typePiece == TypePiece::TOUR){
        std::cout << "Reine: Je me fais enfermer dans une tour, nooon..." << std::endl;
        std::cout << "Tour: kkkrkkrk!! Miam! krrkkrk." << std::endl;
    } else if(typePiece == TypePiece::REINE){
        std::cout << "Reine: Tué par une adversaire avec si peu de style..." << std::endl;
        std::cout << "Reine: Je ne suis pas une simple pionne!" << std::endl;
    } else if(typePiece == TypePiece::ROI){
        std::cout << "Reine: Je me suis offerte, quelle sotte!" << std::endl;
        std::cout << "Tu est désormais à moi!" << std::endl;
    }
    std::cout << "La reine en " + getPosition() + " est morte" << std::endl;
}

Reine::~Reine(){
}

std::vector<std::vector<std::pair<int, int>>> Reine::getDeplacementsPossibles(int x, int y){
    return getDeplacementsReine(x, y);
}


std::vector<std::vector<std::pair<int, int>>> Reine::getDeplacementsReine(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    int droite = 7-x;
    int gauche = x;
    int haut = 7-y;
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
    for(int i = 1; i <= std::min(droite, haut); i++){
        deplacements.at(4).push_back({x+i, y+i});
    }
    for(int i = 1; i <= std::min(gauche, haut); i++){
        deplacements.at(5).push_back({x-i, y+i});
    }
    for(int i = 1; i <= std::min(droite, bas); i++){
        deplacements.at(6).push_back({x+i, y-i});
    }
    for(int i = 1; i <= std::min(gauche, bas); i++){
        deplacements.at(7).push_back({x-i, y-i});
    }
    return deplacements;
}