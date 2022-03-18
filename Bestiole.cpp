#include "Bestiole.h"
#include "Milieu.h"
#include <cstdlib>
#include <cmath>

const double      Bestiole::AFF_SIZE = 20.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
int               Bestiole::next = 0;
int               Bestiole::NB_COMPORTEMENT = 4;

float RandomValues(double min, double max) {
    double r = (double) rand() / (double) RAND_MAX;
    return min + r * (max - min);
}

Bestiole::Bestiole(const std::string comportement) {

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par defaut" << endl;
    comportement_multiple = false;
    x = y = 0;
    cumulX = cumulY = 0.;
    vision = static_cast<double>( rand()) / RAND_MAX * M_PI.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
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
    std::cout << gamma_yeux << std::endl;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;
    // commande pour avoir un nombre dans un range: min + ( std::rand() % ( max - min + 1 ) )
    if (comportement == "gregaire") {
        setComportement(0);
    }
    if (comportement == "kamikaze") {
        setComportement(1);
    }
    if (comportement == "peureuse") {
        setComportement(2);
    }
    if (comportement == "prevoyante") {
        setComportement(3);
    }
    if (comportement == "multiple") {
        comportement_multiple = true;
        randomComportement();
    }
    if (comportement == "random") {
        randomComportement();
    }
}

Bestiole::Bestiole() {
    identite = ++next;

    cout << "const Bestiole (" << identite << ") par defaut" << endl;
    comportement_multiple = false;
    std::cout << "tawa" << std::endl;
    x = y = 0;
    std::cout << "tawa" << std::endl;
    cumulX = cumulY = 0.;
    std::cout << "tawa" << std::endl;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    std::cout << "tawa" << std::endl;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;
    std::cout << "tawa" << std::endl;
    randomComportement();
    vision = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    std::cout << "tawa" << std::endl;
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
    std::cout << gamma_yeux << std::endl;
}

void Bestiole::setEsperanceVie() {
    this->esperanceVie = rand() % 100 + 1;
}

void Bestiole::meurt(Milieu &monMilieu) {
    if ((rand() % 100 + 1) > 90) {
        //monMilieu.removeMember(*this);
        //delete(this);
        return;
    }
}

bool Bestiole::changerComportement() {
    if ((rand() % 100 + 1) > 90) {
        randomComportement();
    }
}

void Bestiole::randomComportement() {
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
            this->couleur = this->comportement->get_couleur();;
            break;
        default :
            randomComportement();
            break;
    }
}

Bestiole::Bestiole(const Bestiole &b) {

    identite = ++next;

    cout << "const Bestiole (" << identite << ") par copie" << endl;

    x = b.x;
    y = b.y;
    cumulX = cumulY = 0.;
    orientation = b.orientation;
    vitesse = b.vitesse;
    couleur = b.couleur;
    comportement_multiple = b.comportement_multiple;
    vision = b.vision;
    gamma_yeux = b.gamma_yeux;
    gamma_ouie = b.gamma_ouie;
    delta_yeux = b.delta_yeux;
    delta_ouie = b.delta_ouie;
    std::cout << "x:  " << x << std::endl;
}


void Bestiole::initCoords(int xLim, int yLim) {
    std::cout<< "initCoords" << std::endl;
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
    //this->meurt(monMilieu);
    if (this->estMultiple()) {
        this->changerComportement();
    }
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

const bool Bestiole::estMultiple() {
    return comportement_multiple;
}

bool Bestiole::jeTeVois(const Bestiole &b) const {
    cout << "orientation : "<< orientation << endl;
    cout << "identité : "<< identite<< " x: "<< x << endl;
    cout << "identité : "<< identite<< " y: "<<y << endl;
    // reste a comparer avec camouflage
    double cosinus = cos(orientation / 2);
    double sinus = -sin(orientation / 2);
    if ((0 <= (b.x-x) <= cosinus * delta_yeux) && (0 <= (b.y-y) <= sinus * delta_yeux) && identite != b.identite) { //Faut rajouter aussi le gamma

        cout << "identité : "<< b.identite<< "b.x : "<< b.x << endl;
        cout << "identité : "<< b.identite<< "b.y : "<< b.y << endl;
        cout << "identité : "<< identite<< " x: "<< x << endl;
        cout << "identité : "<< identite<< " y: "<<y << endl;
        cout << "cosinus * delta_yeux : "<< cosinus * delta_yeux << endl;
        cout << "vision : "<< vision << endl;
        //std::cout << "I see you" << std::endl;
        return true;
    } else { return false; }
}


bool Bestiole::jeTentends(const Bestiole &b) const {
    double dist = std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    if (dist <= delta_ouie) {
    //    std::cout << "I hear you" << std::endl;
        return true;
    } else { return false; }
}

void Bestiole::draw_oreilles( UImg & support )//dessiner les oreilles
{
    extern double global_delta_ouie_min;
    extern double global_delta_ouie_max;
    //double xt = x + delta*cos(orientation) * AFF_SIZE / 2;
    //double yt = y - 50*sin(orientation) * AFF_SIZE / 2;
    std::cout << "vision" << vision<< std:: endl;
    vision = 0.5;
    double xx = x+delta_ouie*cos(orientation + vision/2);
    double xx2 = x+delta_ouie*cos(orientation - vision/2);
    double yy = y -50*sin(orientation+vision/2);
    double yy2 = y -50*sin(orientation-vision/2);


    double rayon_oreilles= (AFF_SIZE)*(delta_ouie/(global_delta_ouie_max-global_delta_ouie_min));
    //support.draw_circle(xt+xd,yt+yd,rayon_oreilles,couleur);
    //support.draw_circle(xt-xd,yt-yd,rayon_oreilles,couleur);
    support.draw_line(x, y, xx,yy, couleur );
    support.draw_line(x, y, xx2,yy2, couleur );
    //support.draw_line(x, y, x+50*cos(-orientation / M_PI * 180.),y+50*sin(-orientation / M_PI * 180.), couleur );
    //support.draw_circle(xt-xd,yt-yd,delta_ouie, couleur, 0.5);
}


void Bestiole::draw_yeux( UImg & support )
{
    extern double global_delta_yeux_min;
    extern double global_delta_yeux_max;
    double xt_av_pupille = x + cos(orientation-0.5 ) * AFF_SIZE/1.4;
    double xt_av = x + cos(orientation-0.5 ) * AFF_SIZE/1.8;
    double xt_av2_pupille = x + cos(orientation+0.5 ) * AFF_SIZE/1.4;
    double xt_av2 = x + cos(orientation+0.5 ) * AFF_SIZE/1.8;
    double yt_av = y - sin(orientation-0.5 ) * AFF_SIZE/1.8;
    double yt_av_pupille = y - sin(orientation-0.5 ) * AFF_SIZE/1.8;
    double yt_av2 = y - sin(orientation + 0.5 ) * AFF_SIZE/1.8;
    double yt_av2_pupille = y - sin(orientation + 0.5 ) * AFF_SIZE/1.8;

  //  double xx = -sin(-orientation / M_PI * 180.)*AFF_SIZE/3.5;
  //  double yy = cos(-orientation / M_PI * 180.)*AFF_SIZE/3.5;

    double xx = x+delta_yeux*cos(orientation + vision/2);
    double xx2 = x+delta_yeux*cos(orientation - vision/2);
    double yy = y -delta_yeux*sin(orientation+vision/2);
    double yy2 = y -delta_yeux*sin(orientation-vision/2);

    double cosinus1 = cos(-orientation / M_PI * 180. / 2);
    double sinus1 = -sin(-orientation / M_PI * 180. / 2);
    double cosinus2 = cos(orientation / M_PI * 180. / 2);
    double sinus2 = -sin(orientation / M_PI * 180. / 2);
    int black[3];
    black[0]=0;
    black[1]=0;
    black[2]=0;
    int white[3];
    white[0]=255;
    white[1]=255;
    white[2]=255;
    support.draw_circle(xt_av,yt_av,((AFF_SIZE/4)*(delta_yeux/(global_delta_yeux_max-global_delta_yeux_min))),white);//cercle des oreilles
    support.draw_circle(xt_av2,yt_av2,((AFF_SIZE/4)*(delta_yeux/(global_delta_yeux_max-global_delta_yeux_min))),white);//cercle des oreilles
    support.draw_circle(xt_av_pupille,yt_av_pupille,((AFF_SIZE/4)*(delta_yeux/(global_delta_yeux_max-global_delta_yeux_min)))*0.6,black);//cercle des oreilles
    support.draw_circle(xt_av2_pupille,yt_av2_pupille,((AFF_SIZE/4)*(delta_yeux/(global_delta_yeux_max-global_delta_yeux_min)))*0.6,black);//cercle des oreilles
    //support.draw_line(x, y, xx,yy, couleur );
    //support.draw_line(x, y, xx2,yy2, couleur );
    //support.draw_circle(x,y,((AFF_SIZE/4)*(delta_yeux/(global_delta_yeux_max-global_delta_yeux_min))),black);//cercle des oreilles
    //support.draw_circle(xt_av-xx,yt_av-yy,((AFF_SIZE/4)*(delta_yeux/(global_delta_yeux_max-global_delta_yeux_min))),couleur);//cercle des oreilles
    support.draw_triangle(x, y, xx, yy, xx2, yy2,  couleur, 0.5);
   // support.draw_triangle(xt_av-xx, yt_av-yy, xt_av-xx+cosinus1*delta_yeux, yt_av-yy*sinus1*delta_yeux, xt_av-xx+cosinus2*delta_yeux, yt_av-yy*sinus2*delta_yeux,  couleur, 0.5);

}
