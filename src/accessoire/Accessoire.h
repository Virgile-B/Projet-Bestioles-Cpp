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
    virtual void gadgetAction(Bestiole* b) =0;
    virtual void drawGadget(Bestiole* b, UImg &support)=0;
};

#endif
