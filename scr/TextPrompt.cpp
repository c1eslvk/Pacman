#include "TextPrompt.h"

TextPrompt::TextPrompt(string prompt, QGraphicsItem* parent){
    int id = QFontDatabase::addApplicationFont(FONT_PATH);
    QFont font;
    font = QFont(QFontDatabase::applicationFontFamilies(id).at(0), 22, 0);
    setBrush(QBrush(Qt::red));
    setPen(QPen(Qt::red));
    setFont(font);
    setText(QString::fromStdString(prompt));
    setY(HEIGHT * TILE_SIZE /2);
    setX(WIDTH * TILE_SIZE /2 - boundingRect().width()/2);
}