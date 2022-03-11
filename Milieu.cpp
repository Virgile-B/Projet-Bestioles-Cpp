#include "Milieu.h"

#include <cstdlib>
#include <ctime>

const T    Milieu::white[] = { (T)255, (T)255, (T)255 };
const int   Milieu::PROBA_NAIS = 10;

Milieu::Milieu( int _width, int _height ) : UImg( _width, _height, 1, 3 ),
                                            width(_width), height(_height)
{

   cout << "const Milieu" << endl;

}

void Milieu::step( void )
{
   
   cimg_forXY( *this, x, y ) fillC( x, y, 0, white[0], white[1], white[2] );
   this->naissance(this->getType());
   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
   {

      it->action( *this );
      it->draw( *this );
   } 

}

int Milieu::nbVoisins( const Bestiole & b )
{

   int         nb = 0;


   for ( std::list<Bestiole>::iterator it = listeBestioles.begin() ; it != listeBestioles.end() ; ++it )
      if ( !(b == *it) && b.jeTeVois(*it) )
         ++nb;

   return nb;

}

void Milieu::naissance(char* type)
{
   if(type == "random")
   {
      if( (std::rand() % 100+1) > PROBA_NAIS){
        addMember(Bestiole());
      }
   }
   else 
   {
      addMember(Bestiole(type));
   }
}

void Milieu::setSimulation(int nbBestioles, char* type)
{
   this->type = type;
   this->nbBestioles = nbBestioles;
}

char* Milieu::getType()
{
   return this->type;
}

int Milieu::getNbBestioles()
{
   return this->nbBestioles;
}