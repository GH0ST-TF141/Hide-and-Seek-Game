#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <vector>

class Player : public QGraphicsPixmapItem {
public:
    Player();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    std::vector<int> activeKeys;
};

#endif // PLAYER_H
