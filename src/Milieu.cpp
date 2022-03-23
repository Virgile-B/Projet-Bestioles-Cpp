#include "Milieu.h"
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <fstream>

const T    Milieu::white[] = {(T) 255, (T) 255, (T) 255};

Milieu::Milieu(int _width, int _height) : UImg(_width, _height, 1, 3),
                                          width(_width), height(_height) {
    cout << "const Milieu" << endl;
    nbStep = 0;
}

void Milieu::step(void) {
    nbStep = nbStep + 1;
    //nbStepMax défini par l'utilisateur
    if (nbStep <= nbStepMax) {
        cimg_forXY(*this, x, y)
        fillC(x, y, 0, white[0], white[1], white[2]);
        // On commence par faire naitre les bestiole selon la probabilité de naissance définie dans le main
        this->naissance();
        // Liste dont laquelle nous mettrons les bestioles mortes dans chaque step
        std::vector < Bestiole * > toRemove;
        if (listeBestioles.size() != 0) {
            // D'abord, on parcourt toutes les bestioles pour que chacune bouge
            for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
                if (!((*it)->meurt() || (*it)->getVie())) {  // Tant que la bestiole n'est pas morte a encore des pts de vie
                    (*it)->action(*this);
                    (*it)->draw(*this); // dessin de la bestiole
                    (*it)->draw_oreilles(*this);
                    (*it)->draw_yeux(*this);
                    (*it)->use_accessoires(*this);
                }
            }
            // Deuxième itération pour savoir s'il y a collision entre deux bestioles
            for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
                this->collision(*(*it));
                if ((*it)->meurt() || (*it)->getVie()) {
                    removeMember(*it, toRemove);
                }
                nbBestioles = listeBestioles.size();
            }
            if (!(toRemove.empty())) {
                // Enlever toutes les bestioles qui sont dans la liste toRemove
                for (std::vector<Bestiole *>::iterator it = toRemove.begin(); it != toRemove.end(); ++it) {
                    listeBestioles.erase(std::remove(listeBestioles.begin(), listeBestioles.end(), *it),
                                         listeBestioles.end());
                    (*it)->~Bestiole();
                }
            }
        }
    } else {
        system("clear");
        std::cout << "Simulation terminée" << std::endl;
        std::exit;
    }
}

// Méthode pour récupérer un vecteur contenant tous les voisins de la bestiole b
std::vector<Bestiole *> Milieu::Voisins(const Bestiole &b) {
    std::vector < Bestiole * > listeVoisins;
    for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if (b.get_identite() != (*it)->get_identite() && (b.jeTeVois(*(*it)) || b.jeTentends(*(*it)))) {
            Bestiole *point_b = *it;
            listeVoisins.push_back(point_b);
        }
    }
    return listeVoisins;
}

void Milieu::addMember(Bestiole *b) {
    extern std::string test;
    listeBestioles.push_back(b);
    if (test.compare("yes") != 0) {
        listeBestioles.back()->initCoords(width, height);
    }
}


void Milieu::naissance() {
    extern int PROBA_NAISSANCE;
    if (nb_peureuse != 0) {
        if ((std::rand() % 100 + 1) > 100 - PROBA_NAISSANCE) {
            Bestiole *ptr_bestiole = new Bestiole("peureuse");
            addMember(ptr_bestiole);
        }
    }
    if (nb_prevoyante != 0) {
        if ((std::rand() % 100 + 1) > 100 - PROBA_NAISSANCE) {
            Bestiole *ptr_bestiole = new Bestiole("prevoyante");
            addMember(ptr_bestiole);
        }
    }
    if (nb_gregaire != 0) {
        if ((std::rand() % 100 + 1) > 100 - PROBA_NAISSANCE) {
            Bestiole *ptr_bestiole = new Bestiole("gregaire");
            addMember(ptr_bestiole);
        }
    }
    if (nb_kamikaze != 0) {
        if ((std::rand() % 100 + 1) > 100 - PROBA_NAISSANCE) {
            Bestiole *ptr_bestiole = new Bestiole("kamikaze");
            addMember(ptr_bestiole);
        }
    }
    if (nb_multiple != 0) {
        if ((std::rand() % 100 + 1) > 100 - PROBA_NAISSANCE) {
            Bestiole *ptr_bestiole = new Bestiole("multiple");
            addMember(ptr_bestiole);
        }
    }
    nbBestioles = listeBestioles.size();
}

void Milieu::removeMember(Bestiole *b, std::vector<Bestiole *> &toRemove) {
    toRemove.push_back(b);
}

void Milieu::setSimulation(int nb_peureuse, int nb_prevoyante, int nb_multiple, int nb_gregaire, int nb_kamikaze,
                           int nbStepMax) {
    this->nb_peureuse = nb_peureuse;
    this->nb_prevoyante = nb_prevoyante;
    this->nb_multiple = nb_multiple;
    this->nb_gregaire = nb_gregaire;
    this->nb_kamikaze = nb_kamikaze;
    this->nbStepMax = nbStepMax;
}

char *Milieu::getType() {
    return this->type;
}

int Milieu::getNbBestioles() {
    return this->nbBestioles;
}

// Méthode collision: Si deux bestioles se rentrent dedans, leur orientation s'inversent et leurs points de vie baissera
// en fonction de leur vitesse
void Milieu::collision(Bestiole &b) {
    for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if (std::sqrt(((*it)->getX() - b.getX()) * ((*it)->getX() - b.getX()) +
                      ((*it)->getY() - b.getY()) * ((*it)->getY() - b.getY())) < (b.getSize()) &&
            b.get_identite() != (*it)->get_identite()) {
            double max_vitesse = (b.getVitesse() >= (*it)->getVitesse()) ? b.getVitesse() : (*it)->getVitesse();
            b.inverse_orientation(max_vitesse);
        }
    }
}

void Milieu::setNbPeureuse(int nb) {
    this->nb_peureuse = nb;
}

void Milieu::setNbKamikaze(int nb) {
    this->nb_kamikaze = nb;
}

void Milieu::setNbMultiple(int nb) {
    this->nb_multiple = nb;
}

void Milieu::setNbGregaire(int nb) {
    this->nb_gregaire = nb;
}

void Milieu::setNbPrevoyante(int nb) {
    this->nb_prevoyante = nb;
}

int Milieu::getNbPeureuse() {
    int compteur = 0;
    for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if ((*it)->getType() == "peureuse") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}

int Milieu::getNbKamikaze() {
    int compteur = 0;
    for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if ((*it)->getType() == "kamikaze") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}

int Milieu::getNbMultiple() {
    int compteur = 0;
    for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if ((*it)->estMultiple()) {
            compteur = compteur + 1;
        }
    }
    return compteur;
}

int Milieu::getNbGregaire() {
    int compteur = 0;
    for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if ((*it)->getType() == "gregaire") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}

int Milieu::getNbPrevoyante() {
    int compteur = 0;
    for (std::vector<Bestiole *>::iterator it = listeBestioles.begin(); it != listeBestioles.end(); ++it) {
        if ((*it)->getType() == "prevoyante") {
            compteur = compteur + 1;
        }
    }
    return compteur;
}

// Méthode d'affichage et enregistrement des stats lors du run du main
void Milieu::stateSimu(bool save) {
    system("clear");
    std::cout << "######################" << std::endl;
    std::cout << "Etat de la simulation  " << std::endl;
    std::cout << "######################" << std::endl;
    std::cout << "Step -> " << nbStep << std::endl;
    std::cout << "Nombre total de bestioles : " << listeBestioles.size() << std::endl;
    std::cout << "Nb prevoyantes initial : " << getNbPrevoyante() << "-" << nb_prevoyante << std::endl;
    std::cout << "Nb gregaires courrant - initial : " << getNbGregaire() << "-" << nb_gregaire << std::endl;
    std::cout << "Nb kamikazes courrant - initial : " << getNbKamikaze() << "-" << nb_kamikaze << std::endl;
    std::cout << "Nb multiples courrant - initial : " << getNbMultiple() << "-" << nb_multiple << std::endl;
    std::cout << "Nb peureuses courrant - initial : " << getNbPeureuse() << "-" << nb_peureuse << std::endl;
    std::cout << "######################" << std::endl;
    if (nbStep == nbStepMax || save) {
        std::cout << "Simulation courrante enregistrée : simulation_out.txt " << std::endl;
        ofstream out;
        out.open("simulation_out.txt");
        out << "######################" << std::endl;
        out << "Etat de la simulation  " << std::endl;
        out << "######################" << std::endl;
        out << "Step -> " << nbStep << std::endl;
        out << "Nombre total de bestioles : " << listeBestioles.size() << std::endl;
        out << "Nb prevoyantes courrant - initial : " << getNbPrevoyante() << "-" << nb_prevoyante << std::endl;
        out << "Nb gregaires courrant - initial : " << getNbGregaire() << "-" << nb_gregaire << std::endl;
        out << "Nb kamikazes courrant - initial : " << getNbKamikaze() << "-" << nb_kamikaze << std::endl;
        out << "Nb multiples courrant - initial : " << getNbMultiple() << "-" << nb_multiple << std::endl;
        out << "Nb peureuses courrant - initial : " << getNbPeureuse() << "-" << nb_peureuse << std::endl;
        out << "######################" << std::endl;
        out.close();
    }
}