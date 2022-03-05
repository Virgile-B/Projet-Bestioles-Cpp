//
// Created by yassine on 05/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_H
#define PROJET_BESTIOLES_COMPORTEMENT_H

/*
 * Interface comportement
*/
class comportement {
public:
    T               * couleur;
    virtual void action() = 0;
};


#endif //PROJET_BESTIOLES_COMPORTEMENT_H
