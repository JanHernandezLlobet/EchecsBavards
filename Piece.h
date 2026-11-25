#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;
#include <vector>


class Piece{

    public:

        std::string position;
        std::string type;

        bool couleur;

        Piece(bool couleur, std::string position, std::string type);
        void deplacer(std::string position);
        void deplacer(int x, int y);
        bool operator==(Piece &p);
        void messageMort();
        ~Piece();
        std::string getType();
        std::string getPosition();
        ///void messageCapture();
        std::vector<std::vector<std::pair<int, int>>> getDeplacementsPossibles();
        static std::vector<std::vector<std::pair<int, int>>> getDeplacementsPossibles(int x, int y);

};

#endif