#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include "Player.h"
#include "Food.h"
#include "Score.h"
#include "Player2.h"

class Game : public QGraphicsView {
public:
    Game(QGraphicsItem *parent = nullptr);
public slots:
    inline void checkCollision();
private:
    Player *player;
    Player2 *player2;
    Score *score1;
    Score *score2;
    Score *forNext;
    Score *time;
    Food *food;
    QTimer timer;
    QTimer timer2;
    QTimer rTime;
    int num1 = 0;
    int num2 = 0;
};

#endif // GAME_H
