#include "Tour.h"

Tour::Tour(bool couleur, std::string position) : Piece(couleur, position, TypePiece::TOUR){
    cout << "Tour " + position + " cree" << endl;
}

void Tour::messageMort(TypePiece typePiece){
    if(typePiece == TypePiece::PION){
        std::cout << "Pion: Jsuis un sappeur!" << std::endl;
        std::cout << "Tour: kkrkr ?! kk... k..." << std::endl;
    } else if(typePiece == TypePiece::CAVALIER){
        std::cout << "Cavalier: Not a tower will scare me!" << std::endl;
        std::cout << "Tour: k..." << std::endl;
    } else if(typePiece == TypePiece::FOU){
        std::cout << "Fou: je te renvoie d'où tu viens démon!" << std::endl;
        std::cout << "Tour: KRKRKRRKRKKKKK!!!" << std::endl;
    } else if(typePiece == TypePiece::TOUR){
        std::cout << "Tour: krkrkkkkk! kkkkkrkkkrrk." << std::endl;
        std::cout << "Tour: kkkrkk, krkrkkkk..." << std::endl;
    } else if(typePiece == TypePiece::REINE){
        std::cout << "Reine: On va aller chercher les trois couronnes maintenant." << std::endl;
        std::cout << "Tour: kkk..." << std::endl;
    } else if(typePiece == TypePiece::ROI){
        std::cout << "Roi: Hm non je n'aime pas ce bâtiment içi, détruisez-le." << std::endl;
        std::cout << "Tour: kk ?? rkrkrkkkk." << std::endl;
    }
    std::cout << "La tour en " + getPosition() + " est morte" << std::endl;
}

Tour::~Tour(){
}

std::vector<std::vector<std::pair<int, int>>> Tour::getDeplacementsPossibles(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    int droite = x;
    int gauche = 7-x;
    int haut = 7-y;
    int bas = y;
    for(int i = 0; i < 4; i++){
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
    return deplacements;
}