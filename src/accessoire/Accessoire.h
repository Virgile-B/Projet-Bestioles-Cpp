#ifndef PROJET_BESTIOLES_ACCESSOIRE_H
#define PROJET_BESTIOLES_ACCESSOIRE_H

#include "../UImg.h"
#include "../Milieu.h"

class Bestiole;


class Accessoire {
public:
    virtual void gadgetAction(Bestiole* b) =0;
    virtual void drawGadget(Bestiole* b, UImg &support)=0;
  //public :
    //virtual double getVitesse();
    //Carapace = probabilité mort
    //virtual double getProbDeath();
    //virtual double getCamouflage();
};

#endif
