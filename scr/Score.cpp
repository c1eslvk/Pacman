#include "Score.h"

void Score::displayScore(){
    setPlainText("Score: " + QString::number((unsigned int)this -> score));
}

Score::Score(unsigned int remainingCoins, QGraphicsItem* parent) {
    this -> score = 0;
    this -> remainingCoins = remainingCoins;
    int id = QFontDatabase::addApplicationFont(FONT_PATH);
    QFont font;
    font = QFont(QFontDatabase::applicationFontFamilies(id).at(0), 22, 0);
    setFont(font);
    setDefaultTextColor(Qt::white);
    displayScore();
}

void Score::updateScore(int score) {
    this -> score += score;
    if(score == COIN_POINTS || score == BOOST_POINTS){
        remainingCoins--;
    }
    if (remainingCoins == 0){
        emit gameWon();
    }
    displayScore();
}