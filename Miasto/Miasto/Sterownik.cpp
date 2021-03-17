#include"Sterownik.h"

Sterownik::Sterownik(bool _bezczynny)
: bezczynny{_bezczynny}
{}

void Sterownik::ustawBezczynny(bool wartosc) {
    bezczynny = wartosc;
}

bool const& Sterownik::czyBezczynny() const {
    return bezczynny;
}

bool& Sterownik::czyBezczynny() {
    return bezczynny;
}
