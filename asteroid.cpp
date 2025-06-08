#include "Asteroid.h"
#include "AsteroShatter.h"
#include <QTimer>
#include <QGraphicsScene>
#include <cstdlib>
#include <QBrush>

Asteroid::Asteroid(AsteroShatter* g) : QGraphicsEllipseItem() {
    game = g;

    // Create a gray ellipse for the asteroid
    int size = 40;
    setRect(0, 0, size, size);
    setBrush(QBrush(Qt::gray));
    setPen(QPen(Qt::darkGray, 2));

    // Set random starting position
    int random_x = rand() % 700;
    setPos(random_x, 0);

    // Set up movement timer
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Asteroid::move);
    timer->start(50);
}

void Asteroid::move() {
    setPos(x(), y() + 5);
    if (pos().y() > 600) {
        if (game && game->health) {
            game->health->decrease();
        }
        scene()->removeItem(this);
        delete this;
    }
}