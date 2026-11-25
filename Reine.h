#ifndef REINE_H
#define REINE_H
#include "Piece.h"


class Reine : public Piece {

    private:

    public:
        Reine(bool couleur, std::string position);
        void messageMort();
        ~Reine();

};

#endif