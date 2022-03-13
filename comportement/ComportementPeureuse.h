//
// Created by ludo on 06/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_PEUREUSE_H
#define PROJET_BESTIOLES_COMPORTEMENT_PEUREUSE_H

#include  "Comportement.h"

/*
 * Singleton class ComportementPeureuse
 */
class ComportementPeureuse : public Comportement {
    static ComportementPeureuse *comportement_peureuse;  // Pointer to the singleton
    ComportementPeureuse();
public:

    /*
     * Static method that controls access to the singleton
     */
    static ComportementPeureuse *get_peureuse() {
        if (!comportement_peureuse)
            comportement_peureuse = new ComportementPeureuse();
        return comportement_peureuse;
    }

    T *get_couleur();

    void action() {};
};


#endif //PROJET_BESTIOLES_COMPORTEMENT_PEUREUSE_H
