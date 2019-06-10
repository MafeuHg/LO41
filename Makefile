#all:  test

main: main.o container.o operator.o stock.o
	gcc main.o container.o operator.o stock.o -o Main -pthread

#Test: test.o atelier.o boiteLettre.o carte.o container.o hommeFlux.o operator.o pieces.o stock.o tableauDeLancement.o zoneCollecte.o
#	gcc test.o atelier.o boiteLettre.o carte.o container.o hommeFlux.o operator.o pieces.o stock.o tableauDeLancement.o zoneCollecte.o -o Test -lpthread

main.o: main.c
	gcc main.c -c -pthread

#test.o: test.c
#	gcc test.c -c -lpthread

#atelier.o: atelier.c
#	gcc -c atelier.c -lpthread

#boiteLettre.o: boiteLettre.c
#	gcc -c boiteLettre.c -lpthread

#carte.o: carte.c
#	gcc -c carte.c -lpthread

container.o: container.c
	gcc -c container.c -lpthread

#hommeFlux.o: hommeFlux.c
#	gcc -c hommeFlux.c -lpthread

operator.o: operator.c
	gcc -c operator.c -lpthread

stock.o: stock.c container.c
	gcc -c stock.c

#tableauDeLancement.o: tableauDeLancement.c
#	gcc -c tableauDeLancement.c

#zoneCollecte.o: zoneCollecte.c
#	gcc -c zoneCollecte.c

clean:
	rm *.o
