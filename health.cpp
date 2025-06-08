#include "Health.h"
#include <QFont>
#include <QApplication>

Health::Health(QGraphicsItem* parent) : QGraphicsTextItem(parent) {
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}

void Health::decrease() {
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2
    if (health == 0) {
		QApplication::quit(); // end the game if health is 0
    }
}

int Health::getHealth() {
    return health;
}   

