//
// Created by ludo on 06/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_PREVOYANTE_H
#define PROJET_BESTIOLES_COMPORTEMENT_PREVOYANTE_H

#include  "Comportement.h"

/*
 * Singleton class ComportementPeureuse
 */
class ComportementPrevoyante : public Comportement {
    static ComportementPrevoyante *comportement_prevoyante;  // Pointer to the singleton
    ComportementPrevoyante();
    ~ComportementPrevoyante();

public:

    /*
     * Static method that controls access to the singleton
     */
    static ComportementPrevoyante *get_prevoyante() {
        if (!comportement_prevoyante)
            comportement_prevoyante = new ComportementPrevoyante();
        return comportement_prevoyante;
    }

    T *get_couleur();
    std::string get_type();

    void action(Bestiole *actualBestiole, Milieu &monMilieu);
};


#endif //PROJET_BESTIOLES_COMPORTEMENT_PREVOYANTE_H
