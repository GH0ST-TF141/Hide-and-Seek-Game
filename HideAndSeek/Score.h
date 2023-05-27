#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QString>

class Score : public QGraphicsTextItem {
public:
    Score(QString text, int x, int y, int font = 20);
};

#endif // SCORE_H
