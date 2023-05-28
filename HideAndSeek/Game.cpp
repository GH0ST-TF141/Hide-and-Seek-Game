#include "Game.h"
#include <QGraphicsScene>
#include <stdlib.h>
#include <windows.h>
#include "EndScene.h"

Game::Game(QGraphicsItem *parent) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    player = new Player();
    player2 = new Player();
    player->setPixmap(QPixmap(":images/player.png").scaled(60, 60));
    player2->setPixmap(QPixmap(":images/player2.png").scaled(60, 60));
    food = new Food();
    food->setBrush(Qt::black);
    score1 = new Score("Player1: 0", 10, 10);
    score2 = new Score("Player2: 0", 600, 10);
    forNext = new Score("REMAINING TİME", 300, 0, 15);
    time = new Score("10", 375, 20);
    QGraphicsScene *scene = new QGraphicsScene();
    setScene(scene);
    player->setPos(100, 200);
    player2->setPos(600, 200);
    food->setPos(350, 250);
    scene->setSceneRect(0, 0, 790, 590);
    scene->addItem(player);
    scene->addItem(player2);
    scene->addItem(food);
    scene->addItem(score1);
    scene->addItem(score2);
    scene->addItem(forNext);
    scene->addItem(time);
    scene->setBackgroundBrush(Qt::black);
    setFixedSize(800, 600);

    int remeaningTime = 10;

    QObject::connect(&timer, &QTimer::timeout, [&]() {
        if (player->hasFocus()) {
            player2->setFocus();
        } else if (player2->hasFocus()) {
            player->setFocus();
        }
        remeaningTime = 10;
    });
    timer.start(10000);

    QObject::connect(&rTime, &QTimer::timeout, [&]() {
        time->setPlainText(QString::number(remeaningTime--));
    });
    rTime.start(1000);

    QObject::connect(&timer2, &QTimer::timeout, this, &Game::checkCollision);
    timer2.start(10);
}

void Game::checkCollision() {
    int distancePlayer1 = qSqrt(qPow((player->x() + 30) - food->x(), 2) + qPow((player->y() + 30) - food->y(), 2));
    int distancePlayer2 = qSqrt(qPow((player2->x() + 30) - food->x(), 2) + qPow((player2->y() + 30) - food->y(), 2));

    if (distancePlayer1 <= 50) {
        num1 += 10;
        score1->setPlainText("Player1: " + QString::number(num1));
        food->setPos(rand() % 500 + 50, rand() % 400 + 50);
    }

    if (distancePlayer2 <= 60) {
        num2 += 10;
        score2->setPlainText("Player2: " + QString::number(num2));
        food->setPos(rand() % 500 + 50, rand() % 400 + 50);
    }
    if(num1 == 40 || num2 == 40) {
        QString text;
        if(num1 == 40) {
            text = "Player1 WON!!";
        } else {
            text = "Player2 WON!!";
        }
        timer.stop();
        timer2.stop();
        rTime.stop();
        EndScene *end = new EndScene(text);
        Game::setScene(end);
    }
}
