#ifndef _BESTIOLES_H_
#define _BESTIOLES_H_


#include "UImg.h"
#include <iostream>

using namespace std;

class Comportement;
class Milieu;


class Bestiole
{

private :
   static const double     AFF_SIZE;
   static const double     MAX_VITESSE;
   static const double     LIMITE_VUE;
   static int              next;
   static int              NB_COMPORTEMENT;

private :
   int               identite;
   int               x, y;
   double            cumulX, cumulY;
   double            orientation;
   double            vitesse;
   bool              comportement_multiple;
   T                 * couleur;
   Comportement      * comportement;
   int               esperanceVie;


private :
   void bouge( int xLim, int yLim );

public :                                           // Forme canonique :
   Bestiole(const std::string comportement);                               // Constructeur par defaut
   Bestiole( const Bestiole & b );                 // Constructeur de copies
   Bestiole();
   ~Bestiole( void )=default;                              // Destructeur
                                                   // Operateur d'affectation binaire par defaut
   void action( Milieu & monMilieu );
   void draw( UImg & support );

   bool jeTeVois( const Bestiole & b ) const;

   void initCoords( int xLim, int yLim );
   const bool estMultiple();
   friend bool operator==( const Bestiole & b1, const Bestiole & b2 );
   void randomComportement();
   bool changerComportement();
   void setComportement(int comprotement);
   void setEsperanceVie();
   void meurt(Milieu & monMilieu);
   double get_orientation();
   void set_orientation(double orientation);

};


#endif
