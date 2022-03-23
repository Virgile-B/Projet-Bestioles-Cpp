//
// Created by yassine on 20/03/2022.
//

#ifndef PROJET_BESTIOLES_NOACCESSOIRE_H
#define PROJET_BESTIOLES_NOACCESSOIRE_H

#include "Accessoire.h"

/*
 * classe Singleton pour que toutes les bestioles d'une meme simulation partagent les memes accessoires.
 * Classe NoAccessoire pour préciser qu'une bestiole n'a pas d'accessoires
*/
class NoAccessoire : public Accessoire {
    static NoAccessoire *no_accessoire;

    NoAccessoire() {};
public :
    void gadgetAction(Bestiole *b) { return; };

    void drawGadget(Bestiole *b, UImg &support) { return; };

    static NoAccessoire *get_no_accessoire() {
        if (!no_accessoire)
            no_accessoire = new NoAccessoire();
        return no_accessoire;
    }
};


#endif //PROJET_BESTIOLES_NOACCESSOIRE_H
