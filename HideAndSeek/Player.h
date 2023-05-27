#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsEllipseItem>
#include <QKeyEvent>

class Player : public QGraphicsEllipseItem {
public:
public:
    Player();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    QSet<int> activeKeys;
};

#endif // PLAYER_H

