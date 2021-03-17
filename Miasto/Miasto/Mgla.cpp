#include"Mgla.h"
#include"Sciezka.h"

Mgla::Mgla()
: Grafika{Wektor2f{0, 0}, 0}
, wyglad{Sciezka::teksturaMgla()}
{}


void Mgla::rysuj(QPainter& painter) {
    painter.drawPixmap(pozycja.x, pozycja.y, wyglad);
}
