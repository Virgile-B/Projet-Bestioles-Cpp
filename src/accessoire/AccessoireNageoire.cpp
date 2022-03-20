#include "AccessoireNageoire.h"
#include <string>
#include <cstdlib>
#include <cmath>
//#include "../UImg.h"

AccessoireNageoire *AccessoireNageoire::accessoire_nageoire = nullptr;  // Instantiating the Pointer to the singleton

void AccessoireNageoire::gadgetAction(Bestiole* b){
    b->setVitesse(b->getVitesse() * coef_vitesse);
}
void AccessoireNageoire::drawGadget(Bestiole* b, UImg &support){
    double xx = b->getX() + 50* b->getVitesse() * cos(b->get_orientation() + 0.5+ M_PI); //  nageoire angle 30degres
    double xx2 = b->getX() + 50*b->getVitesse() * cos(b->get_orientation() - 0.5+ M_PI);
    double yy = b->getY() - 50*b->getVitesse() * sin(b->get_orientation() + 0.5+ M_PI);
    double yy2 = b->getY() -50* b->getVitesse() * sin(b->get_orientation() - 0.5+ M_PI);

    support.draw_line( b->getX(), b->getY(), xx, yy, b->getCouleur());
    support.draw_line( b->getX(), b->getY(), xx2, yy2, b->getCouleur());
}
