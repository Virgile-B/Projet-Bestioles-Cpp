main : src/main.cpp Aquarium.o Bestiole.o Milieu.o Comportement.o ComportementGregaire.o ComportementKamikaze.o ComportementPeureuse.o ComportementPrevoyante.o Accessoire.o NoAccessoire.o AccessoireNageoire.o AccessoireCarapace.o AccessoireCamouflage.o
	g++ -Wall -std=c++11 -o bin/main src/main.cpp bin/Aquarium.o bin/Bestiole.o bin/Milieu.o bin/ComportementGregaire.o bin/ComportementPeureuse.o bin/ComportementPrevoyante.o bin/ComportementKamikaze.o bin/Comportement.o bin/Accessoire.o bin/NoAccessoire.o bin/AccessoireNageoire.o bin/AccessoireCarapace.o bin/AccessoireCamouflage.o -I . -lX11 -lpthread -w

Aquarium.o : src/Aquarium.h src/Aquarium.cpp
	g++ -Wall -std=c++11  -c src/Aquarium.cpp -o bin/Aquarium.o -I . -w

Bestiole.o : src/Bestiole.h src/Bestiole.cpp
	g++ -Wall -std=c++11  -c src/Bestiole.cpp -o bin/Bestiole.o -I . -w

Milieu.o : src/Milieu.h src/Milieu.cpp
	g++ -Wall -std=c++11  -c src/Milieu.cpp -o bin/Milieu.o -I . -w

Comportement.o : src/comportement/Comportement.h src/comportement/Comportement.cpp
	g++ -Wall -std=c++11  -c src/comportement/Comportement.cpp -o bin/Comportement.o -I . -w

ComportementGregaire.o : src/comportement/ComportementGregaire.h src/comportement/ComportementGregaire.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementGregaire.cpp -o bin/ComportementGregaire.o -I . -w

ComportementKamikaze.o : src/comportement/ComportementKamikaze.h src/comportement/ComportementKamikaze.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementKamikaze.cpp -o bin/ComportementKamikaze.o -I . -w

ComportementPeureuse.o : src/comportement/ComportementPeureuse.h src/comportement/ComportementPeureuse.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementPeureuse.cpp -o bin/ComportementPeureuse.o -I . -w

ComportementPrevoyante.o : src/comportement/ComportementPrevoyante.h src/comportement/ComportementPrevoyante.cpp
	g++ -Wall -std=c++11  -c src/comportement/ComportementPrevoyante.cpp -o bin/ComportementPrevoyante.o -I . -w

Accessoire.o : src/accessoire/Accessoire.h src/accessoire/Accessoire.cpp
	g++ -Wall -std=c++11  -c src/accessoire/Accessoire.cpp -o bin/Accessoire.o -I . -w

AccessoireNageoire.o : src/accessoire/AccessoireNageoire.h src/accessoire/AccessoireNageoire.cpp
	g++ -Wall -std=c++11  -c src/accessoire/AccessoireNageoire.cpp -o bin/AccessoireNageoire.o -I . -w

NoAccessoire.o : src/accessoire/NoAccessoire.h src/accessoire/NoAccessoire.cpp
	g++ -Wall -std=c++11  -c src/accessoire/NoAccessoire.cpp -o bin/NoAccessoire.o -I . -w

AccessoireCarapace.o : src/accessoire/AccessoireCarapace.h src/accessoire/AccessoireCarapace.cpp
	g++ -Wall -std=c++11  -c src/accessoire/AccessoireCarapace.cpp -o bin/AccessoireCarapace.o -I . -w

AccessoireCamouflage.o : src/accessoire/AccessoireCamouflage.h src/accessoire/AccessoireCamouflage.cpp
	g++ -Wall -std=c++11  -c src/accessoire/AccessoireCamouflage.cpp -o bin/AccessoireCamouflage.o -I . -w

clean:
	rm -rf bin/*.o bin/main *.o
info:
$(info $$DATA = $(DATA))