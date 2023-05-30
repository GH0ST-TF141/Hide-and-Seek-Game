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
#include <QObject>

class ButtonItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

public:

    ButtonItem(const QString& text, QGraphicsItem* parent = nullptr);

    void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;

    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;

    void mousePressEvent(QGraphicsSceneMouseEvent* event) override;

    ButtonItem operator +(const ButtonItem &other) const;
    ButtonItem(const ButtonItem &other);
signals:
    void clicked();
};


#endif // BUTTONITEM_H
