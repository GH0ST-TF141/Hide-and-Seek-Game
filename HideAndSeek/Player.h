#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <vector>
#include <QPainter>

class Player : public QGraphicsPixmapItem {
public:
    Player();
    QRectF boundingRect() const;
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    std::vector<int> activeKeys;
};

#endif // PLAYER_H
