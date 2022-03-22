//
// Created by ludo on 06/03/2022.
//

#include "ComportementPeureuse.h"
#include <cstdlib>
#include <cmath>

ComportementPeureuse *ComportementPeureuse::comportement_peureuse = nullptr;  // Instantiating the Pointer to the singleton

T* ComportementPeureuse::get_couleur(){
    return ComportementPeureuse::get_peureuse()->couleur;
}
std::string ComportementPeureuse::get_type(){
    return ComportementPeureuse::get_peureuse()->type;
}
ComportementPeureuse::ComportementPeureuse(void){
    couleur = new T[ 3 ];
    couleur[ 0 ] = 125;
    couleur[ 1 ] = 125;
    couleur[ 2 ] = 125;
    type = "peureuse";
}

void ComportementPeureuse::action(Bestiole *b, Milieu &monMilieu){
    std::vector<Bestiole *> voisins = monMilieu.Voisins(*b);
    if (voisins.size()>2){ // A CHANGER
        std::cout<< "voisins grands"<< std::endl;
        if (b->getStepComportement()==0){
            b->set_orientation(b->get_orientation() + M_PI); // deviation de 30 degres
            b->setStepComportement(15);
        }
    }
    if (b->getStepComportement()>0){
        b->setVitesse(b->getMAxVitesse());
        b->setStepComportement(b->getStepComportement()-1);
    } else if (b->getStepComportement() == 0 ){
        b->setVitesse(b->getOldVitesse());
    }
}

/*
ComportementPeureuse::~ComportementPeureuse()
{
    delete[] couleur;
}*/