#ifndef CAVALIER_H
#define CAVALIER_H
#include "Piece.h"


class Cavalier : public Piece {

    private:

    public:
        Cavalier(bool couleur, std::string position);
        void messageMort(TypePiece typePiece);
        ~Cavalier();
        std::vector<std::vector<std::pair<int, int>>> getDeplacementsPossibles(int x, int y) override;
        static std::vector<std::vector<std::pair<int, int>>> getDeplacementsCavalier(int x, int y);
    };

#endif