all: derle bagla calistir

derle:
	g++ -c -I "./include" ./src/Maze.cpp -o ./lib/Maze.o
	g++ -c -I "./include" ./src/main.cpp -o ./lib/main.o
	g++ -c -I "./include" ./src/Konum.cpp -o ./lib/Konum.o

bagla:
	g++ ./lib/Maze.o ./lib/main.o ./lib/Konum.o -o ./bin/program

calistir:
	./bin/program
