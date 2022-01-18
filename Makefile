CC = g++ -g3 -g -std=c++11 

project: main.o  

	$(CC) -o project main.o -lm

main.o:  main.cpp 

	$(CC) -c  main.cpp 

run:

	./project

valgrind:

	valgrind --leak-check=yes ./libraryAsk1 5 15 10 10

clean: 

	rm -f *.o

	
	

