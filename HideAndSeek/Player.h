#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Player : public QGraphicsEllipseItem {
public:
    Player();
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PLAYER_H
