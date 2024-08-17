

#ifndef KONUM_HPP
#define KONUM_HPP

enum Direction { DOWN, LEFT, UP, RIGHT };

class Position {
public:
    int row, col;
    Direction dir;

    Position(int r = 0, int c = 0, Direction d = DOWN) : row(r), col(c), dir(d) {}

    Position move(Direction direction) const;
    Position oppositeDirection() const;
};

#endif
