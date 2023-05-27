#ifndef ENDSCENE_H
#define ENDSCENE_H
#include <QGraphicsScene>

class EndScene : public QGraphicsScene {
public:
    EndScene(QString text);
    void restart();
    void quit();
};

#endif // ENDSCENE_H
