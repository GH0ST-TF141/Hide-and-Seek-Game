#include "Food.h"
#include <stdlib.h>

Food::Food(QGraphicsItem *parent)
{
    setRect(-25, -25, 50, 50);
    connect(&timer, &QTimer::timeout, this, &Food::moveRandom);
    timer.start(500);
}

Food::~Food()
{
    timer.stop();
}

void Food::moveRandom()
{
    if(x() < 50 || x() > 740 || y() < 50 || y() > 540)
        setPos(rand() % 500 + 50, rand() % 400 + 50);

    setPos(x() + (rand() % 100 - 50), y() + (rand() % 100 - 50));
}
