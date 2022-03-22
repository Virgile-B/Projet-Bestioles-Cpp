#include "Aquarium.h"

#include "Milieu.h"


Aquarium::Aquarium( int width, int height, int _delay ) : CImgDisplay(), delay( _delay )
{

   int         screenWidth = 1280; //screen_width();
   int         screenHeight = 1024; //screen_height();


   cout << "const Aquarium" << endl;

   flotte = new Milieu( width, height );
   assign( *flotte, "Simulation d'ecosysteme" );

   move( static_cast<int>((screenWidth-width)/2), static_cast<int>((screenHeight-height)/2) );

}


Aquarium::~Aquarium( void )
{

   delete flotte;

   cout << "####################" << endl;
   cout << "Fin de la Simulation" << endl;
   cout << "####################" << endl;

}


void Aquarium::run( void )
{

   cout << "running Aquarium" << endl;

   while ( ! is_closed() )
   {
      if ( is_key() ) {
         cout << "Vous avez presse la touche " << static_cast<unsigned char>( key() );
         cout << " (" << key() << ")" << endl;
         if (is_keyS()) flotte->stateSimu(false);
         if (is_keyE()) flotte->stateSimu(true);
         if( is_keySPACE()) pause = true;
         if( is_keyENTER()) pause = false ;  
         if ( is_keyESC() ) close();
      }
      if(!pause)
      { 
         flotte->step();
         display(*flotte );
         wait( delay );
      }

   } // while

}
