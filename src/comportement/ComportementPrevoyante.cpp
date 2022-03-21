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
/*
ComportementPrevoyante::~ComportementPrevoyante()
{
    delete[] couleur;
}
*/