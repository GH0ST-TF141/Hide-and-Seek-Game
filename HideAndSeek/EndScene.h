#ifndef ENDSCENE_H
#define ENDSCENE_H

#include <QGraphicsScene>

class EndScene : public QGraphicsScene {
    Q_OBJECT
public:
    EndScene(QString text);
private slots:
    void restart();
    void quit();
};

#endif // ENDSCENE_H
