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

    printf("\n\n     A     B     C     D     E     F     G     H\n");
    printf("  |-----|-----|-----|-----|-----|-----|-----|-----|\n");
    for (int i = 0; i < longueur; i++){
        printf("%d |", i + 1);


        for (int j = 0; j < largeur; j++){
            if(grille[i][j] == nullptr){
                printf("     ");
            } else {
                printf(" %s ", grille[i][j]->getType());
            }
            printf("|");
        }
        printf("\n  |-----|-----|-----|-----|-----|-----|-----|-----|\n");
    }
    printf("\n");
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