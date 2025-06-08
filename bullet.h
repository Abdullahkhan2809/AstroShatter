#pragma once
#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>

#include <QTimer>

#include <QGraphicsRectItem> 
#include <QPointF>
class AsteroShatter;

class Bullet : public QObject, public QGraphicsRectItem {
    Q_OBJECT
public:
	Bullet(AsteroShatter* g, QPointF startPos);  // Constructor with game pointer


  
public slots:
    void move();
private:
    AsteroShatter* game;
};

#endif // BULLET_H