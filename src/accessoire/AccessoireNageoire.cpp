#include "AccessoireNageoire.h"
#include <string>
#include <cstdlib>
#include <cmath>

AccessoireNageoire *AccessoireNageoire::accessoire_nageoire = nullptr;  // Instantiating the Pointer to the singleton

void AccessoireNageoire::gadgetAction(Bestiole* b){
    if( b->getStepAccessoire()==0){
        if (b->getVitesse() * coef_vitesse>10){
            b->setVitesse(10);
            b->setOldVitesse(10); // pour la peureuse
        }else {
            b->setVitesse(b->getVitesse() * coef_vitesse);
            b->setOldVitesse(b->getVitesse() * coef_vitesse); // pour la peureuse
        }
    }
    b->setStepAccessoire();
}
void AccessoireNageoire::drawGadget(Bestiole* b, UImg &support){
    double xx = b->getX() + 50* b->getVitesse() * cos(b->get_orientation() + 0.5+ M_PI); //  nageoire angle 30degres
    double xx2 = b->getX() + 50*b->getVitesse() * cos(b->get_orientation() - 0.5+ M_PI);
    double yy = b->getY() - 50*b->getVitesse() * sin(b->get_orientation() + 0.5+ M_PI);
    double yy2 = b->getY() -50* b->getVitesse() * sin(b->get_orientation() - 0.5+ M_PI);

    support.draw_line( b->getX(), b->getY(), xx, yy, b->getCouleur());
    support.draw_line( b->getX(), b->getY(), xx2, yy2, b->getCouleur());
}
