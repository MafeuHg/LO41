#all:  test

#main: main.o atelier.o boiteLettre.o carte.o conteneur.o hommeFlux.o operateur.o pieces.o stock.o tableauDeLancement.o zoneCollecte.o
#	gcc main.o atelier.o boiteLettre.o carte.o conteneur.o hommeFlux.o operateur.o pieces.o stock.o tableauDeLancement.o zoneCollecte.o -o Main -lpthread

Test: test.o atelier.o boiteLettre.o carte.o conteneur.o hommeFlux.o operateur.o pieces.o stock.o tableauDeLancement.o zoneCollecte.o
	gcc test.o atelier.o boiteLettre.o carte.o conteneur.o hommeFlux.o operateur.o pieces.o stock.o tableauDeLancement.o zoneCollecte.o -o Test -lpthread

#main.o: main.c
#	gcc main.c -c -lpthread

test.o: test.c
	gcc test.c -c -lpthread

atelier.o: atelier.c
	gcc -c atelier.c -lpthread

boiteLettre.o: boiteLettre.c
	gcc -c boiteLettre.c -lpthread

carte.o: carte.c
	gcc -c carte.c -lpthread

conteneur.o: conteneur.c
	gcc -c conteneur.c -lpthread

hommeFlux.o: hommeFlux.c
	gcc -c hommeFlux.c -lpthread

operateur.o: operateur.c
	gcc -c operateur.c -lpthread

pieces.o: pieces.c
	gcc -c pieces.c

stock.o: stock.c pieces.c
	gcc -c stock.c

tableauDeLancement.o: tableauDeLancement.c
	gcc -c tableauDeLancement.c

zoneCollecte.o: zoneCollecte.c
	gcc -c zoneCollecte.c

clean:
	rm *.o
