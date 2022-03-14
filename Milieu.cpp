#include "Milieu.h"

#include <cstdlib>
#include <ctime>

const T    Milieu::white[] = {(T) 255, (T) 255, (T) 255};
const int   Milieu::PROBA_NAIS = 5; // en %

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          width(_width), height(_height) {

    cout << "const Milieu" << endl;

}

void Milieu::step(void) {
    cimg_forXY(*this, x, y)
    fillC(x, y, 0, white[0], white[1], white[2]);
    this->naissance(this->type);
    if (listeBestioles.size() != 0) {
        for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
            if (it->meurt()) {
                removeMember(*it);
            } else {
                it->action(*this);
                it->draw(*this);
            }
        }
        nbBestioles = listeBestioles.size();
    }
}

int Milieu::nbVoisins(const Bestiole &b) {

    int nb = 0;


    for (std::vector<Bestiole>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it)
        if (!(b == *it) && b.jeTeVois(*it))
            ++nb;

    return nb;

}

void Milieu::naissance(char *type) {
    if (strcmp(type, "random") == 0) {
        if ((std::rand() % 100 + 1) < PROBA_NAIS) {
            std::cout << "second iteration random" << std::endl;
            addMember(Bestiole());
        }
    } else {
        if ((std::rand() % 100 + 1) < PROBA_NAIS) {
            std::cout << "second iteration not random" << std::endl;
            addMember(Bestiole(type));
        }
    }
    nbBestioles = listeBestioles.size();
}

void Milieu::removeMember(Bestiole &b) {
    std::remove(listeBestioles.begin(), listeBestioles.end(), b);
    b.Bestiole::~Bestiole();
    //std::remove(listeBestioles.begin(), listeBestioles.end(), b);
}

void Milieu::setSimulation(int nbBestioles, char *type) {
    this->type = type;
    this->nbBestioles = nbBestioles;
}

char *Milieu::getType() {
    return this->type;
}

int Milieu::getNbBestioles() {
    return this->nbBestioles;
}

