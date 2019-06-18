#all:  test

main: main.o container.o operator.o stock.o boite_aux_lettres.o card.o homme_flux.o atelier.o
	gcc ./objects/*.o -o Main -pthread

main.o: ./sources/main.c
	gcc ./sources/main.c -c -o ./objects/main.o -pthread

container.o: ./sources/container.c
	gcc -c ./sources/container.c -o ./objects/container.o

operator.o: ./sources/operator.c
	gcc -c ./sources/operator.c -o ./objects/operator.o -lpthread

stock.o: ./sources/stock.c ./sources/container.c
	gcc -c ./sources/stock.c -o ./objects/stock.o

boite_aux_lettres.o: ./sources/boite_aux_lettres.c
	gcc -c ./sources/boite_aux_lettres.c -o ./objects/boite_aux_lettres.o

card.o: ./sources/card.c
	gcc -c ./sources/card.c -o ./objects/card.o

homme_flux.o: ./sources/homme_flux.o
	gcc -c ./sources/homme_flux.c -o ./objects/homme_flux.o

atelier.o: ./sources/atelier.o
	gcc -c ./sources/atelier.c -o ./objects/atelier.o

clean:
	rm ./objects/*.o
