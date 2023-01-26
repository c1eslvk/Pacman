#include "Blinky.h"

void Blinky::swapDirections(){
    nextDirection = chooseBestDirection(playerXCoord, playerYCoord, xCoord, yCoord);
}
