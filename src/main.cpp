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
int nbPeureuse=0;
int nbPrevoyante=0;
int nbKamikaze=0;
int nbGregaire=0;
int nbMultiple=0;
int nbStepMax=0;
std::string test;

using namespace std;

int main(int argc, char **argv) {
    vector<double *> var_glob;
    double *global_gamma_yeux_min_p = &global_gamma_yeux_min;
    double *global_gamma_yeux_max_p = &global_gamma_yeux_max;
    double *global_gamma_ouie_min_p = &global_gamma_ouie_min;
    double *global_gamma_ouie_max_p = &global_gamma_ouie_max;
    double *global_delta_yeux_min_p = &global_delta_yeux_min;
    double *global_delta_yeux_max_p = &global_delta_yeux_max;
    double *global_delta_ouie_min_p = &global_delta_ouie_min;
    double *global_delta_ouie_max_p = &global_delta_ouie_max;
    var_glob.push_back(global_gamma_yeux_min_p);
    var_glob.push_back(global_gamma_yeux_max_p);
    var_glob.push_back(global_gamma_ouie_min_p);
    var_glob.push_back(global_gamma_ouie_max_p);
    var_glob.push_back(global_delta_yeux_min_p);
    var_glob.push_back(global_delta_yeux_max_p);
    var_glob.push_back(global_delta_ouie_min_p);
    var_glob.push_back(global_delta_ouie_max_p);

    vector<int *> var_nbs;
    int *nbPeureuse_p = &nbPeureuse;
    int *nbPrevoyante_p = &nbPrevoyante;
    int *nbKamikaze_p = &nbKamikaze;
    int *nbGregaire_p = &nbGregaire;
    int *nbMultiple_p = &nbMultiple;
    int *nbStepMax_p = &nbStepMax;
    var_nbs.push_back(nbPeureuse_p);
    var_nbs.push_back(nbPrevoyante_p);
    var_nbs.push_back(nbKamikaze_p);
    var_nbs.push_back(nbGregaire_p);
    var_nbs.push_back(nbMultiple_p);
    var_nbs.push_back(nbStepMax_p);

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
    }
    return 0;
}

