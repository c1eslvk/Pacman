#include "Moveable.h"

bool Moveable::isMoveValid(int direction) {
    if (direction == NONE) return false;
    switch (direction) {
        case UP:
            if (tiles[this -> yCoord - 1][this ->xCoord] == 1 ) return false;
            break;
        case LEFT:
            if (tiles[this -> yCoord][this ->xCoord - 1] == 1) return false;
            break;
        case DOWN:
            if (tiles[this -> yCoord + 1][this ->xCoord] == 1) return false;
            break;
        case RIGHT:
            if (tiles[this -> yCoord][this ->xCoord + 1] == 1) return false;
            break;
        default:
            break;
    }
    return true;
}