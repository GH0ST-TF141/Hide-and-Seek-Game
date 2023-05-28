#include "Player.h"

Player::Player()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player::keyPressEvent(QKeyEvent *event)
{
    // Add the pressed key to the vector of active keys
    if (std::find(activeKeys.begin(), activeKeys.end(), event->key()) == activeKeys.end()) {
        activeKeys.push_back(event->key());
    }

    // Check for diagonal movement
    if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Up) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Left)) {
        moveBy(-10, -10);
    }
    else if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Up) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Right)) {
        moveBy(10, -10);
    }
    else if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Down) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Left)) {
        moveBy(-10, 10);
    }
    else if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Down) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_Right)) {
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
    // Remove the released key from the vector of active keys
    auto it = std::find(activeKeys.begin(), activeKeys.end(), event->key());
    if (it != activeKeys.end()) {
        activeKeys.erase(it);
    }
}
