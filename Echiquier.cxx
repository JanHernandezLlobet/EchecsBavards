#include "Echiquier.h"
#include "Piece.h"
#include <iostream>
#include <vector>
#include "Reine.h"
#include "Cavalier.h"
#include "Fou.h"
#include "Pion.h"
#include "Roi.h"
#include "Tour.h"
using namespace std;
#include <tuple>

Echiquier::Echiquier(int longueur, int largeur, bool couleur) {
    this->longueur = longueur;
    this->largeur = largeur;
    this->couleur = couleur;

    this->grille = new Piece **[longueur];

    for (int i = 0; i < longueur; i++) {
        this->grille[i] = new Piece *[largeur];

        for (int j = 0; j < largeur; j++) {
            this->grille[i][j] = nullptr;
        }
    }
}

std::string Echiquier::typeToString(TypePiece type){
    static const std::string noms[] = { "P", "T", "C", "F", "D", "R" };
    return noms[static_cast<int>(type)];
}

void Echiquier::afficher() {
    std::cout << "\n\n     A     B     C     D     E     F     G     H\n";
    std::cout << "  |-----|-----|-----|-----|-----|-----|-----|-----|\n";
    for (int i = 0; i < longueur; i++) {
        std::cout << i + 1 << " |";


        for (int j = 0; j < largeur; j++) {
            if (grille[i][j] == nullptr) {
                std::cout << "     ";
            } else {
                std::cout << "  " << typeToString(grille[i][j]->getType()) << "  ";
            }
            std::cout << "|";
        }
        std::cout << "\n  |-----|-----|-----|-----|-----|-----|-----|-----|\n";
    }
    std::cout << "\n";
    std::cout << "[CHAT]:\n             chat a faire...";
}

Echiquier::~Echiquier() {
    for (int i = 0; i < longueur; i++) {
        for (int j = 0; j < largeur; j++) {
            delete grille[i][j];
        }
        delete[] grille[i];
    }
    delete[] grille;
    std::cout << "Echiquier detruit" << std::endl;
}

void Echiquier::ajouterPiece(Piece *piece, std::string position) {
    int x = position[0] - 64;
    int y = position[1] - 48;
    grille[x - 1][y - 1] = piece;
    piece->deplacer(position);
}

void Echiquier::ajouterPiece(Piece *piece, int x, int y) {
    grille[x][y] = piece;
    piece->deplacer(x, y);
}

void Echiquier::enleverPiece(std::string position) {
    int x = position[0] - 64;
    int y = position[1] - 48;
    if (grille[x - 1][y - 1] != nullptr) {
        delete grille[x - 1][y - 1];
        grille[x - 1][y - 1] = nullptr;
    }
}

void Echiquier::enleverPiece(int x, int y) {
    if (grille[x][y] != nullptr) {
        delete grille[x][y];
        grille[x][y] = nullptr;
    }
}

bool Echiquier::caseAttaquee(int x, int y) {
    std::vector<std::vector<std::pair<int, int> > > listeCase, listeCase2;
    std::vector<std::vector<std::pair<int, int> > > listeCasePiece;
    Piece *piece;

    listeCase = Reine::getDeplacementsReine(x, y);
    listeCase2 = Cavalier::getDeplacementsCavalier(x, y);
    listeCase.insert(listeCase.end(), listeCase2.begin(), listeCase2.end());

    for (int i = 0; i < listeCase.size(); i++) {
        // Reine, fou, tour, roi, pion
        for (int j = 0; j < listeCase[i].size(); j++) {
            piece = this->grille[listeCase.at(i).at(j).first][listeCase.at(i).at(j).second];
            if (piece != nullptr && piece->couleur != this->grille[x][y]->couleur) {
                listeCasePiece = piece->getDeplacementsPossibles();
                if (piece->type != TypePiece::PION) {
                    for (int k = 0; k < listeCasePiece.size(); k++) {
                        for (int l = 0; l < listeCasePiece[k].size(); l++) {
                            if (listeCasePiece.at(k).at(l).first == x && listeCasePiece.at(k).at(l).second == y) {
                                return true;
                            }
                        }
                    }
                } else {
                    for (int l = 0; l < listeCasePiece[1].size(); l++) {
                        if (listeCasePiece.at(1).at(l).first == x && listeCasePiece.at(1).at(l).second == y) {
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

void Echiquier::deplacerPiece(Piece *piece, int x, int y) {
    this->ajouterPiece(piece, x, y);
    int a = piece->position[0] - 64;
    int b = piece->position[1] - 48;
    grille[a][b] = nullptr;
}


bool Echiquier::coupPossible(Piece *piece, int x, int y) {
    int baseX = piece->position[0] - 64;
    int baseY = piece->position[1] - 48;
    Piece *basePiece = grille[baseX][baseY];
    piece->deplacer(x, y);

    bool result = true;

    if (roiBlanc->couleur == piece->couleur && caseAttaquee(roiBlanc->position[0] - 64, roiBlanc->position[1] - 48)) {
        result = false;
    }
    if (roiNoir->couleur == piece->couleur && caseAttaquee(roiNoir->position[0] - 64, roiNoir->position[1] - 48)) {
        result = false;
    }

    std::vector<std::vector<std::pair<int, int> > > coups = piece->getDeplacementsPossibles();
    if (piece->type == TypePiece::PION) {
        for (int i = 0; i < coups.at(0).size(); i++) {
            if (this->grille[coups.at(0).at(i).first][coups.at(0).at(i).second] != nullptr) {
                result = false;
                break;
            }
        }
    }

    if (piece->couleur == this->grille[x][y]->couleur) {
        result = false;
    }

    if (!result) {
        this->deplacerPiece(piece, x, y);
        this->grille[baseX][baseY] = basePiece;
        return false;
    }

    for (int i = 0; i < coups.size(); i++) {
        for (int j = 0; j < coups.at(i).size(); j++) {
            if (coups.at(i).at(j).first == x && coups.at(i).at(j).second == y) {
                this->deplacerPiece(piece, x, y);
                this->grille[baseX][baseY] = basePiece;
                return true;
            }
        }
    }

    this->deplacerPiece(piece, x, y);
    this->grille[baseX][baseY] = basePiece;
    return false;
}

void Echiquier::jouerCoup(int x1, int y1, int x2, int y2) {
    if (this->grille[x1][y1] != nullptr) {
        if (this->grille[x1][y1]->couleur == this->couleur) {
            if (coupPossible(this->grille[x1][y1], x2, y2)) {
                // coup possible
                if (this->grille[x2][y2]->type == TypePiece::ROI) {
                    // roi pris
                    if (this->grille[x2][y2]->couleur == 1) {
                        std::cout << "victoire des noirs" << "\n";
                    } else { std::cout << "victoire des blancs" << "\n"; }
                }
                // coup normal
                if (this->grille[x2][y2] != nullptr) {
                    this->grille[x2][y2]->messageMort(this->grille[x1][y1]->type);
                }
                enleverPiece(x2, y2);
                deplacerPiece(this->grille[x1][y1], x2, y2);
            } else { std::cout << "coup impossible" << "\n"; }
        } else {
            std::cout << "piece selectionné de la mauvaise couleur" << "\n";
        }
    } else {
        std::cout << "case vide" << "\n";
    }

    this->afficher();
}

void Echiquier::jouerCoup(std::string coup1, std::string coup2) {
    this->jouerCoup(coup1[0] - 64, coup1[1] - 48, coup2[0] - 64, coup2[1] - 48);
}

void Echiquier::generer(std::vector<std::tuple<std::string, TypePiece, bool> > listePiece) {
    for (int i = 0; i < listePiece.size(); i++) {
        switch (std::get<1>(listePiece.at(i))) {
            case TypePiece::PION: ajouterPiece(new Pion(std::get<2>(listePiece.at(i))
                                                        , std::get<0>(listePiece.at(i))),
                                               std::get<0>(listePiece.at(i)));
                break;
            case TypePiece::TOUR:
                ajouterPiece(new Tour(std::get<2>(listePiece.at(i))
                                      , std::get<0>(listePiece.at(i))), std::get<0>(listePiece.at(i)));
                break;
            case TypePiece::CAVALIER:
                ajouterPiece(new Cavalier(std::get<2>(listePiece.at(i))
                                          , std::get<0>(listePiece.at(i))), std::get<0>(listePiece.at(i)));
                break;
            case TypePiece::FOU:
                ajouterPiece(new Fou(std::get<2>(listePiece.at(i))
                                     , std::get<0>(listePiece.at(i))), std::get<0>(listePiece.at(i)));
                break;
            case TypePiece::REINE:
                ajouterPiece(new Reine(std::get<2>(listePiece.at(i))
                                       , std::get<0>(listePiece.at(i))), std::get<0>(listePiece.at(i)));
                break;
            case TypePiece::ROI:
                if (std::get<2>(listePiece.at(i)) == true)
                {this->roiBlanc = new Roi(std::get<2>(listePiece.at(i))
                                      , std::get<0>(listePiece.at(i)));
                ajouterPiece(this->roiBlanc, std::get<0>(listePiece.at(i)));
                }
                else{this->roiNoir = new Roi(std::get<2>(listePiece.at(i))
                                      , std::get<0>(listePiece.at(i)));
                    ajouterPiece(this->roiNoir, std::get<0>(listePiece.at(i)));
                }
                break;
        }
    }
}
