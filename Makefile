INC_DIR = headers
OBJ_DIR = modules
CC = g++ -g3 -g -std=c++11 

ergasia5: main.o $(OBJ_DIR)/highway.o $(OBJ_DIR)/entrance.o $(OBJ_DIR)/segment.o $(OBJ_DIR)/toll.o $(OBJ_DIR)/vehicle.o

	$(CC) -o project main.o $(OBJ_DIR)/highway.o $(OBJ_DIR)/entrance.o $(OBJ_DIR)/segment.o $(OBJ_DIR)/toll.o $(OBJ_DIR)/vehicle.o

main.o: main.cpp

	$(CC) -c main.cpp

entrance.o: $(OBJ_DIR)/entrance.cpp

	$(CC) -c c$(OBJ_DIR)/entrance.cpp

highway.o: $(OBJ_DIR)/highway.cpp

	$(CC) -c c$(OBJ_DIR)/highway.cpp

segment.o: $(OBJ_DIR)/segment.cpp

	$(CC) -c c$(OBJ_DIR)/segment.cpp

toll.o: $(OBJ_DIR)/toll.cpp

	$(CC) -c c$(OBJ_DIR)/toll.cpp

vehicle.o: $(OBJ_DIR)/vehicle.cpp

	$(CC) -c c$(OBJ_DIR)/vehicle.cpp

run:

	./project 20 200 2 3 3

valgrind:

	valgrind --leak-check=yes ./ergasia5 5 20 10 10 10

gdb:
	gdb ./ergasia5 5 200 10 10 10

clean: 

	rm -f *.o modules/*.o

	
	

