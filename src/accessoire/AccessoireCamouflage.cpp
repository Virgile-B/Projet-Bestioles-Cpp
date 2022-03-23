//
// Created by yassine on 21/03/2022.
//
#include <string>
#include <cstdlib>
#include <cmath>
#include "AccessoireCamouflage.h"

AccessoireCamouflage *AccessoireCamouflage::accessoire_camouflage = nullptr; // Initilisation du pointeur sur le singleton

void AccessoireCamouflage::gadgetAction(Bestiole *b) {
    b->setCamouflage(get_camouflage()->coef_camouflage);
}

void AccessoireCamouflage::drawGadget(Bestiole *b, UImg &support) {
    double x = b->getX(); // abscisse de la bestiole b
    double y = b->getY(); // ordonnée de la bestiole b
    double orientation = b->get_orientation(); // orientation de la bestiole b
    double AFF_SIZE = b->getSize(); // Taille de la bestiole b
    double delta = 2.5 * coef_camouflage; // taille du camouflage

    // Dessin des yeux rouges pour camouflage
    double xt_av_pupille = x + cos(orientation - 0.5) * AFF_SIZE / 1.4;
    double xt_av = x + cos(orientation - 0.5) * AFF_SIZE / 1.8;
    double xt_av2_pupille = x + cos(orientation + 0.5) * AFF_SIZE / 1.4;
    double xt_av2 = x + cos(orientation + 0.5) * AFF_SIZE / 1.8;
    double yt_av = y - sin(orientation - 0.5) * AFF_SIZE / 1.8;
    double yt_av_pupille = y - sin(orientation - 0.5) * AFF_SIZE / 1.8;
    double yt_av2 = y - sin(orientation + 0.5) * AFF_SIZE / 1.8;
    double yt_av2_pupille = y - sin(orientation + 0.5) * AFF_SIZE / 1.8;

    // Couleur du masque
    int black[3];
    black[0] = 0;
    black[1] = 0;
    black[2] = 0;

    //Couleur des yeux
    int red[3];
    red[0] = 255;
    red[1] = 0;
    red[2] = 0;

    // dessin utilisant CImg.h
    support.draw_circle(xt_av, yt_av, ((AFF_SIZE / 4) * delta),
                        black);
    support.draw_circle(xt_av2, yt_av2,
                        ((AFF_SIZE / 4) * delta),
                        black);
    support.draw_circle(xt_av_pupille, yt_av_pupille,
                        ((AFF_SIZE / 4) * delta) * 0.4,
                        red);
    support.draw_circle(xt_av2_pupille, yt_av2_pupille,
                        ((AFF_SIZE / 4) * delta) * 0.4,
                        red);
}