#ifndef ASTEROSHATTER_H
#define ASTEROSHATTER_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>


#include "player.h"
#include "score.h"
#include "health.h"
#include "Asteroid.h"
#include "Bullet.h"

class AsteroShatter : public QGraphicsView {
    Q_OBJECT
public:
    explicit AsteroShatter(QWidget* parent = nullptr);

    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;
};

#endif // ASTEROSHATTER_H
