#ifndef CAVALIER_H
#define CAVALIER_H
#include "Piece.h"


class Cavalier : public Piece {

    private:

    public:
        Cavalier(bool couleur, std::string position);
        void messageMort();
        ~Cavalier();
       
};

#endif