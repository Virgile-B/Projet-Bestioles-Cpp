#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <iostream>
#include <fstream> 



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

    string chemin = "bin/init_bestioles.txt";
    ifstream fichier(chemin, ios::in); //ouverture du fichier
    if(fichier.is_open()) 
    {
        double global_initializer;  
        int index_line = 0;
        while (fichier >> global_initializer && index_line < 8) 
        {
            *var_glob[index_line]=global_initializer;
            index_line+=1;
        }

        int nb_bestiole;
        index_line=0;
        while (fichier >> nb_bestiole) 
        { 

            *var_nbs[index_line]=nb_bestiole;
            index_line+=1;

            if (fichier.eof())  // Test si on est en fin de fichier
                break ;
        }

        fichier.close();   
    }  
    else 
    {
      cout << "ERREUR : Impossible d'ouvrir le fichier !" << endl;
    }

    /*
    global_gamma_yeux_min=0;
    global_gamma_yeux_max=1;
    global_gamma_ouie_min=0;
    global_gamma_ouie_max=1;
    global_delta_yeux_min=0;
    global_delta_yeux_max=150;
    global_delta_ouie_min=5;
    global_delta_ouie_max=75;
    */

    Aquarium ecosysteme(1000, 1000, 10);
    //prevoyante peureuse multiple gregaire kamikaze

    /*
    nbPeureuse = std::atoi(argv[1]);
    nbPrevoyante = std::atoi(argv[2]);
    nbKamikaze = std::atoi(argv[3]);
    nbGregaire = std::atoi(argv[4]);
    nbMultiple = std::atoi(argv[5]);
    nbStepMax = std::atoi(argv[6]);
    */
    std::cout <<nbStepMax;
    ecosysteme.getMilieu().setSimulation(nbPeureuse,nbPrevoyante,nbMultiple,nbGregaire,nbKamikaze,nbStepMax);
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

