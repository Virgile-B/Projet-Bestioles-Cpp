//
// Created by ludo on 06/03/2022.
//

#include "ComportementKamikaze.h"

ComportementKamikaze *ComportementKamikaze::comportement_kamikaze = nullptr;  // Instantiating the Pointer to the singleton

T* ComportementKamikaze::get_couleur(){
    return ComportementKamikaze::get_kamikaze()->couleur;
}

ComportementKamikaze::ComportementKamikaze(void){
    couleur = new T[ 3 ];
    couleur[ 0 ] = 255;
    couleur[ 1 ] = 0;
    couleur[ 2 ] = 0;
}

ComportementKamikaze::~ComportementKamikaze()
{
    delete[] couleur;
}
