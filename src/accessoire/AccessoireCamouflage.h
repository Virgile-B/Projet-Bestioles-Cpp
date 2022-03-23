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
        extern float RandomValues(double min, double max); // defninie dans utils.cpp
        extern double global_coef_camouflage_min; // Récupération de la variable gloable global_coef_camouflage_min
        extern double global_coef_camouflage_max; // Récupération de la variable gloable global_coef_camouflage_max
        srand(time(0)); // initialisation du générateur aléatoire
        global_coef_camouflage_min = (global_coef_camouflage_min>1)? 1 : global_coef_camouflage_min;
        global_coef_camouflage_max = (global_coef_camouflage_max>1)? 1 : global_coef_camouflage_max;

        coef_camouflage = RandomValues(global_coef_camouflage_min, global_coef_camouflage_max);
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
