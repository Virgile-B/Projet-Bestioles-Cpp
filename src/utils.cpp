//
// Created by yassine on 20/03/2022.
//

#ifndef PROJET_BESTIOLES_UTILS

float RandomValues(double min, double max) {
    double r = (double) rand() / (double) RAND_MAX;
    return min + r * (max - min);
}

bool estDedans(double x, double x1, double x2){
    if ((x1 <= x && x <= x2) || (x1 >= x && x >= x2)){
        return true;
    }
    else{
        return false;
    }
}

#endif