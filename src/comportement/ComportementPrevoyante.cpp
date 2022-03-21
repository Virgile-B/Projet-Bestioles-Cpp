//
// Created by ludo on 06/03/2022.
//

#include "ComportementPrevoyante.h"

ComportementPrevoyante *ComportementPrevoyante::comportement_prevoyante = nullptr;  // Instantiating the Pointer to the singleton

T* ComportementPrevoyante::get_couleur(){
    return ComportementPrevoyante::get_prevoyante()->couleur;
}

std::string ComportementPrevoyante::get_type(){
    return ComportementPrevoyante::get_prevoyante()->type;
}

ComportementPrevoyante::ComportementPrevoyante(void){
    couleur = new T[ 3 ];
    couleur[ 0 ] = 0;
    couleur[ 1 ] = 0;
    couleur[ 2 ] = 255;
    type = "prevoyante";
}

void ComportementPrevoyante::action(Bestiole *b, Milieu &monMilieu) {
    std::vector<Bestiole *> listeBestiole = monMilieu.getListeBestiole();
    for (std::vector<Bestiole *>::iterator it = listeBestiole.begin();
         it != listeBestiole.end(); ++it) {
        if (std::sqrt(((*it)->getX() - b->getX()) * ((*it)->getX() - b->getX()) +
                      ((*it)->getY() - b->getY()) * ((*it)->getY() - b->getY())) < (b->getSize()*2.5) &&
            b->get_identite() != (*it)->get_identite()) {
            b->set_orientation(b->get_orientation() + 0.5); // deviation de 30 degres
        }
    }
}
/*
ComportementPrevoyante::~ComportementPrevoyante()
{
    delete[] couleur;
}
*/