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

ComportementGregaire::~ComportementGregaire(){
    delete[] couleur;
}
