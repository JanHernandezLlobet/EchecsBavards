#include "Fou.h"

Fou::Fou(bool couleur, std::string position) : Piece(couleur, position, TypePiece::FOU){
    cout << "Fou " + position + " cree" << endl;
}

void Fou::messageMort(TypePiece typePiece){
    if(typePiece == TypePiece::PION){
        std::cout << "Pion: J'ai eu un fou ? J'AI EU UN FOU!!" << std::endl;
        std::cout << "Fou: Tel en etait le destin." << std::endl;
    } else if(typePiece == TypePiece::CAVALIER){
        std::cout << "Cavalier: Haha! Take this!" << std::endl;
        std::cout << "Fou: Tel en etait le destin." << std::endl;
    } else if(typePiece == TypePiece::FOU){
        std::cout << "Fou: Tel en etait le destin." << std::endl;
        std::cout << "Fou: Que ton âme repose en paix." << std::endl;
    } else if(typePiece == TypePiece::TOUR){
        std::cout << "Tour: kkkkkrkkkkk! kkkkkkkkk!!" << std::endl;
        std::cout << "Fou: Tu partiras bientôt aussi dans l'au delà démon." << std::endl;
    } else if(typePiece == TypePiece::REINE){
        std::cout << "Reine: La noblesse reste au dessus du clergé." << std::endl;
        std::cout << "Fou: Dans ce monde peut-être." << std::endl;
    } else if(typePiece == TypePiece::ROI){
        std::cout << "Roi: Vas dire a ton Dieu qui est le véritable souverain." << std::endl;
        std::cout << "Fou: Sacrilège!" << std::endl;
    }
    std::cout << "Le fou en " + getPosition() + " est mort" << std::endl;
}

Fou::~Fou(){
}

std::vector<std::vector<std::pair<int, int>>> Fou::getDeplacementsPossibles(int x, int y){
    std::vector<std::vector<std::pair<int, int>>> deplacements;
    int droite = 7-x;
    int gauche = x;
    int haut = 7-y;
    int bas = y;
    for(int i = 0; i < 4; i++){
        deplacements.push_back(std::vector<std::pair<int, int>>());
    }
    for(int i = 1; i <= std::min(droite, haut); i++){
        deplacements.at(0).push_back({x+i, y+i});
    }
    for(int i = 1; i <= std::min(gauche, haut); i++){
        deplacements.at(1).push_back({x-i, y+i});
    }
    for(int i = 1; i <= std::min(droite, bas); i++){
        deplacements.at(2).push_back({x+i, y-i});
    }
    for(int i = 1; i <= std::min(gauche, bas); i++){
        deplacements.at(3).push_back({x-i, y-i});
    }
    return deplacements;
}