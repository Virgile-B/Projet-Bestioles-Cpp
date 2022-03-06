//
// Created by yassine on 05/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_H
#define PROJET_BESTIOLES_COMPORTEMENT_H

/*
 * Interface Comportement
*/
class Comportement {
public:
    int               * couleur;
    virtual void action() = 0;
};


#endif //PROJET_BESTIOLES_COMPORTEMENT_H
