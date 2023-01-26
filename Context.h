#pragma once
#include "limits.h"

#define TILE_SIZE 20
#define WIDTH 28
#define HEIGHT 36
#define PICKUP_SIZE 7
#define MARGIN(size) ((TILE_SIZE - size) / 2)
#define REGULAR_SPEED 1
#define BOOST_SPEED 2 * REGULAR_SPEED
#define FRAMETIME 10
#define BOOST_TIME 10000
#define DEATH_TIME 3000
#define COIN_POINTS 50
#define BOOST_POINTS 100
#define GHOST_POINTS 200
#define MAX_DISTANCE numeric_limits<double>::max();
#define MAKE_AHEAD 5
#define EXIT_SCREEN_TIME 5
#define PLAYER_X_START 9
#define PLAYER_Y_START 19
#define FONT_PATH "res/font/arcadepi.ttf"
#define PACMAN_UP_PATH "res/sprite/pacman-up.png"
#define PACMAN_DOWN_PATH "res/sprite/pacman-down.png"
#define PACMAN_RIGHT_PATH "res/sprite/pacman-right.png"
#define PACMAN_LEFT_PATH "res/sprite/pacman-left.png"
#define CLYDE_PATH "res/sprite/clyde.png"
#define PINKY_PATH "res/sprite/pinky.png"
#define BLINKY_PATH "res/sprite/blinky.png"
#define INKY_PATH "res/sprite/inky.png"
#define RUNNING_GHOST_PATH "res/sprite/running-ghost.png"



enum objects {
    empty,
    wall,
    boost,
    coin,
    pacman
};

enum directions {
    UP,
    LEFT,
    DOWN,
    RIGHT,
    NONE
};
