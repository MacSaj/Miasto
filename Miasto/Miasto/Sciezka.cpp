#include"Sciezka.h"
#include<vector>
#include<QtGlobal>

char const* Sciezka::teksturaSwiatloCzerwone() {
    return ":/dane/swiatlo_czerwone.png";
}

char const* Sciezka::teksturaSwiatloZielone() {
    return ":/dane/swiatlo_zielone.png";
}

char const* Sciezka::teksturaMapa() {
    return ":/dane/mapa.png";
}

char const* Sciezka::teksturaMgla() {
    return ":/dane/mgla.png";
}

char const* Sciezka::losujTeksturePojazdu() {
    static std::vector<char const*> sciezki{
        ":/dane/pojazd1.png",
        ":/dane/pojazd2.png",
        ":/dane/pojazd3.png",
        ":/dane/pojazd4.png",
        ":/dane/pojazd5.png",
        ":/dane/pojazd6.png",
        ":/dane/pojazd7.png",
        ":/dane/pojazd8.png",
        ":/dane/pojazd9.png",
        ":/dane/pojazd10.png",
        ":/dane/pojazd11.png",
    };

    return sciezki[qrand() % sciezki.size()];
}
