#include "Pion.h"

Pion::Pion(bool couleur, std::string position) : Piece(couleur, position, TypePiece::PION) {
    this->premierCoupFait = false;
    cout << "Pion " + position + " cree" << endl;
}

void Pion::messageMort(TypePiece typePiece) {

    if(typePiece == TypePiece::PION){
        std::cout << "Pion: Ce fut un humble duel." << std::endl;
        std::cout << "Pion: au revoir. " << std::endl;
    } else if(typePiece == TypePiece::CAVALIER){
        std::cout << "Pion: c'est pas juste vous avez un cheval" << std::endl;
        std::cout << "Cavalier: Eat the soil lil peasant." << std::endl;
    } else if(typePiece == TypePiece::FOU){
        std::cout << "Fou: Le prix pour tes péchés." << std::endl;
        std::cout << "Pion: Noooon…" << std::endl;
    } else if(typePiece == TypePiece::TOUR){
        std::cout << "Pion: Quoi ?! Depuis quand les bâtiments se déplacent!" << std::endl;
        std::cout << "Tour: kkkrkrrrrk!! kkkrrrrr!!" << std::endl;
    } else if(typePiece == TypePiece::REINE){
        std::cout << "Reine: Dehors!" << std::endl;
        std::cout << "Pion: …" << std::endl;
    } else if(typePiece == TypePiece::ROI){
        std::cout << "Roi: On en est arrivés au stade ou je dois me salir les mains ?!?" << std::endl;
        std::cout << "Pion: eh ?" << std::endl;
    }
    std::cout << "Le pion en " + getPosition() + " est mort" << std::endl;
}

Pion::~Pion(){
}

bool Pion::getCouleur() {
    return this->couleur;
}

std::vector<std::vector<std::pair<int, int> > > Pion::getDeplacementsPossibles(int x, int y) {
    std::vector<std::vector<std::pair<int, int> > > deplacements;
    for (int i = 0; i < 2; i++) {
        deplacements.push_back(std::vector<std::pair<int, int> >());
    }
    if (this->getCouleur()) {
        deplacements.at(0).push_back({x, y + 1});
        deplacements.at(0).push_back({x, y + 2});
        deplacements.at(1).push_back({x + 1, y + 1});
        deplacements.at(1).push_back({x - 1, y + 1});
    } else {
        deplacements.at(0).push_back({x, y - 1});
        deplacements.at(0).push_back({x, y - 2});
        deplacements.at(1).push_back({x + 1, y - 1});
        deplacements.at(1).push_back({x - 1, y - 1});
    }
    return deplacements;
}
