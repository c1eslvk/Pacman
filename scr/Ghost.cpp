#include "Ghost.h"

Ghost::Ghost(int xCoord, int yCoord, QString ghostTexture, QTimer* playerTimer,QGraphicsItem *parent) : QGraphicsRectItem(parent) {
    this->xCoord = xCoord;
    this->yCoord = yCoord;
    this->xStart = xCoord;
    this->yStart = yCoord;
    this->size = 16;
    setRect(0, 0, this -> size, this -> size);
    this->ghostTexture = ghostTexture;
    // this->ghostCurrentTexture = ghostTexture;
    // setPixmap(QPixmap(ghostCurrentTexture));
    // setBrush(QBrush(ghostColor, Qt::SolidPattern));
    setBrush(QPixmap(ghostTexture));
    setPos(xStart * TILE_SIZE, yStart * TILE_SIZE);
    deathTimer = new QTimer();
    deathTimer->setInterval(DEATH_TIME);
    deathTimer->setSingleShot(true);
    connect(deathTimer, SIGNAL(timeout()), SLOT(setLive()));

    nextDirection = getRandAvDirection();
    nextDirection = NONE;
    connect(playerTimer, SIGNAL(timeout()), this, SLOT(executeMove()));
}

vector<int> Ghost::legalDirections(){
    vector<int> legalDirections;
    for(int i =0; i <= 3; i++){
        if(isMoveValid(i)){
       if((direction + 2)% 4 != i){
            legalDirections.push_back(i);
        }
        }
    }
    return legalDirections;
}

int Ghost::getRandAvDirection(){
    vector <int> directions = legalDirections();
    srand(time(NULL));
    return directions[rand()%directions.size()];
}

void Ghost::move(int direction){
    bool dirSwapPossible = false;
    switch(direction){
        case UP:
            moveBy(0, -speed);
            if(y() == (this -> yCoord - 1) * TILE_SIZE) {
                this -> yCoord--;
                dirSwapPossible = true;
            }
            break;
        case RIGHT:
            moveBy(speed, 0);
            if(x() == (this -> xCoord + 1) * TILE_SIZE) {
                this -> xCoord++;
                dirSwapPossible = true;
            }
            break;
        case DOWN:
            moveBy(0, speed);
            if(y() == (this -> yCoord + 1) * TILE_SIZE){ 
                this -> yCoord++;
                dirSwapPossible = true;
            }
            break;
        case LEFT:
            moveBy(-speed, 0);
            if(x() == (this -> xCoord - 1) * TILE_SIZE){
                this -> xCoord--;
                dirSwapPossible = true;
            }
            break;  
        default:
            break;
    }
    if (dirSwapPossible && !eateable) {
       swapDirections();
    }
}

void Ghost::executeMove(){
    if(eateable && isMoveValid(this -> direction)){
        move(this -> direction);
        if((int) x() % TILE_SIZE == 0 && (int) y()% TILE_SIZE == 0){
            this -> direction = getRandAvDirection();
        }
        return;
    } else if(isMoveValid(this -> nextDirection) && (int) x() % TILE_SIZE == 0 && (int) y()% TILE_SIZE == 0){
        this -> direction = this -> nextDirection;
        this -> nextDirection = NONE;
    }
    if(isMoveValid(this -> direction)){
        move(this -> direction);
    }
}

void Ghost::makeBlue() {
    eateable = true;
    // ghostCurrentTexture = RUNNING_GHOST_PATH;
    // setPixmap(QPixmap(ghostCurrentTexture));
    setBrush(QPixmap(RUNNING_GHOST_PATH));
}

void Ghost::makeRegular() {
    eateable = false;
    // ghostCurrentTexture = ghostTexture;
    setBrush(QPixmap(ghostTexture));
    // setPixmap(QPixmap(ghostCurrentTexture));
    // setPixmap(QPixmap(ghostTexture));
    // setBrush(QBrush(ghostColor, Qt::SolidPattern));
}

bool Ghost::isLive(){
    return this -> live;
}

bool Ghost::isEatable(){
    return this -> eateable;
}

void Ghost::setLive(){
    this -> live = true;
    setPos(xStart * TILE_SIZE, yStart * TILE_SIZE);
    this -> xCoord = xStart;
    this  -> yCoord = yStart;
    direction = getRandAvDirection();
    show();
}


bool Ghost::directionFound(int direction, vector<int> directions){
    return find(directions.begin(), directions.end(), direction) != directions.end();
}

double Ghost::distance(int targetX, int targetY, int currentX, int currentY){
    return sqrt(pow(targetX - currentX, 2) + pow(targetY - currentY, 2));
}
void Ghost::catchPlayerMove(int playerXCoord, int playerYCoord){
    this -> playerXCoord = playerXCoord;
    this -> playerYCoord = playerYCoord;
}

void Ghost::startDeathtimer(){
    this -> deathTimer -> start();
}

void Ghost::setEatable(bool status){
    this -> eateable = status;
}

void Ghost::setAlive(bool status){
    this -> live = status;
}

void Ghost::overwriteDirection(int direction){
    this -> direction = direction;
}

int Ghost::getXCoord(){
    return this -> xCoord;
}

int Ghost::getYCoord(){
    return this -> xCoord;
}

int Ghost::chooseBestDirection(int destX, int destY, int startX, int startY){
    vector <int> directions = legalDirections();
    double upD = MAX_DISTANCE;
    double downD = MAX_DISTANCE;
    double leftD = MAX_DISTANCE;
    double rightD = MAX_DISTANCE;
    if(directionFound(UP, directions)){
        upD = distance(destX, destY, startX, startY-1);

    }
    if(directionFound(LEFT, directions)){
        leftD = distance(destX, destY, startX - 1, startY);
        
    }
    if(directionFound(DOWN, directions)){
        downD = distance(destX, destY, startX, startY+1);
        
    }
    if(directionFound(RIGHT, directions)){
        rightD = distance(destX, destY, startX + 1, startY); 
    }
    double minD = min(upD, min(leftD, min(downD, rightD)));
    if (minD == upD) {
        return UP;
    } else if(leftD == minD){
        return LEFT;
    }
    else if(downD == minD){
        return DOWN;

    }else if(rightD == minD){
       return RIGHT;
    }
    return NONE;
}