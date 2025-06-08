#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPolygonItem>
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsItem>

class AsteroShatter;

class Player : public QObject, public QGraphicsPolygonItem {
    Q_OBJECT
public:
    Player(AsteroShatter* game, QGraphicsItem* parent = nullptr);
    void keyPressEvent(QKeyEvent* event);
    AsteroShatter* game;

public:
    void spawn();

private:
    QPolygonF createTriangleShape();
};

#endif // PLAYER_H