#pragma once
#include "Context.h"
#include "Labyrinth.h"
#include <QtCore/QObject>

class Moveable : public QObject {
    
    Q_OBJECT
    protected:
    int xCoord;
    int yCoord;
    int direction = LEFT;
    int nextDirection = NONE;
    bool isMoveValid(int direction);
    virtual void move(int direction) = 0;
    public slots:
    virtual void executeMove() = 0;
};
