main : src/main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o ComportementGregaire.o ComportementKamikaze.o ComportementPeureuse.o ComportementPrevoyante.o
	g++ -Wall -std=c++11 -o bin/main src/main.cpp bin/Aquarium.o bin/Bestiole.o bin/Milieu.o bin/ComportementGregaire.o bin/ComportementPeureuse.o bin/ComportementPrevoyante.o bin/ComportementKamikaze.o bin/Comportement.o -I . -lX11 -lpthread

Aquarium.o : src/Aquarium.h src/Aquarium.cpp
	g++ -Wall -std=c++11  -c src/Aquarium.cpp -o bin/Aquarium.o -I .

Bestiole.o : src/Bestiole.h src/Bestiole.cpp
	g++ -Wall -std=c++11  -c src/Bestiole.cpp -o bin/Bestiole.o -I .

Milieu.o : src/Milieu.h src/Milieu.cpp
	g++ -Wall -std=c++11  -c src/Milieu.cpp -o bin/Milieu.o -I .

Comportement.o : src/comportement/Comportement.h src/comportement/Comportement.cpp
	g++ -Wall -std=c++11  -c src/comportement/Comportement.cpp -o bin/Comportement.o -I .

ComportementGregaire.o : src/comportement/ComportementGregaire.h src/comportement/ComportementGregaire.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementGregaire.cpp -o bin/ComportementGregaire.o -I .

ComportementKamikaze.o : src/comportement/ComportementKamikaze.h src/comportement/ComportementKamikaze.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementKamikaze.cpp -o bin/ComportementKamikaze.o -I .

ComportementPeureuse.o : src/comportement/ComportementPeureuse.h src/comportement/ComportementPeureuse.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementPeureuse.cpp -o bin/ComportementPeureuse.o -I .

ComportementPrevoyante.o : src/comportement/ComportementPrevoyante.h src/comportement/ComportementPrevoyante.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementPrevoyante.cpp -o bin/ComportementPrevoyante.o -I .

clean:
	rm -rf bin/*.o bin/main *.o
info:
$(info $$DATA = $(DATA))