#include "Bestiole.h"
#include "Milieu.h"
#include <cstdlib>
#include <cmath>


const double      Bestiole::AFF_SIZE = 8.;
const double      Bestiole::MAX_VITESSE = 10.;
const double      Bestiole::LIMITE_VUE = 30.;
int               Bestiole::next = 0;


Bestiole::Bestiole(const std::string comportement)
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par defaut" << endl;
   comportement_multiple = false;
   x = y = 0;
   cumulX = cumulY = 0.;
   orientation = static_cast<double>( rand() )/RAND_MAX*2.*M_PI;
   vitesse = static_cast<double>( rand() )/RAND_MAX*MAX_VITESSE;
   if (comportement == "gregaire"){
      this->comportement = ComportementGregaire::get_gregaire();
      couleur = this->comportement->get_couleur();
   }
   if (comportement == "kamikaze"){
      this->comportement = ComportementKamikaze::get_kamikaze();
      couleur = this->comportement->get_couleur();
   }
   if (comportement == "peureuse"){
      this->comportement = ComportementPeureuse::get_peureuse();
      couleur = this->comportement->get_couleur();
   }
   if (comportement == "prevoyante"){
      this->comportement = ComportementPrevoyante::get_prevoyante();
      couleur = this->comportement->get_couleur();
   }
   if (comportement == "multiple"){
      // lance un timer pour l'état courrant
      comportement_multiple = true;
      randomComportement();
   }
}
bool Bestiole::changerComportement(time_t curr){
   std::cout << timer;
   if( difftime(curr, last_change) > timer) {
      randomComportement();
   }
}
void Bestiole::randomComportement(){
   int num_type;
   int nb_comportement = 4;
   last_change = time(NULL);
   num_type = (rand() % nb_comportement+1);
   setComportement(num_type);
}
void Bestiole::setComportement(int comportement)
{
   switch (comportement)
   {
   case 1:
      couleur = ComportementGregaire::get_gregaire()->get_couleur();
      break;
   case 2:
      couleur = ComportementKamikaze::get_kamikaze()->get_couleur();
      break;         
   case 3:
      couleur = ComportementPeureuse::get_peureuse()->get_couleur();
      break;            
   case 4:
      couleur = ComportementPrevoyante::get_prevoyante()->get_couleur();
      break;
   default :
      couleur = ComportementPrevoyante::get_prevoyante()->get_couleur();
      break;
   }
}
Bestiole::Bestiole( const Bestiole & b )
{

   identite = ++next;

   cout << "const Bestiole (" << identite << ") par copie" << endl;

   x = b.x;
   y = b.y;
   cumulX = cumulY = 0.;
   orientation = b.orientation;
   vitesse = b.vitesse;
   couleur = b.couleur;
   comportement_multiple = b.comportement_multiple;
}


void Bestiole::initCoords( int xLim, int yLim )
{

   x = rand() % xLim;
   y = rand() % yLim;

}


void Bestiole::bouge( int xLim, int yLim )
{

   double         nx, ny;
   double         dx = cos( orientation )*vitesse;
   double         dy = -sin( orientation )*vitesse;
   int            cx, cy;


   cx = static_cast<int>( cumulX ); cumulX -= cx;
   cy = static_cast<int>( cumulY ); cumulY -= cy;

   nx = x + dx + cx;
   ny = y + dy + cy;

   if ( (nx < 0) || (nx > xLim - 1) ) {
      orientation = M_PI - orientation;
      cumulX = 0.;
   }
   else {
      x = static_cast<int>( nx );
      cumulX += nx - x;
   }

   if ( (ny < 0) || (ny > yLim - 1) ) {
      orientation = -orientation;
      cumulY = 0.;
   }
   else {
      y = static_cast<int>( ny );
      cumulY += ny - y;
   }

}


void Bestiole::action( Milieu & monMilieu )
{
   if (this->estMultiple()){
      this->changerComportement(time(NULL));
   }
   bouge( monMilieu.getWidth(), monMilieu.getHeight() );

}

void Bestiole::draw( UImg & support )
{

   double         xt = x + cos( orientation )*AFF_SIZE/2.1;
   double         yt = y - sin( orientation )*AFF_SIZE/2.1;


   support.draw_ellipse( x, y, AFF_SIZE, AFF_SIZE/5., -orientation/M_PI*180., couleur );
   support.draw_circle( xt, yt, AFF_SIZE/2., couleur );

}


bool operator==( const Bestiole & b1, const Bestiole & b2 )
{

   return ( b1.identite == b2.identite );

}

const bool Bestiole::estMultiple()
{
   return comportement_multiple;
}
bool Bestiole::jeTeVois( const Bestiole & b ) const
{

   double         dist;


   dist = std::sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) );
   return ( dist <= LIMITE_VUE );

}
