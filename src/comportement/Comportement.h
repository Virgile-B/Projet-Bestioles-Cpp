//
// Created by yassine on 05/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_H
#define PROJET_BESTIOLES_COMPORTEMENT_H

#include "../UImg.h"
#include "../Milieu.h"

class Bestiole;

/*
 * Interface Comportement
*/
class Comportement {
public:
    T              * couleur;
    std::string type;
    virtual void action(Bestiole * actualBestiole, Milieu &monMilieu) = 0;
    virtual T * get_couleur() = 0;
    virtual std::string get_type() = 0;

};


#endif //PROJET_BESTIOLES_COMPORTEMENT_H
