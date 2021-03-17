#include"PojazdSterownik.h"
#include<cmath>

PojazdSterownik::PojazdSterownik(Pojazd* _pojazd, std::vector<Wierzcholek*> const& _trasa)
: Sterownik{false}
, pojazd{_pojazd}
, trasa{_trasa}
, stan{Stan::ustawPunktDocelowy}
{
    trasa.back()->ustawStanZajety(pojazd);
}

void PojazdSterownik::wykonajKrok(float czasSekundy) {
    if (stan == Stan::ustawPunktDocelowy && trasa.back()->czyMoznaZjechac()) {
        int index = trasa.size() - 2;
        bool ruchDozwolny = false;
        //szukamy komórki, która nie jest skrzyżowaniem i sprawdzamy, czy jest wolna
        while (index > -1) {
            if (trasa[index]->czyTypSkrzyzowanie()) {
                if (trasa[index]->czyStanZajety(pojazd)) {
                    break;
                }
            }
            else {
                ruchDozwolny = !trasa[index]->czyStanZajety(pojazd);
                break;
            }
            --index;
        }

        if (ruchDozwolny) {
            while (index < static_cast<int>(trasa.size())) {
                trasa[index]->ustawStanZajety(pojazd);
                ++index;
            }
            trasa.back()->ustawStanWolny();
            trasa.pop_back();
            stan = Stan::ustawKierunekJazdy;
        }
    }
    else if (stan == Stan::ustawKierunekJazdy) {
        Wektor2f kierunek = trasa.back()->zwrocPozycja() - pojazd->zwrocPozycja();
        float katRadiany = atan2(kierunek.y, kierunek.x) + 3.14f / 2.0f;
        pojazd->ustawKatStopnie(katRadiany * 180.0f / 3.14f);
    }

    if (5.0f < odleglosc(pojazd->zwrocPozycja(), trasa.back()->zwrocPozycja())) {
        Wektor2f kierunek = normalizuj(trasa.back()->zwrocPozycja() - pojazd->zwrocPozycja());
        pojazd->ustawPozycja(pojazd->zwrocPozycja() + 40 * czasSekundy * kierunek);
    }
    else if (1 < trasa.size()) {
        stan = Stan::ustawPunktDocelowy;
    }
    else {
        stan = Stan::koniecTrasy;
        trasa.back()->ustawStanWolny();
        ustawBezczynny(true);
    }
}
