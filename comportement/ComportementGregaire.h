//
// Created by yassine on 05/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_GREGAIRE_H
#define PROJET_BESTIOLES_COMPORTEMENT_GREGAIRE_H

#include  "Comportement.h"

/*
 * Singleton class ComportementGrégaire
 */
class ComportementGregaire : public Comportement {
    static ComportementGregaire *comportement_gregaire;  // Pointer to the singleton
    ComportementGregaire();
public:

    /*
     * Static method that controls access to the singleton
     */
    static ComportementGregaire *get_gregaire() {
        if (!comportement_gregaire)
            comportement_gregaire = new ComportementGregaire();
        return comportement_gregaire;
    }

    T *get_couleur();

    void action() {};

    ~ComportementGregaire();
};


#endif //PROJET_BESTIOLES_COMPORTEMENT_GREGAIRE_H
