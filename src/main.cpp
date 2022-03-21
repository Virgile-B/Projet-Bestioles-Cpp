#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <iostream>



double global_gamma_yeux_min;
double global_gamma_yeux_max;
double global_gamma_ouie_min;
double global_gamma_ouie_max;
double global_delta_yeux_min;
double global_delta_yeux_max;
double global_delta_ouie_min;
double global_delta_ouie_max;
int nbPeureuse;
int nbPrevoyante;
int nbKamikaze;
int nbGregaire;
int nbMultiple;

using namespace std;

int main(int argc, char **argv) {


    global_gamma_yeux_min=0;
    global_gamma_yeux_max=1;
    global_gamma_ouie_min=0;
    global_gamma_ouie_max=1;
    global_delta_yeux_min=0;
    global_delta_yeux_max=65;
    global_delta_ouie_min=5;
    global_delta_ouie_max=90;

    Aquarium ecosysteme(1000, 1000, 10);
    //prevoyante peureuse multiple gregaire kamikaze
    nbPeureuse = std::atoi(argv[1]);
    nbPrevoyante = std::atoi(argv[2]);
    nbKamikaze = std::atoi(argv[3]);
    nbGregaire = std::atoi(argv[4]);
    nbMultiple = std::atoi(argv[5]);

    ecosysteme.getMilieu().setSimulation(nbPeureuse,nbPrevoyante,nbMultiple,nbGregaire,nbKamikaze);
    Bestiole* ptr_bestiole;
    std::cout << ecosysteme.getMilieu().getNbMultiple() ;
    for (int i = 1; i <= nbPeureuse; ++i) {
        std::cout << "first iteration" << std::endl;
        ptr_bestiole = new Bestiole("peureuse");
        ecosysteme.getMilieu().addMember(ptr_bestiole);
    }
    for (int i = 1; i <= nbKamikaze; ++i) {
        std::cout << "first iteration" << std::endl;
        ptr_bestiole = new Bestiole("kamikaze");
        ecosysteme.getMilieu().addMember(ptr_bestiole);
    }
    for (int i = 1; i <= nbGregaire; ++i) {
        std::cout << "first iteration" << std::endl;
        ptr_bestiole = new Bestiole("gregaire");
        ecosysteme.getMilieu().addMember(ptr_bestiole);
    }
    for (int i = 1; i <= nbMultiple; ++i) {
        std::cout << "first iteration" << std::endl;
        ptr_bestiole = new Bestiole("multiple");
        ecosysteme.getMilieu().addMember(ptr_bestiole);
    }
    for (int i = 1; i <= nbPrevoyante; ++i) {
        std::cout << "first iteration" << std::endl;
        ptr_bestiole = new Bestiole("prevoyante");
        ecosysteme.getMilieu().addMember(ptr_bestiole);
    }
    ecosysteme.run();

    return 0;
}

