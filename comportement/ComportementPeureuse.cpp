//
// Created by ludo on 06/03/2022.
//

#include "ComportementPeureuse.h"

ComportementPeureuse *ComportementPeureuse::comportement_peureuse = nullptr;  // Instantiating the Pointer to the singleton

T* ComportementPeureuse::get_couleur(){
    return ComportementPeureuse::get_peureuse()->couleur;
}

ComportementPeureuse::ComportementPeureuse(void){
    couleur = new T[ 3 ];
    couleur[ 0 ] = 125;
    couleur[ 1 ] = 125;
    couleur[ 2 ] = 125;
}
ComportementPeureuse::~ComportementPeureuse()
{
    delete[] couleur;
}