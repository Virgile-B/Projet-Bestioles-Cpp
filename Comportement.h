//
// Created by yassine on 05/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_H
#define PROJET_BESTIOLES_COMPORTEMENT_H
#include "UImg.h"
/*
 * Interface Comportement
*/
class Comportement {
public:
    T              * couleur;
    virtual void action() = 0;
    virtual T * get_couleur() = 0;
};


#endif //PROJET_BESTIOLES_COMPORTEMENT_H
