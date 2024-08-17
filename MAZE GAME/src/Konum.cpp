

#include "Konum.h"

Position Position::move(Direction direction) const {
    switch (direction) {
        case DOWN: return Position(row + 1, col, DOWN);
        case LEFT: return Position(row, col - 1, LEFT);
        case UP: return Position(row - 1, col, UP);
        case RIGHT: return Position(row, col + 1, RIGHT);
        default: return *this;
    }
}

Position Position::oppositeDirection() const {
    switch (dir) {
        case DOWN: return Position(row, col, UP);
        case UP: return Position(row, col, DOWN);
        case LEFT: return Position(row, col, RIGHT);
        case RIGHT: return Position(row, col, LEFT);
        default: return *this;
    }
}
