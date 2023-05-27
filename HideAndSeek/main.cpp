#include "Player.h"
#include "Player2.h"
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTimer>
#include "Food.h"
#include "Score.h"
#include <stdlib.h>
#include "Game.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Game *game = new Game();
    game->show();

    return app.exec();

}
