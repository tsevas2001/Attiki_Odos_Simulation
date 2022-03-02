OBJ_DIR = modules
CC = g++ -g3 -g -std=c++11 

ergasia5: main.o $(OBJ_DIR)/highway.o $(OBJ_DIR)/entrance.o $(OBJ_DIR)/segment.o $(OBJ_DIR)/toll.o $(OBJ_DIR)/vehicle.o

	$(CC) -o project main.o $(OBJ_DIR)/highway.o $(OBJ_DIR)/entrance.o $(OBJ_DIR)/segment.o $(OBJ_DIR)/toll.o $(OBJ_DIR)/vehicle.o

run:

	./project 20 200 2 3 3

valgrind:

	valgrind --leak-check=yes ./ergasia5 5 20 10 10 10

gdb:
	gdb ./ergasia5 5 200 10 10 10

clean: 

	rm -f *.o modules/*.o

	
	

