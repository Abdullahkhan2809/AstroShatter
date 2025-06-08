#include "player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QPolygonF>
#include <QBrush>
#include <QPen>
#include "Bullet.h"
#include "Asteroid.h"
#include "AsteroShatter.h"

Player::Player(AsteroShatter* g, QGraphicsItem* parent) : QObject(), QGraphicsPolygonItem(parent) {
    game = g;

    // Create triangle shape
    setPolygon(createTriangleShape());
    setBrush(QBrush(Qt::blue));
    setPen(QPen(Qt::darkBlue, 2));

    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

QPolygonF Player::createTriangleShape() {
    QPolygonF triangle;
    // Create an upward-pointing triangle
    triangle << QPointF(25, 0)    // Top point
        << QPointF(0, 50)    // Bottom left
        << QPointF(50, 50);  // Bottom right
    return triangle;
}

void Player::keyPressEvent(QKeyEvent* event) {
    int step = 10;
    if (event->key() == Qt::Key_Left && x() - step >= 0) {
        setPos(x() - step, y());
    }
    else if (event->key() == Qt::Key_Right && x() + boundingRect().width() + step <= scene()->width()) {
        setPos(x() + step, y());
    }
    else if (event->key() == Qt::Key_Space) {
        // Calculate bullet position from the tip of the triangle
        QPointF bulletPos(x() + boundingRect().width() / 2 - 5, y());
        Bullet* bullet = new Bullet(game, bulletPos);
        scene()->addItem(bullet);
    }
}

void Player::spawn() {
    Asteroid* asteroid = new Asteroid(game);
    scene()->addItem(asteroid);
}