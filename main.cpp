#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"

#include <iostream>

using namespace std;


int main()
{

   Aquarium       ecosysteme( 1920, 1080, 1 );

   for ( int i = 1; i <= 2; ++i )
      ecosysteme.getMilieu().addMember( Bestiole() );
   ecosysteme.run();


   return 0;
}
