#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <iostream>
using namespace std;
#include "Piece.h"

class Echiquier{
    
    private:
        int longueur;
        int largeur;
        bool couleur;
        Piece*** grille;
        //Historique* historique;

    public:
        Echiquier(int longueur, int largeur, bool couleur);
        void afficher();
        ~Echiquier();
        void ajouterPiece(Piece* piece, std::string position);
        void ajouterPiece(Piece* piece, int x, int y);
        void enleverPiece(std::string position);
        void enleverPiece(int x, int y);
        //bool caseAttaquee(std::string position);
        //bool caseAttaquee(int x, int y);
        //bool coupPossible(Piece* piece, std::string position);
        //bool coupPossible(Piece* piece, int x, int y);
        bool caseAttaquee(string pos);

};

#endif