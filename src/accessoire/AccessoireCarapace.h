//
// Created by yassine on 21/03/2022.
//

#ifndef PROJET_BESTIOLES_ACCESSOIRCARAPACE_H
#define PROJET_BESTIOLES_ACCESSOIRCARAPACE_H
#include "Accessoire.h"
#include <string>
#include <iostream>

class Bestiole;


class AccessoireCarapace: public Accessoire {
    static AccessoireCarapace *accessoire_carapace;
    AccessoireCarapace(){
        // extern double global_coef_carapace_max; // NE PAS OUBLIER CA
        // extern double global_coef_ralentissement_max; // NE PAS OUBLIER CA
        double global_coef_carapace_max = 3.;
        double global_coef_ralentissement_max = 5.;

        coef_carapace = 1 + rand() / RAND_MAX * (global_coef_carapace_max-1);
        coef_ralentissement = 1 + rand() / RAND_MAX * (global_coef_ralentissement_max-1);
    };
public:
    double coef_carapace;
    double coef_ralentissement;

    static AccessoireCarapace *get_carapace(){
        if(!accessoire_carapace){
            accessoire_carapace = new AccessoireCarapace() ;
        }
        return accessoire_carapace;
    };

    void gadgetAction(Bestiole *b);

    void drawGadget(Bestiole *b, UImg &support);

};


#endif //PROJET_BESTIOLES_ACCESSOIRCARAPACE_H
