#pragma once
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsRectItem>
#include <QtCore/QObject>

#include "Context.h"
#include "Pickup.h"
#include "Pacman.h"
#include "Labyrinth.h"
#include "Score.h"
#include "Ghost.h"
#include "Clyde.h"
#include "Blinky.h"
#include "Inky.h"
#include "Pinky.h"

using namespace std;

class Tile : public QGraphicsRectItem 
{
  public:
    Tile(int xPos, int yPos, QGraphicsItem* parent = 0);
};

class Game : public QGraphicsView
{   
  public:
    Game(QWidget* parent = 0);
    QGraphicsScene * scene;
    Pacman* pacm;
    Score* scoreBoard; 
    Ghost* ghosts[4];
    unsigned int initLabyrinth();
    void addScoreBoard(unsigned int remainginCoins);
    void addBlinky();
    void addInky();
    void addPinky();
    void addClyde();
};
