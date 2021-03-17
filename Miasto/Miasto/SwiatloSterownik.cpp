#include"SwiatloSterownik.h"

SwiatloSterownik::SwiatloSterownik(Swiatlo* _swiatlo, Wierzcholek* _wierzcholek)
: Sterownik{false}
, swiatlo{_swiatlo}
, wierzcholek{_wierzcholek}
, czas{0}
{
    wierzcholek->ustawMoznaZjechac(swiatlo->czyStanZielony());
}

void SwiatloSterownik::wykonajKrok(float czasSekundy) {
    czas += czasSekundy;

    if (czas > 10.0f) {
        czas = 0.0f;

        if (swiatlo->czyStanCzerwony()) {
            swiatlo->ustawStanZielony();
        }
        //zielony
        else {
            swiatlo->ustawStanCzerwony();
        }

        wierzcholek->ustawMoznaZjechac(swiatlo->czyStanZielony());
    }
}
