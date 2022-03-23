#include "AccessoireNageoire.h"
#include <string>
#include <cstdlib>
#include <cmath>

AccessoireNageoire *AccessoireNageoire::accessoire_nageoire = nullptr;  // Initilisation du pointeur sur le singleton

void AccessoireNageoire::gadgetAction(Bestiole *b) {
    if (b->getStepAccessoire() == 0) { // Pour ne multiplier qu'une seule fois la vitesse par coef_vitesse
        if (b->getVitesse() * coef_vitesse > 10) {
            b->setVitesse(10);
            b->setOldVitesse(10); // Pour la peureuse
        } else {
            b->setVitesse(b->getVitesse() * coef_vitesse);
            b->setOldVitesse(b->getVitesse() * coef_vitesse); // Pour la peureuse
        }
    }
    b->setStepAccessoire();
}

void AccessoireNageoire::drawGadget(Bestiole *b, UImg &support) {
    // Positions pour tracer les nageoires
    double xx = b->getX() + 8 * b->getVitesse() * cos(b->get_orientation() + 0.5 + M_PI); // nageoire angle 30degres
    double xx2 = b->getX() + 8 * b->getVitesse() * cos(b->get_orientation() - 0.5 + M_PI);
    double yy = b->getY() - 8 * b->getVitesse() * sin(b->get_orientation() + 0.5 + M_PI);
    double yy2 = b->getY() - 8 * b->getVitesse() * sin(b->get_orientation() - 0.5 + M_PI);

    // Dessin des nageoires
    support.draw_line(b->getX(), b->getY(), xx, yy, b->getCouleur());
    support.draw_line(b->getX(), b->getY(), xx2, yy2, b->getCouleur());
}
