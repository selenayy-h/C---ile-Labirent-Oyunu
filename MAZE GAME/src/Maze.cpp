

#include "Maze.h"
#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

Maze::Maze(const std::string& filename) {
    loadMap(filename);
    findStartAndEnd();
}

void Maze::loadMap(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;

    grid.resize(HEIGHT, std::vector<char>(WIDTH, '#'));
    int row = 0;

    while (std::getline(file, line) && row < HEIGHT) {
        for (int col = 0; col < WIDTH && col < line.size(); ++col) {
            grid[row][col] = line[col];
        }
        ++row;
    }
}

void Maze::findStartAndEnd() {
    for (int col = 0; col < WIDTH; ++col) {
        if (grid[0][col] == ' ') {
            start = Position(0, col);
            break;
        }
    }
    for (int col = 0; col < WIDTH; ++col) {
        if (grid[HEIGHT - 1][col] == ' ') {
            end = Position(HEIGHT - 1, col);
            break;
        }
    }
}

bool Maze::solveMaze() {
    path.push(start);

    while (!path.empty()) {
        Position current = path.top();
        path.pop();

        if (current.row == end.row && current.col == end.col) {
            return true;
        }

        // Yön belirleyici ok karakterini göstermek için kullanılır
        grid[current.row][current.col] = directionChars[current.dir];

        displayMaze();
        std::this_thread::sleep_for(std::chrono::milliseconds(200)); // Hareket hızını ayarla

        bool moved = false;
        for (int i = 0; i < 4; ++i) {
            Position next = nextPosition(current, static_cast<Direction>(i));
            if (isValid(next)) {
                path.push(next);
                moved = true;
                break;
            }
        }

        if (!moved) {
            // Eğer hiçbir yere gidilemiyorsa, geri dönülecek
            grid[current.row][current.col] = ' '; // Boşluk olarak işaretle
        }
    }

    return false;
}

Position Maze::nextPosition(const Position& pos, Direction dir) const {
    return pos.move(dir);
}

bool Maze::isValid(const Position& pos) const {
    return pos.row >= 0 && pos.row < HEIGHT && pos.col >= 0 && pos.col < WIDTH &&
           (grid[pos.row][pos.col] == ' ' || grid[pos.row][pos.col] == 'E');
}

void Maze::displayMaze() const {
    std::cout << "\033[2J\033[1;1H"; // Ekranı temizle
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}

void Maze::showSolution() {
    grid[start.row][start.col] = 'S';
    grid[end.row][end.col] = 'E';

    if (solveMaze()) {
        std::cout << "Solution found!" << std::endl;
        displayMaze();
    } else {
        std::cout << "Solution not found!" << std::endl;
    }
}
