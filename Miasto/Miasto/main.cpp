#include "okno.h"

#include<QApplication>
#include<QPainter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Okno o;
    o.show();
    return a.exec();
}
