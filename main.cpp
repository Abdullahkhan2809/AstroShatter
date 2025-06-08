#include <QApplication>
#include "asteroShatter.h"

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    AsteroShatter game;
    return a.exec();
}
