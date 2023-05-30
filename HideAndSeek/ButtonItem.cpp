#include "ButtonItem.h"
#include "Game.h"

ButtonItem::ButtonItem(const QString &text, QGraphicsItem *parent)
    : QGraphicsRectItem(parent)
{
    setRect(0, 0, 100, 50); // Set the size of the button
    QGraphicsTextItem* buttonTextItem = new QGraphicsTextItem(text, this);
    buttonTextItem->setFont(QFont("Arial", 12)); // Set the font for the button text
    buttonTextItem->setPos(rect().center().x() - buttonTextItem->boundingRect().width() / 2,
                           rect().center().y() - buttonTextItem->boundingRect().height() / 2);

    setAcceptHoverEvents(true); // Enable hover events to change button appearance
}

void ButtonItem::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    // Change button appearance on hover
    setBrush(Qt::lightGray);
}

void ButtonItem::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    // Restore button appearance
    setBrush(Qt::white);
}

void ButtonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

ButtonItem ButtonItem::operator+(const ButtonItem& other) const
{
    ButtonItem newItem("", nullptr);
    newItem.setRect(rect().x() + other.rect().x(),
                    rect().y() + other.rect().y(),
                    rect().width() + other.rect().width(),
                    rect().height() + other.rect().height());

    return newItem;
}

ButtonItem::ButtonItem(const ButtonItem& other)
    : QGraphicsRectItem(other.parentItem())
{
    setRect(other.rect());

}
