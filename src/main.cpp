#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include"test.cpp"



double global_gamma_yeux_min=0;
double global_gamma_yeux_max=0;
double global_gamma_ouie_min=0;
double global_gamma_ouie_max=0;
double global_delta_yeux_min=0;
double global_delta_yeux_max=0;
double global_delta_ouie_min=0;
double global_delta_ouie_max=0;
double global_coef_camouflage_min=0;
double global_coef_camouflage_max=0;
double global_coef_carapace_max=0;
double global_coef_ralentissement_max=0;
double global_coef_vitesse_max=0;
double global_alpha_vision_min=0;
double global_alpha_vision_max=0;

int nbPeureuse=0;
int nbPrevoyante=0;
int nbKamikaze=0;
int nbGregaire=0;
int nbMultiple=0;
int nbStepMax=0;
int PROBA_MORT=0;
int PROBA_NAISSANCE=0;
std::string test;

using namespace std;

int main(int argc, char **argv) {
    std::cout << "Do you want to test the product ? Please answer yes or no" << std::endl;
    std::cin >> test;
    if(test.compare("yes")==0) {
        initiateVariables(0);
        runTest();
    }else {
        initiateVariables(1);
        Aquarium ecosysteme(1000, 1000, 10);
        //prevoyante peureuse multiple gregaire kamikaze

        ecosysteme.getMilieu().setSimulation(nbPeureuse, nbPrevoyante, nbMultiple, nbGregaire, nbKamikaze, nbStepMax);
        Bestiole *ptr_bestiole;
        std::cout << ecosysteme.getMilieu().getNbMultiple();
        for (int i = 1; i <= nbPeureuse; ++i) {
            ptr_bestiole = new Bestiole("peureuse");
            ecosysteme.getMilieu().addMember(ptr_bestiole);
        }
        for (int i = 1; i <= nbKamikaze; ++i) {
            ptr_bestiole = new Bestiole("kamikaze");
            ecosysteme.getMilieu().addMember(ptr_bestiole);
        }
        for (int i = 1; i <= nbGregaire; ++i) {
            ptr_bestiole = new Bestiole("gregaire");
            ecosysteme.getMilieu().addMember(ptr_bestiole);
        }
        for (int i = 1; i <= nbMultiple; ++i) {
            ptr_bestiole = new Bestiole("multiple");
            ecosysteme.getMilieu().addMember(ptr_bestiole);
        }
        for (int i = 1; i <= nbPrevoyante; ++i) {
            ptr_bestiole = new Bestiole("prevoyante");
            ecosysteme.getMilieu().addMember(ptr_bestiole);
        }
        ecosysteme.run();
    }
    return 0;
}

