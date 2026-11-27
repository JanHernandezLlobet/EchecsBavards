#ifndef ECHIQUIER_H
#define ECHIQUIER_H
#include <iostream>
using namespace std;
#include "Piece.h"
#include <tuple>

class Echiquier{
    
    private:
        int longueur;
        int largeur;
        bool couleur;
        Piece*** grille;
        Piece* roiBlanc;
        Piece* roiNoir;
        //Historique* historique;

    public:
        Echiquier(int longueur, int largeur, bool couleur);
        void generer(std::vector<std::tuple<std::string, TypePiece, bool> > listePiece);
        void afficher();
        ~Echiquier();
        void ajouterPiece(Piece* piece, std::string position);
        void ajouterPiece(Piece* piece, int x, int y);
        void enleverPiece(std::string position);
        void enleverPiece(int x, int y);
        void deplacerPiece(Piece* piece, int x, int y);
        //bool caseAttaquee(std::string position);
        //bool caseAttaquee(int x, int y);
        //bool coupPossible(Piece* piece, std::string position);
        bool coupPossible(Piece* piece, int x, int y);
        bool caseAttaquee(int x, int y);
        std::string typeToString(TypePiece type);
        void jouerCoup(int x1, int y1, int x2, int y2);
        void jouerCoup(std::string coup1, std::string coup2);
        void afficher_alternatif_grand();
        void extra_line(int i);
        void afficher_alternatif_petit();

};

#endif