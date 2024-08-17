



#ifndef MAZE_HPP
#define MAZE_HPP

#include <fstream>
#include <iomanip>
#include <string>
#include <stack>
#include <vector>
#include "Konum.h"

#define HEIGHT 20
#define WIDTH 50

class Maze {
private:
    std::vector<std::vector<char>> grid;
    Position start, end;
    std::stack<Position> path;
    char directionChars[4] = {'V', '<', '^', '>'}; // Ok karakterleri

    void loadMap(const std::string& filename);
    void findStartAndEnd();
    bool solveMaze();
    Position nextPosition(const Position& pos, Direction dir) const;
    bool isValid(const Position& pos) const;
    void displayMaze() const;

public:
    Maze(const std::string& filename);
    void showSolution();
};

#endif
