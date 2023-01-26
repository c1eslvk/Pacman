#include "Pacman.h"

Pacman::Pacman(int xCoord, int yCoord, QGraphicsItem* parent) : QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(PACMAN_LEFT_PATH));
    setPos(xCoord * TILE_SIZE, yCoord * TILE_SIZE);

    this -> xCoord = xCoord;
    this -> yCoord = yCoord;
    pause = new TextPrompt("PAUSE");
    direction = LEFT;
    nextDirection = NONE;  

    moveTimer = new QTimer();
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(executeMove()));
    boostTimer =  new QTimer();
    boostTimer->setInterval(BOOST_TIME);
    boostTimer->setSingleShot(true);
    connect(boostTimer,SIGNAL(timeout()), SLOT(offBoost()));
    moveTimer->start(FRAMETIME);
}

void Pacman::keyPressEvent(QKeyEvent *pressed){
    switch (pressed -> key())
    {
        case Qt::Key_Up:
            this -> nextDirection = UP;
            setPixmap(QPixmap(PACMAN_UP_PATH));
            break;
        case Qt::Key_Left:
            this -> nextDirection = LEFT;
            setPixmap(QPixmap(PACMAN_LEFT_PATH));
            break;

        case Qt::Key_Down:
            this -> nextDirection = DOWN;
            setPixmap(QPixmap(PACMAN_DOWN_PATH));
            break;
        case Qt::Key_Right:
            this -> nextDirection = RIGHT;
            setPixmap(QPixmap(PACMAN_RIGHT_PATH));
            break;
        case Qt::Key_Escape:
            this -> pauseOrResume();
        break;
    }
}

void Pacman::pauseOrResume(){
    if(this -> isGameRunning){
        moveTimer -> stop();
        isGameRunning = false;
        scene() -> addItem(pause);
    } else {
        moveTimer -> start(FRAMETIME);
        isGameRunning = true;
        scene() -> removeItem(pause);
    }
}

void Pacman::move(int direction) {
    
    if(speed == BOOST_SPEED){
        if((int)x() % BOOST_SPEED == REGULAR_SPEED) moveBy(-REGULAR_SPEED, 0);
        if((int)y() % BOOST_SPEED == REGULAR_SPEED) moveBy(0, -REGULAR_SPEED);
    }
    switch(direction){
        case UP:
            moveBy(0, -speed);
            if(y() == (this -> yCoord - 1) * TILE_SIZE) {
                this -> yCoord--;
                emit moved(xCoord, yCoord);
            }
            break;

        case RIGHT:
            moveBy(speed, 0);
            if(x() == (this -> xCoord + 1) * TILE_SIZE) {
                this -> xCoord++;
                emit moved(xCoord, yCoord);
            }
            break;

        case DOWN:
            moveBy(0, speed);
            if(y() == (this -> yCoord + 1) * TILE_SIZE){ 
                this -> yCoord++;
                emit moved(xCoord, yCoord);
            }
            break;

        case LEFT:
            moveBy(-speed, 0);
            if(x() == (this -> xCoord - 1) * TILE_SIZE){
                this -> xCoord--;
                emit moved(xCoord, yCoord);
            }
            break;
        
        default:
            break;
    }
}

void Pacman::executeMove() {
    this -> determineCollisionWithObjects();
    if(isMoveValid(this -> nextDirection) && (int) x() % TILE_SIZE == 0 && (int) y()% TILE_SIZE == 0){
        this -> direction = this -> nextDirection;
    }
    if(isMoveValid(this -> direction)){
        move(this -> direction);
    }
}

void Pacman::determineCollisionWithObjects() {
    QList<QGraphicsItem*> objects = collidingItems();
    for (auto object : objects){
        if(dynamic_cast<Pickup*>(object) != nullptr){
            handlePickupCollision(object);
        } else if(dynamic_cast<Ghost*>(object) != nullptr){
            handleEnemyCollision(object);
        }
    }
}

void Pacman::offBoost() {
    this -> speed = REGULAR_SPEED;
    emit endBoost();
}

void Pacman::delay()
{
    QTime time = QTime::currentTime().addSecs(EXIT_SCREEN_TIME);
    while (QTime::currentTime() < time){
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
}

void Pacman::finishGame() {
    TextPrompt* win = new TextPrompt("YOU WON");
    moveTimer -> stop();
    scene() -> addItem(win);
    delay();
    QCoreApplication::quit();  
}

void Pacman::handlePickupCollision(QGraphicsItem* object){
    Pickup* newPickup = (Pickup*) object;
    if(newPickup -> isSpecial()){
        this -> scene() -> removeItem(object);
        emit increaseScore(BOOST_POINTS);
        this -> speed = BOOST_SPEED;
        emit startBoost();
        boostTimer -> start();
    } else {
        this -> scene() -> removeItem(object);
        emit increaseScore(COIN_POINTS);
    }
}

void Pacman::handleEnemyCollision(QGraphicsItem* object){
    Ghost* newGhost = (Ghost*) object;
    if(newGhost -> isLive()){
        if (this -> speed == BOOST_SPEED){
                newGhost -> setEatable(false);
                newGhost -> setAlive(false);
                newGhost -> hide();
                newGhost -> startDeathtimer();
            emit increaseScore(GHOST_POINTS);
        } else {
            TextPrompt* failure = new TextPrompt("YOU LOSE");
            scene() -> addItem(failure);
            delay();
            QCoreApplication::quit();     
        }
    }
}