#ifndef ROI_H
#define ROI_H
#include "Piece.h"


class Roi : public Piece {

    private:

    public:
        Roi(bool couleur, std::string position);
        void messageMort();
        ~Roi();

};

#endif