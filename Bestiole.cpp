#include "Bestiole.h"
#include "Milieu.h"
#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
int               Bestiole::next = 0;
int               Bestiole::NB_COMPORTEMENT = 5;

Bestiole::Bestiole(const std::string comportement) {
    identite = ++next;
    cout << "const Bestiole (" << identite << ") par defaut" << endl;
    comportement_multiple = false;
    x = y = 0;
    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;
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
    x = y = 0;
    cumulX = cumulY = 0.;
    orientation = static_cast<double>( rand()) / RAND_MAX * 2. * M_PI;
    vitesse = static_cast<double>( rand()) / RAND_MAX * MAX_VITESSE;
    randomComportement();
}

bool Bestiole::meurt() {
    if ((rand() % 100 + 1) > 99) {
        return true;
    }
    return false;
}

void Bestiole::changerComportement() {
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
            break;
        case 1:
            this->comportement = ComportementKamikaze::get_kamikaze();
            break;
        case 2:
            this->comportement = ComportementPeureuse::get_peureuse();
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
    comportement_multiple = b.comportement_multiple;
    comportement = b.comportement;
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
    bouge(monMilieu.getWidth(), monMilieu.getHeight());
}

void Bestiole::draw(UImg &support) {

    double xt = x + cos(orientation) * AFF_SIZE / 2.1;
    double yt = y - sin(orientation) * AFF_SIZE / 2.1;

    support.draw_ellipse(x, y, AFF_SIZE, AFF_SIZE / 5., -orientation / M_PI * 180., this->comportement->get_couleur());
    support.draw_circle(xt, yt, AFF_SIZE / 2., this->comportement->get_couleur());

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

const bool Bestiole::estMultiple() {
    return comportement_multiple;
}

bool Bestiole::jeTeVois(const Bestiole &b) const {

    double dist;
    dist = std::sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
    return (dist <= LIMITE_VUE);

}