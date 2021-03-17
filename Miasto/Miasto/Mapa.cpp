#include"Mapa.h"
#include"Sciezka.h"

Mapa::Mapa()
: Grafika{Wektor2f{0, 0}, 0}
, tlo{Sciezka::teksturaMapa()}
{}

void Mapa::rysuj(QPainter& painter) {
    //ustawiamy początek układu współrzędnych
    painter.translate(pozycja.x, pozycja.y);

    painter.drawPixmap(0, 0, tlo);
}
