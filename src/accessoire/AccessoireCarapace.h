//
// Created by yassine on 21/03/2022.
//

#ifndef PROJET_BESTIOLES_ACCESSOIRCARAPACE_H
#define PROJET_BESTIOLES_ACCESSOIRCARAPACE_H

#include "Accessoire.h"
#include <string>
#include <iostream>

class Bestiole;

/*
 * classe Singleton pour que toutes les bestioles d'une meme simulation partagent les memes accessoires.
*/
class AccessoireCarapace : public Accessoire {

    // Seul pointeur pointant sur l'accessoire Carapace
    static AccessoireCarapace *accessoire_carapace;

    /*
     * Constructeur pour initialiser le coef_carapace et coef_ralentissement qui sont pris respectivement aléatoirement
     * entre 1 et global_coef_carapace_max et 1 et global_coef_ralentissement_max
    */
    AccessoireCarapace() {
        // extern double global_coef_carapace_max; // NE PAS OUBLIER CA
        // extern double global_coef_ralentissement_max; // NE PAS OUBLIER CA
        srand(time(0)); // initialisation du générateur aléatoire
        int global_coef_carapace_max = 10;
        int global_coef_ralentissement_max = 5;

        coef_carapace = 1 + (rand() % global_coef_carapace_max);
        coef_ralentissement = 1 + (rand() % global_coef_ralentissement_max);
    };
public:
    double coef_carapace; // coefficient carapace à multiplier aux points de vie de la bestiole
    double coef_ralentissement; // coefficient ralentissent qui sera le diviseur de la vitesse de la bestiole

    /*
     * Méthode d'accès au pointeur du singleton
     */
    static AccessoireCarapace *get_carapace() {
        if (!accessoire_carapace) {
            accessoire_carapace = new AccessoireCarapace();
        }
        return accessoire_carapace;
    };

    // La réécriture de la méthode gadgetAction
    void gadgetAction(Bestiole *b);

    // La réécriture de la méthode drawGadget
    void drawGadget(Bestiole *b, UImg &support);

};


#endif //PROJET_BESTIOLES_ACCESSOIRCARAPACE_H
