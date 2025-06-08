#ifndef ASTEROID_H
#define ASTEROID_H
#include <QGraphicsEllipseItem>
#include <QObject>

class AsteroShatter;  // Forward declaration

class Asteroid : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT
public:
    Asteroid(AsteroShatter* g);

public slots:
    void move();

private:
    AsteroShatter* game;
};

#endif // ASTEROID_H