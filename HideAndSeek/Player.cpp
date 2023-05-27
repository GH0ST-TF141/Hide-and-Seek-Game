#include "Player.h"

Player::Player()
{
    setRect(-50, -50, 100, 100);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Up) {
        if(y() > 50)
        setPos(x(), y() - 10);
    }
    if(event->key() == Qt::Key_Down) {
        if(y() < 540 )
        setPos(x(), y() + 10);
    }
    if(event->key() == Qt::Key_Left) {
        if(x() > 50)
        setPos(x() - 10, y());
    }
    if(event->key() == Qt::Key_Right) {
        if(x() < 740)
        setPos(x() + 10, y());
    }
    if (event->key() == Qt::Key_Up && event->key() == Qt::Key_Right) {
        if (y() > 50 && x() < 740)
        setPos(x() + 10, y() - 10);
    }
    if (event->key() == Qt::Key_Up && event->key() == Qt::Key_Left) {
        if (y() > 50 && x() > 50)
        setPos(x() - 10, y() - 10);
    }
    if (event->key() == Qt::Key_Down && event->key() == Qt::Key_Right) {
        if (y() < 540 && x() < 740)
        setPos(x() + 10, y() + 10);
    }
    if (event->key() == Qt::Key_Down && event->key() == Qt::Key_Left) {
        if (y() < 540 && x() > 50)
        setPos(x() - 10, y() + 10);
    }
}
