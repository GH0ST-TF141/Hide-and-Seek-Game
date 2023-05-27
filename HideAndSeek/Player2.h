#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Player2 : public QGraphicsEllipseItem {
public:
    Player2();
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PLAYER_H
