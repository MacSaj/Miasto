#include"Grafika.h"

Grafika::Grafika(Wektor2f const& _pozycja, float _katStopnie)
: pozycja{_pozycja}
, katStopnie{_katStopnie}
{}

void Grafika::ustawPozycja(Wektor2f const& _pozycja) {
    pozycja = _pozycja;
}

Wektor2f const& Grafika::zwrocPozycja() const {
    return pozycja;
}

Wektor2f& Grafika::zwrocPozycja() {
    return pozycja;
}

void Grafika::ustawKatStopnie(float _katStopnie) {
    katStopnie = _katStopnie;
}

float const& Grafika::zwrocKatStopnie() const {
    return katStopnie;
}

float& Grafika::zwrocKatStopnie() {
    return katStopnie;
}

void Grafika::rysujStrzalke(Wektor2f const& poczatek, Wektor2f const& koniec, QPainter& painter) {
    QPen penRed{QColor{255, 0, 0}, 2};
    painter.setPen(penRed);

    painter.drawLine(poczatek.x, poczatek.y, koniec.x, koniec.y);

    Wektor2f const kierunek = koniec - poczatek;
    Wektor2f const kierunekProstopadly{-kierunek.y, kierunek.x};

    Wektor2f grotPozycja{poczatek + kierunek * 0.7f + kierunekProstopadly * 0.1f};
    painter.drawLine(grotPozycja.x, grotPozycja.y, koniec.x, koniec.y);

    grotPozycja = Wektor2f{poczatek + kierunek * 0.7f + -kierunekProstopadly * 0.1f};
    painter.drawLine(grotPozycja.x, grotPozycja.y, koniec.x, koniec.y);
}
