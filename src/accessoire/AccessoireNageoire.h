#ifndef PROJET_BESTIOLES_ACCESSOIRENAGEOIRE

#include "Accessoire.h"
#include <string>
#include <iostream>

class Bestiole;

class AccessoireNageoire : public Accessoire {
    static AccessoireNageoire *accessoire_nageoire;  // Pointer to the singleton
    AccessoireNageoire() {
        srand(time(0));
        // extern double global_coef_vitesse_max; // NE PAS OUBLIER CA
        int global_coef_vitesse_max = 5.;
        coef_vitesse = 1 + (rand()%global_coef_vitesse_max);;
    };
    //string nom;
public:
    double coef_vitesse;

    static AccessoireNageoire *get_nageoire() {
        if (!accessoire_nageoire)
            accessoire_nageoire = new AccessoireNageoire();
        return accessoire_nageoire;
    }

    void gadgetAction(Bestiole *b);

    void drawGadget(Bestiole *b, UImg &support);

    //string getName();

};


#endif