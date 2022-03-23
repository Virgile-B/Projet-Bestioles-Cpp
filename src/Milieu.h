#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;


class Milieu : public UImg {

private :
    static const T white[];
    int width, height;
    std::vector<Bestiole *> listeBestioles;
    char *type;
    int nbBestioles;
    int nbStep;
    int nbStepMax;

public :
    int nb_peureuse;
    int nb_kamikaze;
    int nb_gregaire;
    int nb_multiple;
    int nb_prevoyante;

    Milieu(int _width, int _height);  // Constructeur milieu

    ~Milieu(void) = default; // Destructeur Milieu

////////////////////////////////////////////// Les getters /////////////////////////////////////////////////////////////
    int getWidth(void) const { return width; };

    int getHeight(void) const { return height; };

    int getNbPeureuse();

    int getNbKamikaze();

    int getNbMultiple();

    int getNbGregaire();

    int getNbPrevoyante();

    std::vector<Bestiole *> getListeBestiole() { return this->listeBestioles; };

    int getNbBestioles();

    char *getType();

////////////////////////////////////////////// Les setters /////////////////////////////////////////////////////////////

    void setNbPeureuse(int nb);

    void setNbKamikaze(int nb);

    void setNbMultiple(int nb);

    void setNbGregaire(int nb);

    void setNbPrevoyante(int nb);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    void step(void);

    void addMember(Bestiole *b);

    void removeMember(Bestiole *b, std::vector<Bestiole *> &toRemove);

    std::vector<Bestiole *> Voisins(const Bestiole &b);

    int nbVoisins(const Bestiole &b);

    void naissance();

    void setSimulation(int nb_peureuse, int nb_prevoyante, int nb_multiple, int nb_gregaire, int nb_kamikaze,
                       int nbStepMax = 100);

    void collision(Bestiole &b);

    void stateSimu(bool save);

};


#endif
