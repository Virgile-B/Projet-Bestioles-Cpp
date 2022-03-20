#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"

#include <iostream>

using namespace std;

class Comportement;
class Accessoire;
class Milieu;


class Bestiole {

private :
    static const double AFF_SIZE;
    static const double MAX_VITESSE;
    static const double LIMITE_VUE;
    static int next;
    static int NB_COMPORTEMENT;

private :
    int identite;
    int x, y;
    double cumulX, cumulY;
    double orientation;
    double vision;
    double vitesse;
    bool comportement_multiple;
    T *couleur;
    Comportement *comportement;
    Accessoire **accessoire;
    int esperanceVie;
    double gamma_yeux;
    double gamma_ouie;
    double delta_yeux;
    double delta_ouie;


private :
    void bouge(int xLim, int yLim);

public :                                           // Forme canonique :
    Bestiole(const std::string comportement);                               // Constructeur par defaut
    Bestiole(const Bestiole &b);                 // Constructeur de copies
    Bestiole();

    ~Bestiole(void) = default;                              // Destructeur
    // Operateur d'affectation binaire par defaut
    void action(Milieu &monMilieu);

    void draw(UImg &support);

    bool jeTeVois(const Bestiole &b) const;

    bool jeTentends(const Bestiole &b) const;

    void initCoords(int xLim, int yLim);

    const bool estMultiple();

    friend bool operator==(const Bestiole &b1, const Bestiole &b2);

    void randomComportement();

    void changerComportement();

    void setComportement(int comprotement);

    void setEsperanceVie();

    bool meurt();

    void draw_oreilles(UImg &support);

    void draw_yeux(UImg &support);

    Bestiole &operator=(const Bestiole &b);

    double get_orientation();

    void set_orientation(double orientation);

    double getX() const { return this->x; };

    double getY() const { return this->y; };

    double get_x() const; // A quoi ca sert ca ?
    double get_y() const; // A quoi ca sert ca ?
    int get_identite() const { return this->identite; };
    double getVitesse() { return this->vitesse;};
    void setVitesse(double new_vitesse) { this->vitesse = new_vitesse;};
    T* getCouleur(){ return this->couleur;};


    void inverse_orientation(Bestiole &b);

    Accessoire **getAccessoire() { return this->accessoire; };

    void use_accessoires(UImg &support);


};
#endif
