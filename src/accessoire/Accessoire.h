#ifndef PROJET_BESTIOLES_ACCESSOIRE_H
#define PROJET_BESTIOLES_ACCESSOIRE_H

#include "../UImg.h"
#include "../Milieu.h"

class Bestiole;

/*
 * Interface Accessoire qui sera appelée par Bestiole
 */
class Accessoire {
public:
    // méthode abstraite pour activer l'accessoire
    virtual void gadgetAction(Bestiole *b) = 0;

    // méthode abstraite pour dessiner l'accessoire
    virtual void drawGadget(Bestiole *b, UImg &support) = 0;
};

#endif
