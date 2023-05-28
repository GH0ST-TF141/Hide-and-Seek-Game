#include "Player.h"
#include <QRectF>
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

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Draw the white circular area
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());

    // Draw the player's pixmap
    QGraphicsPixmapItem::paint(painter, option, widget);
}


QRectF Player::boundingRect() const
{
    // Define the bounding circle based on the player's position and radius
    qreal radius = 120;
    return QRectF(-25 ,-25, radius, radius);
}
