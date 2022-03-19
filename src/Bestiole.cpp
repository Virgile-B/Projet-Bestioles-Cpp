#include "Bestiole.h"
#include "Milieu.h"
#include <cstdlib>
#include <cmath>

#include "comportement/Comportement.h"
#include "comportement/ComportementGregaire.h"
#include "comportement/ComportementKamikaze.h"
#include "comportement/ComportementPeureuse.h"
#include "comportement/ComportementPrevoyante.h"


const double      Bestiole::AFF_SIZE = 20.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
int               Bestiole::next = 0;
int               Bestiole::NB_COMPORTEMENT = 5;

float RandomValues(double min, double max) {
    double r = (double) rand() / (double) RAND_MAX;
    return min + r * (max - min);
}

bool estDedans(double x, double x1, double x2){
    if ((x1 <= x && x <= x2) || (x1 >= x && x >= x2)){
        return true;
    }
    else{
        return false;
    }
}

Bestiole::Bestiole(const std::string comportement)
{

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par defaut" << endl;
    comportement_multiple = false;
    x = y = 0;
    cumulX = cumulY = 0.;
    vision = static_cast<double>( rand()) / RAND_MAX * M_PI;
    orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
    extern double global_gamma_yeux_min;
    extern double global_gamma_yeux_max;
    extern double global_gamma_ouie_min;
    extern double global_gamma_ouie_max;
    extern double global_delta_yeux_min;
    extern double global_delta_yeux_max;
    extern double global_delta_ouie_min;
    extern double global_delta_ouie_max;
    gamma_yeux = RandomValues(global_gamma_yeux_min, global_gamma_yeux_max);
    gamma_ouie = RandomValues(global_gamma_ouie_min, global_gamma_ouie_max);
    delta_yeux = RandomValues(global_delta_yeux_min, global_delta_yeux_max);
    delta_ouie = RandomValues(global_delta_ouie_min, global_delta_ouie_max);
    vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
    if (comportement == "gregaire"){
        setComportement(0);
    }
    if (comportement == "kamikaze"){
        setComportement(1);
    }
    if (comportement == "peureuse"){
        setComportement(2);
    }
    if (comportement == "prevoyante"){
        setComportement(3);
    }
    if (comportement == "multiple"){
        comportement_multiple = true;
        randomComportement();
    }
    if (comportement == "random"){
        randomComportement();
    }
}

Bestiole::Bestiole() {
    identite = ++next;

    cout << "const Bestiole (" << identite << ") par defaut" << endl;
    comportement_multiple = false;
    x = y = 0;
    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;
    randomComportement();
    vision = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    extern double global_gamma_yeux_min;
    extern double global_gamma_yeux_max;
    extern double global_gamma_ouie_min;
    extern double global_gamma_ouie_max;
    extern double global_delta_yeux_min;
    extern double global_delta_yeux_max;
    extern double global_delta_ouie_min;
    extern double global_delta_ouie_max;
    gamma_yeux = RandomValues(global_gamma_yeux_min, global_gamma_yeux_max);
    gamma_ouie = RandomValues(global_gamma_ouie_min, global_gamma_ouie_max);
    delta_yeux = RandomValues(global_delta_yeux_min, global_delta_yeux_max);
    delta_ouie = RandomValues(global_delta_ouie_min, global_delta_ouie_max);
}
void Bestiole::setEsperanceVie(){
    this->esperanceVie = rand() % 100 + 1;
}

bool Bestiole::meurt() {
    if ((rand() % 100 + 1) > 99) {
        return true;
    }
    return false;
}

void Bestiole::changerComportement() {
    if( (rand() % 100+1) > 90) {
        randomComportement();
    }
}
void Bestiole::randomComportement(){
    setComportement(rand() % NB_COMPORTEMENT);
}

void Bestiole::setComportement(int comportement) {
    switch (comportement) {
        case 0:
            this->comportement = ComportementGregaire::get_gregaire();
            this->couleur = this->comportement->get_couleur();
            break;
        case 1:
            this->comportement = ComportementKamikaze::get_kamikaze();
            this->couleur = this->comportement->get_couleur();
            break;
        case 2:
            this->comportement = ComportementPeureuse::get_peureuse();
            this->couleur = this->comportement->get_couleur();
            break;
        case 3:
            this->comportement = ComportementPrevoyante::get_prevoyante();
            break;
        case 4:
            if (!this->estMultiple()) {
                this->comportement_multiple = true;
            }
            randomComportement();
            break;
        default :
            randomComportement();
            break;
    }
}

Bestiole::Bestiole(const Bestiole &b) {
    identite = b.identite;
    cout << "const Bestiole (" << identite << ") par copie" << endl;

    x = b.x;
    y = b.y;
    cumulX = b.cumulX;
    cumulY = b.cumulY;
    orientation = b.orientation;
    vitesse = b.vitesse;
    couleur = b.couleur;
    comportement_multiple = b.comportement_multiple;
    comportement = b.comportement;
    vision = b.vision;
    gamma_yeux = b.gamma_yeux;
    gamma_ouie = b.gamma_ouie;
    delta_yeux = b.delta_yeux;
    delta_ouie = b.delta_ouie;
}


void Bestiole::initCoords(int xLim, int yLim) {

    x = rand() % xLim;
    y = rand() % yLim;

}


void Bestiole::bouge(int xLim, int yLim) {

    double nx, ny;
    double dx = cos(orientation) * vitesse;
    double dy = -sin(orientation) * vitesse;
    int cx, cy;


    cx = static_cast<int>( cumulX );
    cumulX -= cx;
    cy = static_cast<int>( cumulY );
    cumulY -= cy;

    nx = x + dx + cx;
    ny = y + dy + cy;

    if ((nx < 0) || (nx > xLim - 1)) {
        orientation = M_PI - orientation;
        cumulX = 0.;
    } else {
        x = static_cast<int>( nx );
        cumulX += nx - x;
    }

    if ((ny < 0) || (ny > yLim - 1)) {
        orientation = -orientation;
        cumulY = 0.;
    } else {
        y = static_cast<int>( ny );
        cumulY += ny - y;
    }

}


void Bestiole::action(Milieu &monMilieu) {
    if (this->estMultiple()) {
        this->changerComportement();
    }
    comportement->action(this,monMilieu);
    bouge(monMilieu.getWidth(), monMilieu.getHeight());

}

void Bestiole::draw(UImg &support) {

    double xt = x + cos(orientation) * AFF_SIZE / 2.1;
    double yt = y - sin(orientation) * AFF_SIZE / 2.1;


    support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., couleur);
    support.draw_circle(xt, yt, AFF_SIZE / 2., couleur);

}


bool operator==(const Bestiole &b1, const Bestiole &b2) {

    return (b1.identite == b2.identite);

}

Bestiole &Bestiole::operator=(const Bestiole &b) {
    if (this == &b) {
        return *this;
    }
    this->identite = b.identite;
    this->x = b.x;
    this->y = b.y;
    this->cumulX = b.cumulX;
    this->cumulY = b.cumulY;
    this->orientation = b.orientation;
    this->vitesse = b.vitesse;
    this->comportement_multiple = b.comportement_multiple;
    this->comportement = b.comportement;
    return *this;
}

const bool Bestiole::estMultiple()
{
    return comportement_multiple;
}
bool Bestiole::jeTeVois( const Bestiole & b ) const
{


    double xx = x + delta_yeux * cos(orientation + vision / 2);
    double xx2 = x + delta_yeux * cos(orientation - vision / 2);
    double yy = y - delta_yeux * sin(orientation + vision / 2);
    double yy2 = y - delta_yeux * sin(orientation - vision / 2);
    if (estDedans(b.x, xx, xx2) && estDedans(b.y, yy, yy2) && this != &b){
        return true;
    } else { return false; }
}


bool Bestiole::jeTentends(const Bestiole &b) const {
    if (this == &b) {
        return false;
    }
    double dist = std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    if (dist <= delta_ouie) {
        return true;
    } else { return false; }
}

void Bestiole::draw_oreilles(UImg &support)//dessiner les oreilles
{
    extern double global_delta_ouie_min;
    extern double global_delta_ouie_max;
    double xt_av = x + cos(orientation + 0.8) * AFF_SIZE / 1.8;
    double xt_av2 = x + cos(orientation - 0.8) * AFF_SIZE / 1.8;
    double yt_av = y - sin(orientation + 0.8) * AFF_SIZE / 1.8;
    double yt_av2 = y - sin(orientation - 0.8) * AFF_SIZE / 1.8;
    double rayon_oreilles = (AFF_SIZE) * (delta_ouie / (global_delta_ouie_max - global_delta_ouie_min));
    support.draw_ellipse(xt_av, yt_av, rayon_oreilles / 6, rayon_oreilles / 3, -orientation / M_PI * 180., couleur);
    support.draw_ellipse(xt_av2, yt_av2, rayon_oreilles / 6, rayon_oreilles / 3, -orientation / M_PI * 180., couleur);
    support.draw_circle(x, y, delta_ouie, couleur, 0.2);
}

double Bestiole::get_orientation() {return this->orientation;}
void Bestiole::set_orientation(double orientation) {this->orientation = orientation;}
double Bestiole::get_x() const {return this->x + this->cumulX;}
double Bestiole::get_y() const {return this->y + this->cumulY;}

void Bestiole::draw_yeux(UImg &support) {
    extern double global_delta_yeux_min;
    extern double global_delta_yeux_max;
    double xt_av_pupille = x + cos(orientation - 0.5) * AFF_SIZE / 1.4;
    double xt_av = x + cos(orientation - 0.5) * AFF_SIZE / 1.8;
    double xt_av2_pupille = x + cos(orientation + 0.5) * AFF_SIZE / 1.4;
    double xt_av2 = x + cos(orientation + 0.5) * AFF_SIZE / 1.8;
    double yt_av = y - sin(orientation - 0.5) * AFF_SIZE / 1.8;
    double yt_av_pupille = y - sin(orientation - 0.5) * AFF_SIZE / 1.8;
    double yt_av2 = y - sin(orientation + 0.5) * AFF_SIZE / 1.8;
    double yt_av2_pupille = y - sin(orientation + 0.5) * AFF_SIZE / 1.8;

    double xx = x + delta_yeux * cos(orientation + vision / 2);
    double xx2 = x + delta_yeux * cos(orientation - vision / 2);
    double yy = y - delta_yeux * sin(orientation + vision / 2);
    double yy2 = y - delta_yeux * sin(orientation - vision / 2);

    int black[3];
    black[0] = 0;
    black[1] = 0;
    black[2] = 0;
    int white[3];
    white[0] = 255;
    white[1] = 255;
    white[2] = 255;
    double centre_rayon_x = min(xx, xx2) + abs(xx-xx2)/2;
    double centre_rayon_y = min(yy, yy2) + abs(yy-yy2)/2;
    double rayon = std::sqrt((centre_rayon_x - xx) * (centre_rayon_x - xx) + (centre_rayon_y - yy) * (centre_rayon_y - yy));
    support.draw_circle(xt_av, yt_av, ((AFF_SIZE / 4) * (delta_yeux / (global_delta_yeux_max - global_delta_yeux_min))),
                        white);//cercle des oreilles
    support.draw_circle(xt_av2, yt_av2,
                        ((AFF_SIZE / 4) * (delta_yeux / (global_delta_yeux_max - global_delta_yeux_min))),
                        white);//cercle des oreilles
    support.draw_circle(xt_av_pupille, yt_av_pupille,
                        ((AFF_SIZE / 4) * (delta_yeux / (global_delta_yeux_max - global_delta_yeux_min))) * 0.6,
                        black);//cercle des oreilles
    support.draw_circle(xt_av2_pupille, yt_av2_pupille,
                        ((AFF_SIZE / 4) * (delta_yeux / (global_delta_yeux_max - global_delta_yeux_min))) * 0.6,
                        black);//cercle des oreilles
    support.draw_triangle(x, y, xx, yy, xx2, yy2, couleur, 0.3);
    support.draw_circle(centre_rayon_x, centre_rayon_y, rayon, couleur, 0.05);
}

void Bestiole::inverse_orientation(Bestiole& b){
    b.orientation =  M_PI - b.orientation;
    orientation =  M_PI - orientation;
}
