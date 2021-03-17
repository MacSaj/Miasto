#include"Swiatlo.h"
#include"Stala.h"
#include"Sciezka.h"

Swiatlo::Swiatlo(Wektor2f _pozycja, float _katStapnie, Stan _stan)
: Grafika{_pozycja, _katStapnie}
, stan{_stan}
, wygladCzerwony{Sciezka::teksturaSwiatloCzerwone()}
, wygladZielony{Sciezka::teksturaSwiatloZielone()}
{
    ustawWygladZeStanu();
}

void Swiatlo::ustawStanCzerwony() {
    stan = Stan::czerwony;
    ustawWygladZeStanu();
}

void Swiatlo::ustawStanZielony() {
    stan = Stan::zielony;
    ustawWygladZeStanu();
}

bool Swiatlo::czyStanCzerwony() const {
    return stan == Stan::czerwony;
}

bool Swiatlo::czyStanZielony() const {
    return stan == Stan::zielony;
}

void Swiatlo::rysuj(QPainter& painter) {
    painter.save();
    /*
    Transformacje są wykonywane w odwrotnej kolejności: 4, 3, 2, 1
    4) Najpierw ustalamy środek obrotu na centrum obrazka
    3) Później obracamy obrazek
    2) Wracamy na pozycję początkową
    1) Przenosimy obrazek na miejsce docelowe
    */
    painter.translate(pozycja.x, pozycja.y);                                            //1
    painter.translate(Stala::rozmiarPolowaKafelka(), Stala::rozmiarPolowaKafelka());    //2
    painter.rotate(katStopnie);                                                         //3
    painter.translate(-Stala::rozmiarPolowaKafelka(), -Stala::rozmiarPolowaKafelka());  //4
    painter.drawPixmap(0, 0, *wyglad);
    painter.restore();
}

void Swiatlo::ustawWygladZeStanu() {
    if (czyStanCzerwony()) {
        wyglad = &wygladCzerwony;
    }
    else {
        wyglad = &wygladZielony;
    }
}
