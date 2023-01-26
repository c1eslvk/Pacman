#include "Context.h"
#include "Pickup.h"

Pickup::Pickup(int xPos, int yPos, bool isSpecial, QGraphicsItem *parent){
    this -> special = isSpecial;
    if (isSpecial){
        setRect(0, 0, 2 * PICKUP_SIZE, 2 * PICKUP_SIZE);
        setPos(xPos * TILE_SIZE + MARGIN(2 * PICKUP_SIZE), yPos * TILE_SIZE+ MARGIN(2 * PICKUP_SIZE));
        QBrush brush;
        brush.setColor(Qt::white);
        brush.setStyle(Qt::SolidPattern);
        setBrush(brush);
    } else {
        setRect(0, 0, PICKUP_SIZE, PICKUP_SIZE);
        setPos(xPos * TILE_SIZE + MARGIN(PICKUP_SIZE), yPos * TILE_SIZE + MARGIN(PICKUP_SIZE));
        QBrush brush;
        brush.setColor(Qt::yellow);
        brush.setStyle(Qt::SolidPattern);
        setBrush(brush);
    }
}

bool Pickup::isSpecial(){
    return this -> special;
}