#pragma once

#include <QtWidgets/QGraphicsPixmapItem>
#include "Moveable.h"
#include "Context.h"
#include "cmath"
#include <QtGui/QBrush>
#include <QtCore/QTimer>
#include <vector>

using namespace std;
class Ghost : public Moveable, public QGraphicsRectItem {
    Q_OBJECT
    public:
        Ghost(int xCoord, int yCoord, QString path, QTimer* playerTimer, QGraphicsItem *parent = 0);
        bool isLive();
        bool isEatable();
        void startDeathtimer();
        void setEatable(bool status);
        void setAlive(bool status);
        void overwriteDirection(int direction);
        int getXCoord();
        int getYCoord();
        int speed = REGULAR_SPEED;
    private:
        int xStart;
        int yStart; 
        bool live = true;
        bool eateable = false;
        int size;
        void move(int direction);
        QString ghostTexture;
        QString ghostCurrentTexture;
        QTimer* deathTimer;
    protected:
        int chooseBestDirection(int destX, int destY, int startX, int startY);
        int getRandAvDirection();
        int playerXCoord = PLAYER_X_START;
        int playerYCoord = PLAYER_Y_START;
        virtual void swapDirections() = 0;
        vector <int> legalDirections();
        double distance(int targetX, int targetY, int currentX, int currentY);
        bool directionFound(int direction, vector<int> directions);
    public slots:
        void makeBlue();
        void makeRegular();
        void executeMove();
        void setLive();
        void catchPlayerMove(int playerXCoord, int playerYCoord);
};