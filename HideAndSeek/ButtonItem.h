#ifndef BUTTONITEM_H
#define BUTTONITEM_H
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QGraphicsSceneMouseEvent>
#include <QMouseEvent>
#include <QFont>
#include <QDebug>

class ButtonItem : public QGraphicsRectItem
{
public:
    ButtonItem(const QString& text, QGraphicsItem* parent = nullptr);

    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
};


#endif // BUTTONITEM_H
