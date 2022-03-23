//
// Created by yassine on 21/03/2022.
//

#ifndef PROJET_BESTIOLES_ACCESSOIRECAMOUFLAGE_H
#define PROJET_BESTIOLES_ACCESSOIRECAMOUFLAGE_H

#include "Accessoire.h"
#include <string>
#include <iostream>

/*
 * classe Singleton pour que toutes les bestioles d'une meme simulation partagent les memes accessoires.
*/
class AccessoireCamouflage : public Accessoire {

    // Seul pointeur pointant sur l'accessoire camouflage
    static AccessoireCamouflage *accessoire_camouflage;

    /*
     * Constructeur pour initialiser le coef_camouflage qui est pris aléatoirement entre global_coef_camouflage_min et
     * global_coef_camouflage_max
    */
    AccessoireCamouflage() {
        // extern double global_coef_carapace_max; // NE PAS OUBLIER CA
        // extern double global_coef_ralentissement_max; // NE PAS OUBLIER CA
        double global_coef_camouflage_min = 0.;
        double global_coef_camouflage_max = 1.;

        coef_camouflage = global_coef_camouflage_min +
                          rand() / RAND_MAX * (global_coef_camouflage_max - global_coef_camouflage_min);
    };

public:

    // coef_camouflage qui sera comparé à gamma yeux et gamma ouie
    double coef_camouflage;

    // méthode pour récupérer le pointeur camouflage
    static AccessoireCamouflage *get_camouflage() {
        if (!accessoire_camouflage) {
            accessoire_camouflage = new AccessoireCamouflage();
        }
        return accessoire_camouflage;
    }

    // La réécriture de la méthode gadgetAction
    void gadgetAction(Bestiole *b);

    // La réécriture de la méthode drawGadget
    void drawGadget(Bestiole *b, UImg &support);
};


#endif //PROJET_BESTIOLES_ACCESSOIRECAMOUFLAGE_H
