//
// Created by ludo on 06/03/2022.
//

#ifndef PROJET_BESTIOLES_COMPORTEMENT_KAMIKAZE_H
#define PROJET_BESTIOLES_COMPORTEMENT_KAMIKAZE_H

#include  "Comportement.h"

/*
 * Singleton class ComportementKamikaze
 */
class ComportementKamikaze : public Comportement {
    static ComportementKamikaze *comportement_kamikaze;  // Pointer to the singleton
    ComportementKamikaze();

public:

    /*
     * Static method that controls access to the singleton
     */
    static ComportementKamikaze *get_kamikaze() {
        if (!comportement_kamikaze)
            comportement_kamikaze = new ComportementKamikaze();
        return comportement_kamikaze;
    }

    T *get_couleur();
    std::string get_type();

    void action(Bestiole *actualBestiole, Milieu &monMilieu);
};


#endif //PROJET_BESTIOLES_COMPORTEMENT_KAMIKAZE_H
