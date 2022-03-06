//
// Created by ludo on 06/03/2022.
//

#include "ComportementPrevoyante.h"

ComportementPrevoyante *ComportementPrevoyante::comportement_prevoyante = nullptr;  // Instantiating the Pointer to the singleton

int* ComportementPrevoyante::get_couleur(){
    return ComportementPrevoyante::get_prevoyante()->couleur;
}

ComportementPrevoyante::ComportementPrevoyante(void){
    couleur = new int[ 3 ];
    couleur[ 0 ] = 0;
    couleur[ 1 ] = 0;
    couleur[ 2 ] = 255;
}
