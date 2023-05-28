#include "EndScene.h"
#include "Score.h"
#include "ButtonItem.h"
#include "Game.h"
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QDebug>
#include <QObject>

extern Game *game;

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
    connect(restart, SIGNAL(clicked()), this, SLOT(restart()));
    connect(quit, SIGNAL(clicked()), this, SLOT(quit()));

    addItem(gameOver);
    addItem(restart);
    addItem(quit);
    addItem(win);

}

void EndScene::restart()
{
    qDebug() << "button clicked";
    game->hide();
    Game *game2 = new Game();
    game2->show();
}

void EndScene::quit()
{
    qDebug() << "Button quit clicked";
    game->hide();
}
