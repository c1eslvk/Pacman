#include "Game.h"


Tile::Tile(int xPos, int yPos, QGraphicsItem* parent)
	: QGraphicsRectItem(parent)
{
	setRect(0, 0, TILE_SIZE, TILE_SIZE);
	setPos(xPos * TILE_SIZE, yPos * TILE_SIZE);
	QBrush brush;
	brush.setColor(Qt::black);
    setPen(QPen(Qt::blue, 2));
	setBrush(brush);
}

Game::Game(QWidget* parent) : QGraphicsView(parent)
{
	scene = new QGraphicsScene();
	setSceneRect(0, 0, WIDTH * TILE_SIZE, HEIGHT * TILE_SIZE);
	setScene(scene);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setFixedSize(TILE_SIZE * WIDTH, TILE_SIZE * HEIGHT);
	scene->setBackgroundBrush(QBrush(Qt::black, Qt::SolidPattern));

	unsigned int remainingCoins = initLabyrinth();

	addScoreBoard(remainingCoins);

	addBlinky();
	addClyde();
	addInky();
	addPinky();
}

unsigned int Game::initLabyrinth(){
		unsigned int remainingCoins = 0;
		for (int x = 0; x < WIDTH; x++) {
		for (int y = 0; y < HEIGHT; y++) {
			if (tiles[y][x] == wall) {
				scene->addItem(new Tile(x, y));
			}
			if(tiles[y][x] == boost) {
				scene->addItem(new Pickup(x, y, true));
				remainingCoins++;
			}
			if(tiles[y][x] == coin) {
				scene->addItem(new Pickup(x, y, false));
				remainingCoins++;
			}
			if(tiles[y][x] == pacman) {
				pacm = new Pacman(x, y);
				pacm->setFlag(QGraphicsItem::ItemIsFocusable);
				pacm->setFocus();
				scene->addItem(pacm);
			}

		}
	}
	return remainingCoins;
}

void Game::addScoreBoard(unsigned int remainingCoins){
	scoreBoard = new Score(remainingCoins);
	scene->addItem(scoreBoard);
	connect(pacm, SIGNAL(increaseScore(int)), scoreBoard, SLOT(updateScore(int)));
	connect(scoreBoard, SIGNAL(gameWon()), pacm, SLOT(finishGame()));
}

void Game::addBlinky(){
	ghosts[0] = new Blinky(13, 17, BLINKY_PATH, pacm -> moveTimer);
	scene -> addItem(ghosts[0]);
	connect(pacm, SIGNAL(startBoost()), ghosts[0], SLOT(makeBlue()));
	connect(pacm, SIGNAL(endBoost()), ghosts[0], SLOT(makeRegular()));
	connect(pacm, SIGNAL(moved(int, int)), ghosts[0], SLOT(catchPlayerMove(int, int)));
	ghosts[0] -> overwriteDirection(UP);
}

void Game::addClyde(){
	ghosts[1] = new Clyde(14, 17, CLYDE_PATH, pacm -> moveTimer);
	scene -> addItem(ghosts[1]);
	connect(pacm, SIGNAL(startBoost()), ghosts[1], SLOT(makeBlue()));
	connect(pacm, SIGNAL(endBoost()), ghosts[1], SLOT(makeRegular()));
	ghosts[1] -> overwriteDirection(LEFT);
}

void Game::addInky(){
	ghosts[2] = new Inky(15, 17, INKY_PATH, pacm -> moveTimer);
	scene -> addItem(ghosts[2]);
	connect(pacm, SIGNAL(startBoost()), ghosts[2], SLOT(makeBlue()));
	connect(pacm, SIGNAL(endBoost()), ghosts[2], SLOT(makeRegular()));
	connect(pacm, SIGNAL(moved(int, int)), ghosts[2], SLOT(catchPlayerMove(int, int)));
	ghosts[2] -> overwriteDirection(RIGHT);
}

void Game::addPinky(){
    Pinky* pinky = new Pinky(16, 17, PINKY_PATH, pacm -> moveTimer);
	ghosts[3] = pinky;
	scene -> addItem(ghosts[3]);
	connect(pacm, SIGNAL(startBoost()), ghosts[3], SLOT(makeBlue()));
	connect(pacm, SIGNAL(endBoost()), ghosts[3], SLOT(makeRegular()));
	ghosts[3] -> overwriteDirection(DOWN);
	pinky -> assignCompanion(ghosts[0]);
}
