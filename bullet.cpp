#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include "Asteroid.h"
#include "AsteroShatter.h"
#include <QPainter>
#include <QGraphicsRectItem>

Bullet::Bullet(AsteroShatter* g, QPointF startPos) {
    game = g;
    // Draw the bullet rectangle
    setRect(0, 0, 10, 15); // Make bullet smaller and more visible
    setBrush(QBrush(Qt::yellow)); // Make bullet yellow so it's visible

    // Set the bullet's position
    setPos(startPos);

    // Connect timer to move slot
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Bullet::move);
    timer->start(50);
}

void Bullet::move() {
    QList<QGraphicsItem*> colliding_items = collidingItems();
    for (QGraphicsItem* item : colliding_items) {
        Asteroid* asteroid = qgraphicsitem_cast<Asteroid*>(item);
        if (asteroid) {
            if (scene()) {
                scene()->removeItem(asteroid);
                scene()->removeItem(this);
            }
            delete asteroid;
            if (game && game->score) {
                game->score->increase();
            }
            this->deleteLater();
            return;
        }
    }
    setPos(x(), y() - 10);
    if (pos().y() + rect().height() < 0) {
        if (scene()) {
            scene()->removeItem(this);
        }
        this->deleteLater();
    }
}