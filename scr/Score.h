#pragma once

#include <QtWidgets/QGraphicsSimpleTextItem>
#include <QtCore/QObject>
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>
#include <QtGui/QBrush>
#include <QtGui/QPen>

#include <Context.h>

class Score : public QGraphicsTextItem {
    private:
    Q_OBJECT
    int score;
    unsigned int remainingCoins;
    void displayScore();

    public:
    Score(unsigned int remainingCoins, QGraphicsItem* parent = 0);

    signals:
    void gameWon();
    
    public slots:
    void updateScore(int score);
};