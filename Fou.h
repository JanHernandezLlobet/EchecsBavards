#ifndef FOU_H
#define FOU_H
#include "Piece.h"


class Fou : public Piece {

    private:

    public:
        Fou(bool couleur, std::string position);
        void messageMort();
        ~Fou();

};

#endif