//
// Created by yassine on 05/03/2022.
//

#include "ComportementGregaire.h"

ComportementGregaire *ComportementGregaire::comportement_gregaire = nullptr;  // Instantiating the Pointer to the singleton

int* ComportementGregaire::get_couleur(){
    return ComportementGregaire::get_gregaire()->couleur;
}

ComportementGregaire::ComportementGregaire(void){
    couleur = new int[ 3 ];
    couleur[ 0 ] = 10;
    couleur[ 1 ] = 10;
    couleur[ 2 ] = 10;
}
