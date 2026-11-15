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


};


#endif