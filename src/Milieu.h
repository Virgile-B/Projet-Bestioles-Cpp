#ifndef _MILIEU_H_
#define _MILIEU_H_


#include "UImg.h"
#include "Bestiole.h"
#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>

using namespace std;


class Milieu : public UImg
{

private :
   static const T          white[];

   int                     width, height;
   std::vector<Bestiole*>   listeBestioles;
   static const int        PROBA_NAIS;
   char* type;
   int nbBestioles;

public :
   Milieu( int _width, int _height );
   ~Milieu( void )=default;

   int getWidth( void ) const { return width; };
   int getHeight( void ) const { return height; };

   void step( void );

   void addMember(Bestiole* b ) {listeBestioles.push_back(b); listeBestioles.back()->initCoords(width, height); }
   void removeMember(Bestiole* b, std::vector<Bestiole*> &toRemove);
   std::vector<Bestiole*> Voisins( const Bestiole & b);
   int nbVoisins( const Bestiole & b );
   void naissance(char* type);
   void setSimulation(int nbBestiole, char* type);  
   int getNbBestioles();
   char* getType();

   void collision(Bestiole & b);

};


#endif
