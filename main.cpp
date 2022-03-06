#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   Aquarium       ecosysteme( 1920, 1080, 10 );
   int nbBestioles =  std::atoi(argv[1]);
   char* type = argv[2];
    for ( int i = 1; i <=nbBestioles; ++i )
      ecosysteme.getMilieu().addMember( Bestiole(type) );
   ecosysteme.run();

   return 0;
}

