#ifndef TOUR_H
#define TOUR_H
#include "Piece.h"


class Tour : public Piece {

    private:

    public:
        Tour(bool couleur, std::string position);
        void messageMort();
        ~Tour();

};

#endif