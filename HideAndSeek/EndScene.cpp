#include "EndScene.h"
#include "Score.h"
#include "ButtonItem.h"
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>

EndScene::EndScene(QString text)
{
    setSceneRect(0, 0, 800, 600);
    ButtonItem *restart = new ButtonItem("RESTART");
    restart->setPos(100, 400);
    ButtonItem *quit = new ButtonItem("QUIT");
    quit->setPos(100, 300);
    Score *gameOver = new Score("GAME OVER", 100, 50, 30);
    Score *win = new Score(text, 120, 100);

    try {
        QPixmap image(":images/gameover");
        if (image.isNull()) {
            throw std::runtime_error("exception occur!");
        }
        QPixmap scaledImage = image.scaled(790, 590);
        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(scaledImage);
        addItem(pixmapItem);
        qDebug() << "loaded successfully completed!";
    } catch(std::exception& e) {
        qWarning() << e.what();
    }

    addItem(gameOver);
    addItem(restart);
    addItem(quit);
    addItem(win);

    // Connect the buttons to their respective slots
}

void EndScene::restart()
{
    Game *game = new Game();
    game->show();
}

void EndScene::quit()
{
    this->clear();
}
