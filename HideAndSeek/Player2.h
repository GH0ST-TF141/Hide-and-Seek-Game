#ifndef PLAYER2_H
#define PLAYER2_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <vector>
#include <QPainter>

class Player2 : public QGraphicsPixmapItem {
public:
    Player2();
    QRectF boundingRect() const;
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    std::vector<int> activeKeys;
};

#endif // PLAYER2_H
