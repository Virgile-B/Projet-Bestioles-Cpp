//
// Created by yassine on 22/03/2022.
//
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Bestiole;

/*
 * setComportement(int comportement); // 0:gregaire 1:Kamikaze 2:peureuse 3:prevoyante
 */
void
setBestiole(Bestiole *b, double x, double y, double orientation, vector <std::string> accessoires, int comportement,
            double vitesse, double deltaYeux, double deltaOuie, bool multiple) {
    b->setComportementMultiple(multiple);
    b->initTestCoords(x, y, orientation);
    b->setVitesse(vitesse);
    b->setOldVitesse(vitesse);  // Pour que le comportement peureuse ne remette pas la vitesse initiale
    b->setAccessoire(accessoires);
    b->setComportement(comportement);
    b->setDeltaYeux(deltaYeux);
    b->setDeltaOuie(deltaOuie);

}

void runTest() {
    int testCase;
    cout << "Please select the number of one of the following tests" << endl;
    cout << "1-test Camouflage" << endl;
    cout << "2-test Carapace" << endl;
    cout << "3-test Nageoire" << endl;
    cout << "4-test Yeux" << endl;
    cout << "5-test Ouie" << endl;
    cout << "6-test 2 Capteurs" << endl;
    cout << "7-test Gregaire" << endl;
    cout << "8-test Kamikaze" << endl;
    cout << "9-test Peureuse" << endl;
    cout << "10-test Prevoyante" << endl;
    cout << "11-test Multiple" << endl;
    cin >> testCase;

    Aquarium ecosysteme(1000, 1000, 10);
    ecosysteme.getMilieu().setSimulation(0, 0, 0, 0, 0, 1000);

    switch (testCase) {
        case 1: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 5., 200,
                        200, false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 600, 500, M_PI, {"noAccessoires", "noAccessoires", "camouflage"}, 0, 5., 50.,
                        0., false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);
            break;
        }
        case 2: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 400, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 1, 5., 0., 0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 600, 500, M_PI, {"noAccessoires", "carapace", "noAccessoires"}, 1, 5., 0., 0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);
            break;
        }
        case 3: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 100, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 1, 6., 0., 0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 100, 700, 0, {"nageoires", "noAccessoires", "noAccessoires"}, 1, 6., 0., 0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);
            break;
        }
        case 4: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 80., 0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 800, 500, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 2, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);
            break;
        }
        case 5: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0., 80.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 800, 500, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 1, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);
            break;
        }
        case 6: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0., 0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 800, 500, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);

            // Création de la troisième bestiole en haut
            Bestiole *ptr_bestiole3;
            ptr_bestiole3 = new Bestiole();
            setBestiole(ptr_bestiole3, 450, 300, -M_PI / 2, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6.,
                        120., 100.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole3);
            break;
        }
        case 7: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 150.,
                        150.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 800, 500, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);

            // Création de la troisième bestiole à droite
            Bestiole *ptr_bestiole3;
            ptr_bestiole3 = new Bestiole();
            setBestiole(ptr_bestiole3, 800, 400, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole3);
            // Création de la quatrième bestiole à droite
            Bestiole *ptr_bestiole4;
            ptr_bestiole4 = new Bestiole();
            setBestiole(ptr_bestiole4, 800, 600, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole4);
            break;
        }
        case 8: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 1, 6., 150.,
                        150.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 800, 400, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);

            break;
        }
        case 9: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 2, 6., 150.,
                        150.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 800, 500, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);

            // Création de la troisième bestiole à droite
            Bestiole *ptr_bestiole3;
            ptr_bestiole3 = new Bestiole();
            setBestiole(ptr_bestiole3, 800, 520, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole3);
            // Création de la quatrième bestiole à droite
            Bestiole *ptr_bestiole4;
            ptr_bestiole4 = new Bestiole();
            setBestiole(ptr_bestiole4, 800, 480, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole4);
            break;
        }
        case 10: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 3, 6., 0.,
                        0.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 800, 500, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 2, 6., 150.,
                        150.,
                        false);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);

            break;
        }
        case 11: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            setBestiole(ptr_bestiole1, 0, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 0, 6., 0.,
                        0.,
                        true);
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            setBestiole(ptr_bestiole2, 1000, 500, M_PI, {"noAccessoires", "noAccessoires", "noAccessoires"}, 1, 6., 0.,
                        0.,
                        true);
            ecosysteme.getMilieu().addMember(ptr_bestiole2);

            // Création de la troisième bestiole en bas
            Bestiole *ptr_bestiole3;
            ptr_bestiole3 = new Bestiole();
            setBestiole(ptr_bestiole3, 500, 1000, M_PI/2, {"noAccessoires", "noAccessoires", "noAccessoires"}, 2, 6., 0.,
                        0.,
                        true);
            ecosysteme.getMilieu().addMember(ptr_bestiole3);
            // Création de la quatrième bestiole en haut
            Bestiole *ptr_bestiole4;
            ptr_bestiole4 = new Bestiole();
            setBestiole(ptr_bestiole4, 500, 0, -M_PI/2, {"noAccessoires", "noAccessoires", "noAccessoires"}, 3, 6., 0.,
                        0.,
                        true);
            ecosysteme.getMilieu().addMember(ptr_bestiole4);
            break;
        }
    }

    ecosysteme.run();


}

//permet d'initier les variables globales d'angles de vue / ouïe et les nombres de chaque comportement pour une
//simulation donnée. Ainsi, pour changer une configuration, il suffit de changer un des fichier init_bestioles.txt
// ou init_bestioles2.txt (le numéro 2 étant pour le cas de figure voulu par l'utilisateur et le 1 pour tester le programme)
void initiateVariables(int index){
    //ici on défini les fameuses costantes comme devant être lues dans le main via le mot-clé "extern"
    extern double global_gamma_yeux_min;
    extern double global_gamma_yeux_max;
    extern double global_gamma_ouie_min;
    extern double global_gamma_ouie_max;
    extern double global_delta_yeux_min;
    extern double global_delta_yeux_max;
    extern double global_delta_ouie_min;
    extern double global_delta_ouie_max;
    extern double global_coef_camouflage_min;
    extern double global_coef_camouflage_max;
    extern double global_coef_carapace_max;
    extern double global_coef_ralentissement_max;
    extern double global_coef_vitesse_max;
    extern double global_alpha_vision_min;
    extern double global_alpha_vision_max;
    extern int nbPeureuse;
    extern int nbPrevoyante;
    extern int nbKamikaze;
    extern int nbGregaire;
    extern int nbMultiple;
    extern int nbStepMax;
    extern int PROBA_MORT;
    extern int PROBA_NAISSANCE;


    // on créé un vecteur de pointeur vers les variables globale d'ouïe et de vision
    vector<double *> var_glob;
    double *global_gamma_yeux_min_p = &global_gamma_yeux_min;
    double *global_gamma_yeux_max_p = &global_gamma_yeux_max;
    double *global_gamma_ouie_min_p = &global_gamma_ouie_min;
    double *global_gamma_ouie_max_p = &global_gamma_ouie_max;
    double *global_delta_yeux_min_p = &global_delta_yeux_min;
    double *global_delta_yeux_max_p = &global_delta_yeux_max;
    double *global_delta_ouie_min_p = &global_delta_ouie_min;
    double *global_delta_ouie_max_p = &global_delta_ouie_max;
    double *global_coef_camouflage_min_p = &global_coef_camouflage_min;
    double *global_coef_camouflage_max_p = &global_coef_camouflage_max;
    double *global_coef_carapace_max_p = &global_coef_carapace_max;
    double *global_coef_ralentissement_max_p = &global_coef_ralentissement_max;
    double *global_coef_vitesse_max_p = &global_coef_vitesse_max;
    double *global_alpha_vision_min_p = &global_alpha_vision_min;
    double *global_alpha_vision_max_p = &global_alpha_vision_max;
    // on remplit ce vecteur
    var_glob.push_back(global_gamma_yeux_min_p);
    var_glob.push_back(global_gamma_yeux_max_p);
    var_glob.push_back(global_gamma_ouie_min_p);
    var_glob.push_back(global_gamma_ouie_max_p);
    var_glob.push_back(global_delta_yeux_min_p);
    var_glob.push_back(global_delta_yeux_max_p);
    var_glob.push_back(global_delta_ouie_min_p);
    var_glob.push_back(global_delta_ouie_max_p);
    var_glob.push_back(global_coef_camouflage_min_p);
    var_glob.push_back(global_coef_camouflage_max_p);
    var_glob.push_back(global_coef_carapace_max_p);
    var_glob.push_back(global_coef_ralentissement_max_p);
    var_glob.push_back(global_coef_vitesse_max_p);
    var_glob.push_back(global_alpha_vision_min_p);
    var_glob.push_back(global_alpha_vision_max_p);
    // on fait la même chose avec le nombre de chaque comportement dans la simulation
    vector<int *> var_nbs;
    int *PROBA_MORT_p = &PROBA_MORT;
    int *PROBA_NAISSANCE_p = &PROBA_NAISSANCE;
    int *nbPeureuse_p = &nbPeureuse;
    int *nbPrevoyante_p = &nbPrevoyante;
    int *nbKamikaze_p = &nbKamikaze;
    int *nbGregaire_p = &nbGregaire;
    int *nbMultiple_p = &nbMultiple;
    int *nbStepMax_p = &nbStepMax;
    var_nbs.push_back(PROBA_MORT_p);
    var_nbs.push_back(PROBA_NAISSANCE_p);
    var_nbs.push_back(nbPeureuse_p);
    var_nbs.push_back(nbPrevoyante_p);
    var_nbs.push_back(nbKamikaze_p);
    var_nbs.push_back(nbGregaire_p);
    var_nbs.push_back(nbMultiple_p);
    var_nbs.push_back(nbStepMax_p);
    // si l'utilisateur veut tester le programme, on instancie via le fichier init_vestioles.txt
    if(index==0)
    {
        string chemin = "bin/init_bestioles.txt";
        // ici on définit notre fichier d'entrée et on l'ouvre
        ifstream fichier(chemin, ios::in);
        if(fichier.is_open()) 
        {
            //cette variable sert à instancier les éléments des vecteurs de pointeurs un par un
            // (elle ira entre 0 et la longueur du vecteur donc)
            int index_line = 0;
            // cette variable servira à stocker une ligne dans le fichier texte
            string line;
            // tant que l'on est dans les 8 premières lignes, soit le vecteur 1...
            while (index_line < 15 && getline(fichier, line))
            {
                // on créé un stringstream...
                stringstream ss(line);
                // strline servira à quantifier la partie de la ligne qui est un string...
                string strline;
                // et doubleline la partie de la ligne qui est un double
                double doubleline;
                // comme on sait que chaque ligne a la même structure string, espace, double, on peut récupérer 
                // notre double doubleling et l'atitrer dans le vecteur
                ss >> strline >> doubleline;
                *var_glob[index_line]=doubleline;
                index_line+=1;

            }
            // on refait la même chose avec le deuxième vecteur
            index_line=0;
            while (getline(fichier, line)) 
            {
                stringstream ss2(line);
                string strline;
                int intline;

                ss2 >> strline >> intline;
                *var_nbs[index_line]=intline;
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
    }
    // si l'utilisateur ne veut pas tester le programme, on instancie via le fichier init_vestioles2.txt
    else
    {
        string chemin = "bin/init_bestioles2.txt";
        ifstream fichier(chemin, ios::in);
        if(fichier.is_open()) 
        {
            int index_line = 0;
            string line;
            while (index_line < 15 && getline(fichier, line))
            {
                stringstream ss(line);
                string strline;
                double doubleline;

                ss >> strline >> doubleline;
                *var_glob[index_line]=doubleline;
                index_line+=1;
            }

            index_line=0;
            while (getline(fichier, line)) 
            { 
                stringstream ss2(line);
                string strline;
                int intline;

                ss2 >> strline >> intline;
                *var_nbs[index_line]=intline;
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
    }
}
