#include "Player.h"

Player::Player()
{
    setRect(-50, -50, 100, 100);
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    // Add the pressed key to the set of active keys
    activeKeys.insert(event->key());

    // Check for diagonal movement
    if (activeKeys.contains(Qt::Key_Up) && activeKeys.contains(Qt::Key_Left)) {
        moveBy(-10, -10);
    }
    else if (activeKeys.contains(Qt::Key_Up) && activeKeys.contains(Qt::Key_Right)) {
        moveBy(10, -10);
    }
    else if (activeKeys.contains(Qt::Key_Down) && activeKeys.contains(Qt::Key_Left)) {
        moveBy(-10, 10);
    }
    else if (activeKeys.contains(Qt::Key_Down) && activeKeys.contains(Qt::Key_Right)) {
        moveBy(10, 10);
    }
    // Handle individual directions
    else if (event->key() == Qt::Key_Up) {
        if (y() > 50)
            moveBy(0, -10);
    }
    else if (event->key() == Qt::Key_Down) {
        if (y() < 540)
            moveBy(0, 10);
    }
    else if (event->key() == Qt::Key_Left) {
        if (x() > 50)
            moveBy(-10, 0);
    }
    else if (event->key() == Qt::Key_Right) {
        if (x() < 740)
            moveBy(10, 0);
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    // Remove the released key from the set of active keys
    activeKeys.remove(event->key());
}
