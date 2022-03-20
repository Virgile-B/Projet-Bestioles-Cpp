#include "Milieu.h"

#include <cstdlib>
#include <ctime>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
const int   Milieu::PROBA_NAIS = 10; // en %

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

    cout << "const Milieu" << endl;

}

void Milieu::step( void ) {
    cimg_forXY(*this, x, y)
    fillC(x, y, 0, white[0], white[1], white[2]);
    this->naissance(this->type);
    std::vector < Bestiole * > toRemove;
    if (listeBestioles.size() != 0) {
        for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
            if ((*it)->meurt() || (*it)->getVie()) {
                removeMember(*it, toRemove);
            } else {
                this->collision(*(*it));
                (*it)->action(*this);
                (*it)->draw(*this);
                (*it)->draw_oreilles(*this);
                (*it)->draw_yeux(*this);
            }
            nbBestioles = listeBestioles.size();
        }
        if (!(toRemove.empty())){
            for (std::vector<Bestiole *>::iterator it = toRemove.begin(); it != toRemove.end(); ++it) {
                listeBestioles.erase(std::remove(listeBestioles.begin(), listeBestioles.end(), *it), listeBestioles.end());
                (*it)->~Bestiole();
            }
        }
    }
}

std::vector<Bestiole*> Milieu::Voisins( const Bestiole & b)
{
    std::vector<Bestiole*> listeVoisins;
    for (std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it) {
        if (b.get_identite() != (*it)->get_identite() && (b.jeTeVois(*(*it)) || b.jeTentends(*(*it)))) {
            Bestiole *point_b = *it;
            listeVoisins.push_back(point_b);
        }
    }
    return listeVoisins;
}

void Milieu::naissance(char* type)
{

    if(strcmp(type, "random") == 0)   {
        if( (std::rand() % 100+1) < PROBA_NAIS){
            std::cout<< "second iteration random"<< std::endl;
            Bestiole* ptr_bestiole = new Bestiole();
            addMember(ptr_bestiole);
        }
    }
    else
    {
        if( (std::rand() % 100+1) < PROBA_NAIS){
            std::cout<< "second iteration not random"<< std::endl;
            Bestiole* ptr_bestiole = new Bestiole(type);
            addMember(ptr_bestiole);
        }
    }
    nbBestioles = listeBestioles.size();
}

void Milieu::removeMember(Bestiole *b, std::vector<Bestiole*> &toRemove) {
    toRemove.push_back(b);
}

void Milieu::setSimulation(int nbBestioles, char* type)
{
    this->type = type;
    this->nbBestioles = nbBestioles;
}

char* Milieu::getType()
{
    return this->type;
}

int Milieu::getNbBestioles()
{
    return this->nbBestioles;
}

void Milieu::collision(Bestiole & b){
    std::vector<Bestiole*> voisins = this->Voisins(b);
    for ( std::vector<Bestiole*>::iterator it = voisins.begin() ; it != voisins.end() ; ++it ){
        if( std::sqrt(((*it)->getX() - b.getX()) * ((*it)->getX() - b.getX()) + ((*it)->getY() - b.getY()) * ((*it)->getY() - b.getY())) < b.getSize()){
            b.inverse_orientation(*(*it));
        }
    }
}
