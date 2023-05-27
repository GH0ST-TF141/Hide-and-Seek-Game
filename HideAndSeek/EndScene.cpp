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
    restart->setPos(180, 400);
    ButtonItem *quit = new ButtonItem("QUIT");
    quit->setPos(180, 300);
    Score *gameOver = new Score("GAME OVER", 100, 0, 30);
    Score *win = new Score(text, 120, 70);
    try {
    QPixmap image(":images/gameover");
        if(image.isNull()) {
            throw std::runtime_error("exception occur!");
        }
        QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(image);
        addItem(pixmapItem);
        //qDebug << "loaded succesfully completed!";
    } catch(std::exception e) {
        //qWarning << e;
    }

    addItem(gameOver);
    addItem(restart);
    addItem(quit);
    addItem(win);
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
