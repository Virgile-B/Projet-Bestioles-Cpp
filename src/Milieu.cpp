#include "Milieu.h"
#include <string.h>
#include <cstdlib>
#include <ctime>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
const int   Milieu::PROBA_NAIS = 5; // en %

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

    cout << "const Milieu" << endl;

}

void Milieu::step( void ) {
    cimg_forXY(*this, x, y)
    fillC(x, y, 0, white[0], white[1], white[2]);
    this->naissance();
    std::vector < Bestiole * > toRemove;
    if (listeBestioles.size() != 0) {
        for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
            if ((*it)->meurt(*this)) {
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

void Milieu::naissance()
{    
    if(nb_peureuse != 0)   {
        if( (std::rand() % 100+1) > 100-PROBA_NAIS){
            std::cout<< "naissance peureuse"<< std::endl;
            Bestiole* ptr_bestiole = new Bestiole("peureuse");
            addMember(ptr_bestiole);
        }
    }
    if( nb_prevoyante != 0)   {
        if( (std::rand() % 100+1) > 100-PROBA_NAIS){
            std::cout<< "naissance prevoyante"<< std::endl;
            Bestiole* ptr_bestiole = new Bestiole("prevoyante");
            addMember(ptr_bestiole);
        }
    }
    if( nb_gregaire != 0)   {
        if( (std::rand() % 100+1) > 100-PROBA_NAIS){
            std::cout<< "naissance gregaire"<< std::endl;
            Bestiole* ptr_bestiole = new Bestiole("gregaire");
            addMember(ptr_bestiole);
        }
    }
    if( nb_kamikaze != 0)   {
        if( (std::rand() % 100+1) > 100-PROBA_NAIS){
            std::cout<< "naissance kamikaze"<< std::endl;
            Bestiole* ptr_bestiole = new Bestiole("kamikaze");
            addMember(ptr_bestiole);
        }
    }
    if( nb_multiple != 0)   {
        if( (std::rand() % 100+1) > 100-PROBA_NAIS){
            std::cout<< "naissance multiple"<< std::endl;
            Bestiole* ptr_bestiole = new Bestiole("multiple");
            addMember(ptr_bestiole);
        }
    }
    nbBestioles = listeBestioles.size();
}

void Milieu::removeMember(Bestiole *b, std::vector<Bestiole*> &toRemove) {
    toRemove.push_back(b);
}

void Milieu::setSimulation(int nb_peureuse, int nb_prevoyante, int nb_multiple, int nb_gregaire, int nb_kamikaze)
{
    this->nb_peureuse = nb_peureuse;
    this->nb_prevoyante = nb_prevoyante;
    this->nb_multiple = nb_multiple;
    this->nb_gregaire = nb_gregaire;
    this->nb_kamikaze = nb_kamikaze;
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
        if (((*it)->get_x() == b.get_x()) && ((*it)->get_y() == b.get_y())){
            b.inverse_orientation(*(*it));
        }
    }
}

void Milieu::setNbPeureuse(int nb)
{
    this->nb_peureuse = nb;
}
void Milieu::setNbKamikaze(int nb)
{
    this->nb_kamikaze = nb;
}
void Milieu::setNbMultiple(int nb)
{
    this->nb_multiple = nb;
}
void Milieu::setNbGregaire(int nb)
{
    this->nb_gregaire = nb;
}
void Milieu::setNbPrevoyante(int nb)
{
    this->nb_prevoyante = nb;
}

int Milieu::getNbPeureuse()
{
    int compteur = 0;
    for (std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it) {
        if ((*it)->getType() == "peureuse") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}
int Milieu::getNbKamikaze()
{
    int compteur = 0;
    for (std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it) {
        if ((*it)->getType()=="kamikaze") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}
int Milieu::getNbMultiple()
{
    int compteur = 0;
    for (std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it) {
        if ((*it)->estMultiple()==true) {
            compteur = compteur + 1;
        }
    }
    return compteur;
}
int Milieu::getNbGregaire()
{
   int compteur = 0;
    for (std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it) {
        if ((*it)->getType()=="gregaire") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}
int Milieu::getNbPrevoyante()
{
   int compteur = 0;
    for (std::vector<Bestiole*>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it) {
        if ((*it)->getType()=="prevoyante") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}
