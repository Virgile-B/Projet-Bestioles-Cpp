//
// Created by yassine on 21/03/2022.
//

#include "AccessoireCarapace.h"
#include <string>
#include <cstdlib>
#include <cmath>

AccessoireCarapace *AccessoireCarapace::accessoire_carapace = nullptr;

void AccessoireCarapace::gadgetAction(Bestiole *b) {
    if (b->getStepAccessoire()==0){
        cout<<"old_vie "<<b->getPtsVie()<<endl;
        b->setPtsVie(coef_carapace * (b->getPtsVie()));
        cout<<"coef carapace "<<coef_carapace<<endl;
        b->setVitesse((b->getVitesse()) / coef_ralentissement);
        cout<<"new_vie "<<b->getPtsVie()<<endl;
    }
    b->setStepAccessoire();
}

void AccessoireCarapace::drawGadget(Bestiole *b, UImg &support) {
    int* couleur= new int[3];
    couleur[0] = 0;
    couleur[1] = 0;
    couleur[2] = 0;
    double xx = b->getX() + 1.3 * b->getSize() * cos(b->get_orientation() + 0.5);
    double xx2 = b->getX() + 1.3 * b->getSize() * cos(b->get_orientation() - 0.5);
    double yy =  b->getY()- 1.3 * b->getSize() * sin(b->get_orientation() + 0.5);
    double yy2 =  b->getY() - 1.3 * b->getSize() * sin(b->get_orientation() - 0.5);
    double centre_rayon_x = min(xx, xx2) + abs(xx - xx2) / 2;
    double centre_rayon_y = min(yy, yy2) + abs(yy - yy2) / 2;
    // dessin du shield dont l'opacite depend des points de vie
    support.draw_ellipse(centre_rayon_x, centre_rayon_y, 1.5 * b->getSize(), b->getSize() / 5.,
                         -b->get_orientation() / M_PI * 180. + 90, couleur, min(b->getPtsVie() / 100., 0.5));

}