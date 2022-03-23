#ifndef PROJET_BESTIOLES_ACCESSOIRENAGEOIRE

#include "Accessoire.h"
#include <string>
#include <iostream>

class Bestiole;

/*
 * classe Singleton pour que toutes les bestioles d'une meme simulation partagent les memes accessoires.
*/
class AccessoireNageoire : public Accessoire {

    // Seul pointeur pointant sur l'accessoire Nageoire
    static AccessoireNageoire *accessoire_nageoire;

    /*
 * Constructeur pour initialiser le coef_vitesse pris aléatoirement entre 1 et global_coef_vitesse_max
    */
    AccessoireNageoire() {
        srand(time(0));
        // extern double global_coef_vitesse_max; // NE PAS OUBLIER CA
        int global_coef_vitesse_max = 5.;
        coef_vitesse = 1 + (rand() % global_coef_vitesse_max);;
    };

public:
    double coef_vitesse; // coef vitesse à multiplier par la vitesse de la bestiole

    /*
 * Méthode d'accès au pointeur du singleton
    */
    static AccessoireNageoire *get_nageoire() {
        if (!accessoire_nageoire)
            accessoire_nageoire = new AccessoireNageoire();
        return accessoire_nageoire;
    }

    // La réécriture de la méthode gadgetAction
    void gadgetAction(Bestiole *b);

    // La réécriture de la méthode drawGadget
    void drawGadget(Bestiole *b, UImg &support);

};


#endif