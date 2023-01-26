#include <QtWidgets/QGraphicsSimpleTextItem>
#include <QtGui/QFont>
#include <QtGui/QFontDatabase>
#include <QtGui/QBrush>
#include <QtGui/QPen>

#include "Context.h"

using namespace std;

class TextPrompt : public QGraphicsSimpleTextItem {
    public:
    TextPrompt(string prompt, QGraphicsItem* parent = 0);
};