#ifndef PION_H
#define PION_H
#include "Piece.h"


class Pion : public Piece {

    private:

        bool premierCoupFait;

    public:
        Pion(bool couleur, std::string position);
        void messageMort();
        ~Pion();

};

#endif