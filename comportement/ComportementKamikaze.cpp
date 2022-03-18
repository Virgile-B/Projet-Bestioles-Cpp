//
// Created by ludo on 06/03/2022.
//

#include "ComportementKamikaze.h"
#include "math.h"
#include <cmath>
#include <iostream>

using namespace std;

ComportementKamikaze *ComportementKamikaze::comportement_kamikaze = nullptr;  // Instantiating the Pointer to the singleton

T* ComportementKamikaze::get_couleur(){
    return ComportementKamikaze::get_kamikaze()->couleur;
}

ComportementKamikaze::ComportementKamikaze(void){
    couleur = new T[ 3 ];
    couleur[ 0 ] = 255;
    couleur[ 1 ] = 0;
    couleur[ 2 ] = 0;
}

void ComportementKamikaze::action(Bestiole *actualBestiole, Milieu &monMilieu){
    std::vector<Bestiole> mesVoisins = monMilieu.Voisins(*actualBestiole);
    if (mesVoisins.size() != 0){
        double x_proche = mesVoisins.front().get_x();
        double y_proche = mesVoisins.front().get_y();
        for ( std::vector<Bestiole>::iterator it = mesVoisins.begin() ; it != mesVoisins.end() ; ++it ){
            double r_proche = std::pow(x_proche - actualBestiole->get_x(),2) + std::pow(y_proche - actualBestiole->get_y(),2);
            double r = std::pow(it->get_x() - actualBestiole->get_x(),2) + std::pow(it->get_y() - actualBestiole->get_y(),2);
            if ( r_proche > r ){
                x_proche = it->get_x();
                y_proche = it->get_y();
            }
        }
        double H = std::sqrt(std::pow(x_proche - actualBestiole->get_x(),2) + std::pow(y_proche - actualBestiole->get_y(),2));
        double h = std::sqrt(std::pow(x_proche - actualBestiole->get_x(),2));
        double theta = -asin(h/H);

        if (actualBestiole->get_y() < y_proche){
            if (actualBestiole->get_x() > x_proche){
                actualBestiole->set_orientation(theta);
            } else {
                actualBestiole->set_orientation(M_PI - theta);
            }
        } else {
            if (actualBestiole->get_x() > x_proche){
                actualBestiole->set_orientation(M_PI + theta);
            } else {
                actualBestiole->set_orientation(-theta);
            }
        }
    }

}
