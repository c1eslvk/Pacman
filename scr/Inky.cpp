#include "Inky.h"

void Inky::swapDirections(){
    nextDirection = chooseBestDirection(playerXCoord + MAKE_AHEAD, playerYCoord + MAKE_AHEAD, xCoord, yCoord);
}