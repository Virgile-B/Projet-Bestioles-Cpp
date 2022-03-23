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
    int step_comportement = 0;
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
    double camouflage = 0;
    int step_accessoire = 0;


private :
    void bouge(int xLim, int yLim);

public :
    Bestiole(const std::string comportement);    // Constructeur
    Bestiole(const Bestiole &b);                 // Constructeur par copies
    Bestiole();                                  // Constructeur par défaut

    ~Bestiole(void) = default;                  // Destructeur


////////////////////////////////////////////// Les getters /////////////////////////////////////////////////////////////

    int get_identite() const { return this->identite; };

    double getX() const { return this->x; };

    double getY() const { return this->y; };

    double get_orientation() { return this->orientation;};

    double get_x() const { return this->x + this->cumulX;};

    double get_y() const { return this->y + this->cumulY;};

    double getVitesse() { return this->vitesse; };

    double getOldVitesse() { return this->old_vitesse; };

    int getStepComportement() { return this->step_comportement; };

    double getCamouflage() const { return this->camouflage; };

    double getMAxVitesse() { return this->MAX_VITESSE; };

    int getStepAccessoire() { return this->step_accessoire; };

    double getSize() { return AFF_SIZE; }; // Pour récupérer la taille de la bestiole

    int getPtsVie() { return this->pts_vie; };

    T *getCouleur() { return this->couleur; };

    bool getVie() { return morte; };

    void setComportement(int comprotement);

    void setEsperanceVie();

    std::string getType();

    Accessoire **getAccessoire() { return this->accessoire; };


///////////////////////////////////////////// Les setters //////////////////////////////////////////////////////////////

    void set_orientation(double orientation) { this->orientation = orientation; };

    void setCamouflage(double new_camouflage) { this->camouflage = new_camouflage; };

    void setVitesse(double new_vitesse) { this->vitesse = new_vitesse; };

    void setPtsVie(int new_pts_vie) { this->pts_vie = new_pts_vie; };

    void setVie(bool mort) { this->morte = mort; };

    void setStepComportement(int step) { this->step_comportement = step; };

    void setOldVitesse(double vitesse) { this->old_vitesse = vitesse; };

    void setAccessoire(std::vector <std::string> accessoires);

    void setDeltaYeux(double delta) { this->delta_yeux = delta; };

    void setDeltaOuie(double delta) { this->delta_ouie = delta; };

    void setStepAccessoire() { this->step_accessoire += 1; };

    void setComportementMultiple(bool multiple) { this->comportement_multiple = multiple; };

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    friend bool operator==(const Bestiole &b1, const Bestiole &b2);

    Bestiole &operator=(const Bestiole &b); // Operateur d'affectation binaire par defaut

    void action(Milieu &monMilieu);

    void draw(UImg &support);

    bool jeTeVois(const Bestiole &b) const;

    bool jeTentends(const Bestiole &b) const;

    void initCoords(int xLim, int yLim);

    const bool estMultiple();

    void randomComportement();

    void changerComportement();

    bool meurt();

    void draw_oreilles(UImg &support);

    void draw_yeux(UImg &support);

    void inverse_orientation(double max_vitesse);

    void use_accessoires(UImg &support);

    void initTestCoords(double x0, double y0, double orientation0);

};

#endif
