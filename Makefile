main : main.cpp Aquarium.o Bestiole.o Milieu.o ComportementGregaire.o Comportement.o
	g++ -Wall -std=c++11 -o main main.cpp Aquarium.o Bestiole.o Milieu.o ComportementGregaire.o Comportement.o -I . -lX11 -lpthread

Aquarium.o : Aquarium.h Aquarium.cpp
	g++ -Wall -std=c++11  -c Aquarium.cpp -I .

Bestiole.o : Bestiole.h Bestiole.cpp
	g++ -Wall -std=c++11  -c Bestiole.cpp -I .

Milieu.o : Milieu.h Milieu.cpp
	g++ -Wall -std=c++11  -c Milieu.cpp -I .

Comportement.o : Comportement.h Comportement.cpp
	g++ -Wall -std=c++11  -c Comportement.cpp -I .

ComportementGregaire.o : ComportementGregaire.h ComportementGregaire.cpp
	g++ -Wall -std=c++11  -c ComportementGregaire.cpp -I .

clean:
	rm -rf *.o main
info:
$(info $$DATA = $(DATA))