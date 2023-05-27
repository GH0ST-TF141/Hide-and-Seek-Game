#include "Player2.h"

Player2::Player2()
{
    setRect(-50, -50, 100, 100);
    setFlag(QGraphicsItem::ItemIsFocusable);
   }

void Player2::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_W) {
        if(y() > 50)
            setPos(x(), y() - 10);
    }
    if(event->key() == Qt::Key_S) {
        if(y() < 540 )
            setPos(x(), y() + 10);
    }
    if(event->key() == Qt::Key_A) {
        if(x() > 50)
            setPos(x() - 10, y());
    }
    if(event->key() == Qt::Key_D) {
        if(x() < 740)
            setPos(x() + 10, y());
    }
}
