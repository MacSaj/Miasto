#include"Wierzcholek.h"
#include"Stala.h"

Wierzcholek::Wierzcholek(Wektor2f const& _pozycja, Typ _typ, Stan _stan)
: Grafika{_pozycja, 0.0f}
, typ{_typ}
, stan{_stan}
, przeszkoda{nullptr}
, moznaZjechac{true}
{}

bool Wierzcholek::czyTypSkrzyzowanie() const {
    return typ == Typ::skrzyzowanie;
}

bool Wierzcholek::czyTypPoczatekTrasy() const {
    return typ == Typ::poczatekTrasy;
}

bool Wierzcholek::czyTypKoniecTrasy() const {
    return typ == Typ::koniecTrasy;
}

void Wierzcholek::ustawStanWolny() {
    stan = Stan::wolny;
    przeszkoda = nullptr;
}

void Wierzcholek::ustawMoznaZjechac(bool wartosc) {
    moznaZjechac = wartosc;
}

bool Wierzcholek::czyMoznaZjechac() const {
    return moznaZjechac;
}

void Wierzcholek::ustawStanZajety(void* _przeszkoda) {
    stan = Stan::zajety;
    przeszkoda = _przeszkoda;
}

bool Wierzcholek::czyStanZajety(void* _przeszkoda) const {
    return stan == Stan::zajety && ((_przeszkoda) ? przeszkoda != _przeszkoda : true);
}

void Wierzcholek::rysuj(QPainter& painter) {
    QPen pen;

    if(!czyMoznaZjechac()) {
        pen.setColor(QColor(255, 140, 0));
        pen.setWidth(15);
    }
    else if(czyStanZajety()) {
        pen.setColor(QColor(255, 255, 255));
        pen.setWidth(15);
    }
    else if (czyTypPoczatekTrasy()) {
        pen.setColor(QColor(255, 255, 0));
        pen.setWidth(30);
    }
    else if (czyTypKoniecTrasy()) {
        pen.setColor(QColor(0, 255, 0));
        pen.setWidth(30);
    }
    else if (czyTypSkrzyzowanie()) {
        pen.setColor(QColor(0, 0, 255));
        pen.setWidth(30);
    }
    else {
        pen.setColor(QColor(0, 0, 255));
        pen.setWidth(15);
    }

    painter.setPen(pen);
    painter.drawPoint(pozycja.x + Stala::rozmiarPolowaKafelka(), pozycja.y + Stala::rozmiarPolowaKafelka());
}
