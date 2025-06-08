#include "AsteroShatter.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QBrush>
#include "Player.h"

AsteroShatter::AsteroShatter(QWidget* parent) : QGraphicsView(parent) {
    // Create and set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    // Set a simple dark background color instead of image
    setBackgroundBrush(QBrush(Qt::black));
    setScene(scene);

    // Configure the view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);

    // Create and position the player
    Player* player = new Player(this);
    player->setPos(scene->width() / 2 - player->boundingRect().width() / 2,
        scene->height() - player->boundingRect().height() - 10);
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    player->game = this;
    scene->addItem(player);

    // Create score display
    score = new Score();
    scene->addItem(score);

    // Create health display
    health = new Health();
    health->setPos(0, 25);
    scene->addItem(health);

    // Set up timer to spawn asteroids
    QTimer* spawnTimer = new QTimer(this);
    connect(spawnTimer, &QTimer::timeout, player, &Player::spawn);
    spawnTimer->start(2000);

    // Show the game window
    show();
}