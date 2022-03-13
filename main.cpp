#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <string>
#include <iostream>

double global_gamma_yeux_min;
double global_gamma_yeux_max;
double global_gamma_ouie_min;
double global_gamma_ouie_max;
double global_delta_yeux_min;
double global_delta_yeux_max;
double global_delta_ouie_min;
double global_delta_ouie_max;
using namespace std;

int main(int argc, char **argv) {
    double gamma_yeux_min, gamma_yeux_max, gamma_ouie_min, gamma_ouie_max, delta_yeux_min, delta_yeux_max,
            delta_ouie_min, delta_ouie_max;
    std::cout << "Please enter the values you need for this simulation" << std::endl;

    do {
        std::cout << "Please enter a value between 0 and 1" << std::endl;
        std::cout << "gamma_yeux_min: " << std::endl;
        std::cin >> gamma_yeux_min;
    } while (gamma_yeux_min > 1);
    do {
        std::cout << "Please enter a value between 0 and 1" << std::endl;
        std::cout << "gamma_yeux_max: " << std::endl;
        std::cin >> gamma_yeux_max;
    } while (gamma_yeux_max > 1);
    do {
        std::cout << "Please enter a value between 0 and 1" << std::endl;
        std::cout << "gamma_ouie_min: " << std::endl;
        std::cin >> gamma_ouie_min;
    } while (gamma_ouie_min > 1);
    do {
        std::cout << "Please enter a value between 0 and 1" << std::endl;
        std::cout << "gamma_ouie_max: " << std::endl;
        std::cin >> gamma_ouie_max;
    } while (gamma_ouie_max > 1);
    std::cout << "delta_yeux_min: " << std::endl;
    std::cin >> delta_yeux_min;
    std::cout << "delta_yeux_max: " << std::endl;
    std::cin >> delta_yeux_max;
    std::cout << "delta_ouie_min: " << std::endl;
    std::cin >> delta_ouie_min;
    std::cout << "delta_ouie_max: " << std::endl;
    std::cin >> delta_ouie_max;


    global_gamma_yeux_min = gamma_yeux_min;
    global_gamma_yeux_max = gamma_yeux_max;
    global_gamma_ouie_min = gamma_ouie_min;
    global_gamma_ouie_max = gamma_ouie_max;
    global_delta_yeux_min = delta_yeux_min;
    global_delta_yeux_max = delta_yeux_max;
    global_delta_ouie_min = delta_ouie_min;
    global_delta_ouie_max = delta_ouie_max;

    Aquarium ecosysteme(1000, 1000, 10);
    ecosysteme.getMilieu().setSimulation(std::atoi(argv[1]), argv[2]);
    for (int i = 1; i <= ecosysteme.getMilieu().getNbBestioles(); ++i) {
        std::cout << "first iteration" << std::endl;
        ecosysteme.getMilieu().addMember(Bestiole(ecosysteme.getMilieu().getType()));
    }
    ecosysteme.run();

    return 0;
}

