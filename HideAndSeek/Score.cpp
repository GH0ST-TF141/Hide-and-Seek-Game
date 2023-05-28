#include "Score.h"
#include <QFont>

Score::Score(QString text, int x, int y, int font)
{
    setPos(x, y);
    QFont appearance;
    appearance.setFamily("Arial");
    appearance.setPointSize(font);
    appearance.setBold(true);
    setDefaultTextColor(Qt::white);
    setFont(appearance);
    setPlainText(text);
}
