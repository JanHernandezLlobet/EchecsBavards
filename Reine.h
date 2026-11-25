#ifndef REINE_H
#define REINE_H
#include "Piece.h"


class Reine : public Piece {

    private:

    public:
        Reine(bool couleur, std::string position);
        void messageMort();
        ~Reine();
        std::vector<std::vector<std::pair<int, int>>> getDeplacementsPossibles(int x, int y);
        static std::vector<std::vector<std::pair<int, int>>> getDeplacementsReine(int x, int y);

    };

#endif