#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   Aquarium       ecosysteme( 500, 500, 60 );
   ecosysteme.getMilieu().setSimulation(std::atoi(argv[1]), argv[2]);
    for ( int i = 1; i <=ecosysteme.getMilieu().getNbBestioles(); ++i )
      ecosysteme.getMilieu().addMember( Bestiole(ecosysteme.getMilieu().getType()) );
   ecosysteme.run();

   return 0;
}

