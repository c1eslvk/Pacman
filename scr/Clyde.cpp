#include "Clyde.h"

void Clyde::swapDirections(){
    vector <int> directions = legalDirections();
    srand(time(NULL));
    nextDirection = directions[rand()%directions.size()];
}