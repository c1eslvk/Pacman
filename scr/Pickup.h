#pragma once

#include <QtWidgets/QGraphicsEllipseItem>
#include <QtWidgets/QWidget>
#include <QtGui/QPixmap>
#include <QtGui/QBrush>

class Pickup : public QGraphicsEllipseItem {
    private: 
        bool special = false;
    public:
        Pickup(int xPos, int yPos, bool isSpecial, QGraphicsItem *parent = 0);
        bool isSpecial();
};