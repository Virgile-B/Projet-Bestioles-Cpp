#include "Aquarium.h"
#include "Milieu.h"
#include "Bestiole.h"
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>

int main(int argc, char **argv) {

	std::istringstream is_file("simulation.cfg");

	std::string line;
	while( std::getline(is_file, line) )
	{
	  std::istringstream is_line(line);
	  std::string key;
	  if( std::getline(is_line, key, '=') )
	  {
	    std::string value;
	    if( std::getline(is_line, value) ) 
	      store_line(key, value);
	  }
	}
}
