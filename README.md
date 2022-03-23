# Projet-bestioles

# Requirements

* g++ v5.4 or newer
* Make


# Compilation

The code can be compiled with the provided makefile using the standard `make`
command.
Then you can answer the question by typing `yes` or `no`.
If you answer `yes`, you can access the test files and then you can select the number you wish to execute.  
If you answer no, you will have a free simulation of critters taken randomly.

If compiling the code manually, or integrating into a larger program, include
the following flags:
```
FLAGS=-std=c++11 -Wall 
```


To launch a simulation, you need to type the following command:
```
./bin/main
```
To configure the following variables:
```
    global_gamma_yeux_min;
    global_gamma_yeux_max;
    global_gamma_ouie_min;
    global_gamma_ouie_max;
    global_delta_yeux_min;
    global_delta_yeux_max;
    global_delta_ouie_min;
    global_delta_ouie_max;
    global_coef_camouflage_min;
    global_coef_camouflage_max;
    global_coef_carapace_max;
    global_coef_ralentissement_max;
    global_coef_vitesse_max;
    global_alpha_vision_min;
    global_alpha_vision_max;
    nbPeureuse;
    nbPrevoyante;
    nbKamikaze;
    nbGregaire;
    nbMultiple;
    nbStepMax;
    PROBA_MORT;
    PROBA_NAISSANCE;
```

you need to change the file
```
int_bestioles2.txt
```

You can also test the program by typing yes after executing it. Then you can choose the test you want to see.
You can also configure the variables for the test by changing the file
```
int_bestioles.txt
```

# Context
This project's objective is to simulate the environment of different critters.
They have two sensors, 3 accessories and 5 different behaviours that you can discover in the test.
