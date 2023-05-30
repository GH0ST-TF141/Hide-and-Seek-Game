#include "player2.h"
#include <QRectF>

Player2::Player2()
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

void Player2::keyPressEvent(QKeyEvent *event)
{
    // Add the pressed key to the vector of active keys
    if (std::find(activeKeys.begin(), activeKeys.end(), event->key()) == activeKeys.end()) {
        activeKeys.push_back(event->key());
    }

    // Check for diagonal movement
    if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_W) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_A)) {
        moveBy(-10, -10);
    }
    else if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_W) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_D)) {
        moveBy(10, -10);
    }
    else if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_S) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_A)) {
        moveBy(-10, 10);
    }
    else if (std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_S) && std::count(activeKeys.begin(), activeKeys.end(), Qt::Key_D)) {
        moveBy(10, 10);
    }
    // Handle individual directions
    else if (event->key() == Qt::Key_W) {
        if (y() > 50)
            moveBy(0, -10);
    }
    else if (event->key() == Qt::Key_S) {
        if (y() < 540)
            moveBy(0, 10);
    }
    else if (event->key() == Qt::Key_A) {
        if (x() > 50)
            moveBy(-10, 0);
    }
    else if (event->key() == Qt::Key_D) {
        if (x() < 740)
            moveBy(10, 0);
    }
}

void Player2::keyReleaseEvent(QKeyEvent *event)
{
    // Remove the released key from the vector of active keys
    auto it = std::find(activeKeys.begin(), activeKeys.end(), event->key());
    if (it != activeKeys.end()) {
        activeKeys.erase(it);
    }
}

void Player2::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Draw the white circular area
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::white);
    painter->drawEllipse(boundingRect());

    // Draw the player's pixmap
    QGraphicsPixmapItem::paint(painter, option, widget);
}


QRectF Player2::boundingRect() const
{
    // Define the bounding circle based on the
    qreal radius = 120;
    return QRectF(-25, -25, radius, radius);
}
