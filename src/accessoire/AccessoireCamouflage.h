//
// Created by yassine on 21/03/2022.
//

#ifndef PROJET_BESTIOLES_ACCESSOIRECAMOUFLAGE_H
#define PROJET_BESTIOLES_ACCESSOIRECAMOUFLAGE_H
#include "Accessoire.h"
#include <string>
#include <iostream>


class AccessoireCamouflage : public Accessoire {

    static AccessoireCamouflage* accessoire_camouflage;
    AccessoireCamouflage(){
        // extern double global_coef_carapace_max; // NE PAS OUBLIER CA
        // extern double global_coef_ralentissement_max; // NE PAS OUBLIER CA
        double global_coef_camouflage_max = 0.;
        double global_coef_camouflage_min = 1.;

        coef_camouflage = global_coef_camouflage_min + rand() / RAND_MAX * (global_coef_camouflage_max-global_coef_camouflage_min);
    };

public:
    double coef_camouflage;
    static AccessoireCamouflage* get_camouflage(){
        if(!accessoire_camouflage){
            accessoire_camouflage = new AccessoireCamouflage();
        }
        return accessoire_camouflage;
    }

    void gadgetAction(Bestiole *b);

    void drawGadget(Bestiole *b, UImg &support);


};


#endif //PROJET_BESTIOLES_ACCESSOIRECAMOUFLAGE_H
