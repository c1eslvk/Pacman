#include "Pinky.h"

void Pinky::assignCompanion(Ghost* ghost){
    this -> companion = ghost;
}

void Pinky::swapDirections(){
    int destX = this -> companion -> getXCoord() - MAKE_AHEAD;
    int destY = this -> companion -> getYCoord() + MAKE_AHEAD;
    nextDirection = chooseBestDirection(destX, destY, xCoord, yCoord);
}