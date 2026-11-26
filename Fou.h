#ifndef FOU_H
#define FOU_H
#include "Piece.h"


class Fou : public Piece {

    private:

    public:
        Fou(bool couleur, std::string position);
        void messageMort(TypePiece typePiece);
        ~Fou();
        std::vector<std::vector<std::pair<int, int>>> getDeplacementsPossibles(int x, int y) override;


};

#endif