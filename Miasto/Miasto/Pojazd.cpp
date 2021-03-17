#include"Pojazd.h"
#include"Stala.h"

Pojazd::Pojazd(char const* sciezkaTeksturyPojazdu, Wektor2f _pozycja, float _katStapnie)
: Grafika{_pozycja, _katStapnie}
, wyglad{sciezkaTeksturyPojazdu}
{}

void Pojazd::rysuj(QPainter& painter) {
    painter.save();

    painter.translate(pozycja.x, pozycja.y);                                            //1
    painter.translate(Stala::rozmiarPolowaKafelka(), Stala::rozmiarPolowaKafelka());    //2
    painter.rotate(katStopnie);                                                         //3
    painter.translate(-Stala::rozmiarPolowaKafelka(), -Stala::rozmiarPolowaKafelka());  //4
    painter.drawPixmap(0, 0, wyglad);
    painter.restore();
}
