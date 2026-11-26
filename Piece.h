#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;
#include <vector>

enum class TypePiece { PION, TOUR, CAVALIER, FOU, REINE, ROI };

class Piece{

    public:

        std::string position;
        TypePiece type;

        bool couleur;

        Piece(bool couleur, std::string position, TypePiece type);
        void deplacer(std::string position);
        void deplacer(int x, int y);
        bool operator==(Piece &p);
        void messageMort(TypePiece typePiece);
        ~Piece();
        TypePiece getType();
        std::string getPosition();
        ///void messageCapture();
        std::vector<std::vector<std::pair<int, int>>> getDeplacementsPossibles();
        virtual std::vector<std::vector<std::pair<int, int>>> getDeplacementsPossibles(int x, int y) = 0;
        bool getCouleur();
};

#endif