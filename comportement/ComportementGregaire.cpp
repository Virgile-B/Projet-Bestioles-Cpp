//
// Created by yassine on 05/03/2022.
//

#include "ComportementGregaire.h"


ComportementGregaire *ComportementGregaire::comportement_gregaire = nullptr;  // Instantiating the Pointer to the singleton

T* ComportementGregaire::get_couleur(){
    return ComportementGregaire::get_gregaire()->couleur;
}

ComportementGregaire::ComportementGregaire(void){
    couleur = new T[ 3 ];
    couleur[ 0 ] = 0;
    couleur[ 1 ] = 255;
    couleur[ 2 ] = 0;
}

void ComportementGregaire::action(Bestiole *actualBestiole, Milieu &monMilieu){
    float dir_moy = 0;
    std::cout << actualBestiole->get_orientation() << std::endl;
    std::vector<Bestiole> mesVoisins = monMilieu.Voisins(*actualBestiole);
    if (mesVoisins.size() != 0){
        for ( std::vector<Bestiole>::iterator it = mesVoisins.begin() ; it != mesVoisins.end() ; ++it ){
        dir_moy += (it->get_orientation());
    }
    actualBestiole->set_orientation(dir_moy/(mesVoisins.size()));
    }
}

