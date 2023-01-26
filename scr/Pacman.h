#pragma once
#include <QtWidgets/QGraphicsPixmapItem>
#include <QtCore/QObject>
#include <QtGui/QBrush>
#include <QtGui/QKeyEvent>
#include <QtCore/QTimer>
#include <QtCore/QTime>
#include <QtCore/QList>
#include <QtWidgets/QGraphicsScene>
#include <QtCore/QCoreApplication>

#include "Context.h"
#include "Moveable.h"
#include "Pickup.h"
#include "Score.h"
#include "Ghost.h"
#include "TextPrompt.h"
#include "unistd.h"
class Pacman : public Moveable, public QGraphicsPixmapItem{
    private:
        Q_OBJECT
        int size = TILE_SIZE - 2;
        int speed = REGULAR_SPEED;
        void move(int direction);
        void keyPressEvent(QKeyEvent *pressed);
        void determineCollisionWithObjects();
        bool isGameRunning = true;
        void pauseOrResume();
        QTimer* boostTimer;
        TextPrompt* pause;
        void delay();
        void handlePickupCollision(QGraphicsItem* object);
        void handleEnemyCollision(QGraphicsItem* object);
    public:
        Pacman(int xCoord, int yCoord, QGraphicsItem* parent = 0);
        QTimer* moveTimer;
    public slots:
        void executeMove();
        void offBoost();
        void finishGame();
    signals:
        void increaseScore(int score);
        void startBoost();
        void endBoost();
        void ghostEaten();
        void moved(int xCoord, int yCoord);
};