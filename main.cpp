#include <QtGui/QApplication>
#include <QStyleFactory>
#include <QStyle>
#include "test.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Test w;
    a.setStyle(QStyleFactory::create("Plastique"));
    w.show();

    return a.exec();
}
