#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;

class Piece{
    
    private:
        bool couleur;
        std::string position;
        std::string type;

    public:
        Piece(bool couleur, std::string position);
        void deplacer(std::string position);
        void deplacer(int x, int y);
        bool operator==(Piece &p);
        void messageMort();
        ~Piece();
        std::string getType();
        std::string getPosition();
        ///void messageCapture();

};

#endif