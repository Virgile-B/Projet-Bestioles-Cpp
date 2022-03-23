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
        extern float RandomValues(double min, double max); // defninie dans utils.cpp
        extern double global_coef_carapace_max; // Récupération de la variable gloable global_coef_carapace_max
        extern double global_coef_ralentissement_max; // Récupération de la variable gloable global_coef_ralentissement_max
        srand(time(0)); // initialisation du générateur aléatoire

        coef_carapace = RandomValues(1,global_coef_carapace_max);
        coef_ralentissement = RandomValues(1, global_coef_ralentissement_max);
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
