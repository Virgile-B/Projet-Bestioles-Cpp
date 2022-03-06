//
// Created by ludo on 06/03/2022.
//

#include "ComportementPeureuse.h"

ComportementPeureuse *ComportementPeureuse::comportement_peureuse = nullptr;  // Instantiating the Pointer to the singleton

int* ComportementPeureuse::get_couleur(){
    return ComportementPeureuse::get_peureuse()->couleur;
}

ComportementPeureuse::ComportementPeureuse(void){
    couleur = new int[ 3 ];
    couleur[ 0 ] = 125;
    couleur[ 1 ] = 125;
    couleur[ 2 ] = 125;
}
