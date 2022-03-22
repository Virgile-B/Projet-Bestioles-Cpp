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
    cout << "12-test tous les comportements" << endl;
    cin >> testCase;

    Aquarium ecosysteme(1000, 1000, 10);
    ecosysteme.getMilieu().setSimulation(0, 0, 0, 0, 0, 1000);

    switch (testCase) {
        case 1: {
            // Création de la première bestiole à gauche
            Bestiole *ptr_bestiole1;
            ptr_bestiole1 = new Bestiole();
            cout << "vitesse " << ptr_bestiole1->getVitesse() << endl;
            setBestiole(ptr_bestiole1, 300, 500, 0, {"noAccessoires", "noAccessoires", "noAccessoires"}, 2, 5., 100,
                        100, false);
            cout << "vitesse " << ptr_bestiole1->getVitesse() << endl;
            ecosysteme.getMilieu().addMember(ptr_bestiole1);

            // Création de la seconde bestiole à droite
            Bestiole *ptr_bestiole2;
            ptr_bestiole2 = new Bestiole();
            cout << "vitesse " << ptr_bestiole2->getVitesse() << endl;
            setBestiole(ptr_bestiole2, 600, 500, M_PI, {"noAccessoires", "noAccessoires", "camouflage"}, 2, 5., 50.,
                        0., false);
            cout << "vitesse " << ptr_bestiole2->getVitesse() << endl;
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
    }

    ecosysteme.run();


}

