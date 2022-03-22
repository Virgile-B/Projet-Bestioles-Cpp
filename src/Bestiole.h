#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include <vector>
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
    double old_vitesse;
    int step_peureuse = 0;
    bool comportement_multiple;
    T *couleur;
    Comportement *comportement;
    Accessoire **accessoire;
    int esperanceVie;
    double gamma_yeux;
    double gamma_ouie;
    double delta_yeux;
    double delta_ouie;
    int pts_vie = 100;
    bool morte = false;
    double camouflage=0;
    int step_accessoire = 0;


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

    bool meurt(Milieu &monMilieu);

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

    double getCamouflage() const{ return this->camouflage;};

    void setCamouflage(double new_camouflage){ this->camouflage = new_camouflage;};

    double getVitesse() { return this->vitesse; };

    void setVitesse(double new_vitesse) { this->vitesse = new_vitesse; };

    T *getCouleur() { return this->couleur; };

    int getPtsVie() { return this->pts_vie; };

    void setPtsVie(int new_pts_vie) { this->pts_vie = new_pts_vie; };

    bool getVie() { return morte; };

    void setVie(bool mort) { this->morte = mort; };

    double getSize(){ return AFF_SIZE;};

    void inverse_orientation(double max_vitesse);

    Accessoire **getAccessoire() { return this->accessoire; };

    void use_accessoires(UImg &support);

    std::string getType();

    int getStepPeureuse() { return this->step_peureuse;};
    void setStepPeureuse(int step){ this->step_peureuse = step;};
    double getOldVitesse(){ return this->old_vitesse;};
    double setOldVitesse(double vitesse){this->old_vitesse = vitesse;};

    double getMAxVitesse(){ return this->MAX_VITESSE;};

    void initTestCoords(double x0,double y0, double  orientation0);

    void setAccessoire(std::vector<std::string> accessoires);

    void setDeltaYeux(double delta){this->delta_yeux = delta;};
    void setDeltaOuie(double delta){this->delta_ouie = delta;};

    void setStepAccessoire(){ this->step_accessoire+=1;};
    int getStepAccessoire(){return this->step_accessoire;};

    void setComportementMultiple(bool multiple){this->comportement_multiple = multiple;};

    };

#endif
