#ifndef FOOD_H
#define FOOD_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QTimer>

class Food : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    Food(QGraphicsItem *parent = nullptr);
    ~Food();

public slots:
    void moveRandom();

private:
    QTimer timer;
};

#endif // FOOD_H
