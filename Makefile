#all:  test

main: main.o container.o operator.o stock.o
	gcc ./objects/*.o -o Main -pthread

main.o: ./sources/main.c
	gcc ./sources/main.c -c -o ./objects/main.o -pthread

container.o: ./sources/container.c
	gcc -c ./sources/container.c -o ./objects/container.o

operator.o: ./sources/operator.c
	gcc -c ./sources/operator.c -o ./objects/operator.o -lpthread

stock.o: ./sources/stock.c ./sources/container.c
	gcc -c ./sources/stock.c -o ./objects/stock.o

clean:
	rm ./objects/*.o
