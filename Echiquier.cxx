#include "Echiquier.h"
#include "Piece.h"
#include <iostream>
using namespace std;

Echiquier::Echiquier(int longueur, int largeur, bool couleur) {
    this->longueur = longueur;
    this->largeur = largeur;
    this->couleur = couleur;

    this->grille = new Piece**[longueur];

    for (int i = 0; i < longueur; i++){
        this->grille[i] = new Piece*[largeur];

        for (int j = 0; j < largeur; j++){
            this->grille[i][j] = nullptr; 
        }
    }
}

void Echiquier::afficher() {

    std::cout << "\n\n     A     B     C     D     E     F     G     H\n";
    std::cout << "  |-----|-----|-----|-----|-----|-----|-----|-----|\n";
    for (int i = 0; i < longueur; i++){
        std::cout << i + 1 << " |";


        for (int j = 0; j < largeur; j++){
            if(grille[i][j] == nullptr){
                std::cout << "     ";
            } else {
                std::cout << " " << grille[i][j]->getType() << " ";
            }
            std::cout << "|";
        }
        std::cout << "\n  |-----|-----|-----|-----|-----|-----|-----|-----|\n";
    }
    std::cout << "\n";
}

Echiquier::~Echiquier() {
    for (int i = 0; i < longueur; i++){
        for (int j = 0; j < largeur; j++){
            delete grille[i][j]; 
        }
        delete[] grille[i]; 
    }
    delete[] grille; 
}


void Echiquier::ajouterPiece(Piece* piece, std::string position) {

    std::string pos1 = position;

}