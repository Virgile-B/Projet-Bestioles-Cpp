main : main.cpp Aquarium.o Bestiole.o Milieu.o ComportementGregaire.o Comportement.o ComportementKamikaze.o ComportementPeureuse.o ComportementPrevoyante.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o ComportementGregaire.o ComportementPeureuse.o ComportementPrevoyante.o ComportementKamikaze.o Comportement.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Comportement.o : comportement/Comportement.h comportement/Comportement.cpp
	g++ -Wall -std=c++11  -c comportement/Comportement.cpp -I .

ComportementGregaire.o : comportement/ComportementGregaire.h comportement/ComportementGregaire.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementGregaire.cpp -I .

ComportementKamikaze.o : comportement/ComportementKamikaze.h comportement/ComportementKamikaze.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementKamikaze.cpp -I .

ComportementPeureuse.o : comportement/ComportementPeureuse.h comportement/ComportementPeureuse.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementPeureuse.cpp -I .

ComportementPrevoyante.o : comportement/ComportementPrevoyante.h comportement/ComportementPrevoyante.cpp
	g++ -Wall -std=c++11  -c comportement/ComportementPrevoyante.cpp -I .

clean:
	rm -rf *.o main
info:
$(info $$DATA = $(DATA))