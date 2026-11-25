#include "Echiquier.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include "Reine.h"
#include "Cavalier.h"
using namespace std;

Echiquier::Echiquier(int longueur, int largeur, bool couleur){
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
    std::cout << "[CHAT]:\n             chat a faire...";
}

Echiquier::~Echiquier(){
    for (int i = 0; i < longueur; i++){
        for (int j = 0; j < largeur; j++){
            delete grille[i][j]; 
        }
        delete[] grille[i]; 
    }
    delete[] grille; 
    std::cout << "Echiquier detruit" << std::endl;
}

void Echiquier::ajouterPiece(Piece* piece, std::string position){
    int x = position[0] - 64;
    int y = position[1] - 48;
    grille[x - 1][y - 1] = piece;
    piece->deplacer(position);

}

void Echiquier::ajouterPiece(Piece* piece, int x, int y){
    grille[x][y] = piece;
    piece->deplacer(x, y);
}

void Echiquier::enleverPiece(std::string position){
    int x = position[0] - 64;
    int y = position[1] - 48;
    if (grille[x - 1][y - 1] != nullptr) {
        delete grille[x - 1][y - 1];
        grille[x - 1][y - 1] = nullptr;
    }
}

void Echiquier::enleverPiece(int x, int y){
    if (grille[x][y] != nullptr) {
        delete grille[x][y];
        grille[x][y] = nullptr;
    }
}

bool Echiquier::caseAttaquee(int x, int y) {

    std::vector<std::vector<std::pair<int, int>>> listeCase,listeCase2;
    std::vector<std::vector<std::pair<int, int>>> listeCasePiece;
    Piece* piece;

    listeCase = Reine::getDeplacementsPossibles(x,y);
    listeCase2 = Cavalier::getDeplacementsPossibles(x,y);
    listeCase.insert(listeCase.end(), listeCase2.begin(), listeCase2.end());

    for (int i = 0; i < listeCase.size(); i++) { // Reine, fou, tour, roi, pion
        for (int j = 0; j < listeCase[i].size(); j++) {

            piece = this->grille[listeCase.at(i).at(j).first][listeCase.at(i).at(j).second];
            if (piece != nullptr && piece->couleur != this->grille[x][y]->couleur) {
                listeCasePiece = piece->getDeplacementsPossibles();
                for (int k = 0; k < listeCasePiece.size(); k++) {
                    for (int l = 0; l < listeCasePiece[k].size(); l++) {
                        if (listeCasePiece.at(k).at(l).first == x && listeCasePiece.at(k).at(l).second == y) {
                            return true;
                        }
                    }
                }

                break;
            }

            if (piece != nullptr) {
                break;
            }
        }
    }
    return false;

}



