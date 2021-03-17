#include "okno.h"
#include "ui_okno.h"
#include<QPainter>

#include"Graf.h"
#include"Sciezka.h"

Okno::Okno(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Okno)

    , pokazGraf{false}
    , interwalGeneratora{1}
    , aktualnyCzas{0}
    , mapa{}
    , mgla{}
{
    ui->setupUi(this);

    std::unique_ptr<Swiatlo> swiatlo1{new Swiatlo{Graf::wierszKolumnaNaPozycje(8, 7), -90.0f}};
    std::unique_ptr<Sterownik> sterownik1{
        new SwiatloSterownik{swiatlo1.get(), Graf::wierszKolumnaNaWierzcholek(9, 7)}
    };
    aktorzy.emplace_back(std::move(swiatlo1), std::move(sterownik1));

    std::unique_ptr<Swiatlo> swiatlo2{
        new Swiatlo{Graf::wierszKolumnaNaPozycje(8, 4), 180.0f, Swiatlo::Stan::czerwony}
    };
    std::unique_ptr<Sterownik> sterownik2{
        new SwiatloSterownik{swiatlo2.get(), Graf::wierszKolumnaNaWierzcholek(8, 5)}
    };
    aktorzy.emplace_back(std::move(swiatlo2), std::move(sterownik2));

    std::unique_ptr<Swiatlo> swiatlo3{
        new Swiatlo{Graf::wierszKolumnaNaPozycje(11, 7), 0.0f, Swiatlo::Stan::czerwony}
    };
    std::unique_ptr<Sterownik> sterownik3{
        new SwiatloSterownik{swiatlo3.get(), Graf::wierszKolumnaNaWierzcholek(11, 6)}
    };
    aktorzy.emplace_back(std::move(swiatlo3), std::move(sterownik3));


    connect(&zegar, &QTimer::timeout, this, &Okno::tykniecieZegara);
    connect(
        ui->interwalGeneratora, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &Okno::zmienionoInterwalGeneratora
    );
    connect(ui->pokazGraf, &QCheckBox::clicked, this, &Okno::zmienionoPokazGraf);

    zegar.start(25);
    stoper.start();
}

Okno::~Okno()
{
    delete ui;
}

void Okno::paintEvent(QPaintEvent*)
{
    QPainter painter;
    painter.begin(this);

    mapa.rysuj(painter);

    if (pokazGraf) {
        Graf::rysuj(painter);
    }

    for (auto& para : aktorzy) {
        auto& grafika = para.first;
        grafika->rysuj(painter);
    }

    mgla.rysuj(painter);

    painter.end();
}

void Okno::tykniecieZegara() {
    int const fps = 1000 / stoper.elapsed();
    float const sekundy = stoper.elapsed() / 1000.0f;

    ui->fps->setText(QString::number(fps));
    aktualnyCzas += sekundy;

    if (interwalGeneratora <= aktualnyCzas) {
        aktualnyCzas = 0;
        int const poczatek = Graf::losujPoczatekTrasy();
        Wierzcholek* wierzcholek = Graf::indeksNaWierzcholek(poczatek);

        if (!wierzcholek->czyStanZajety()) {
            int const koniec = Graf::losujKoniecTrasy();
            std::unique_ptr<Pojazd> pojazd{
                new Pojazd{Sciezka::losujTeksturePojazdu(), wierzcholek->zwrocPozycja(), 0.0f}
            };
            std::unique_ptr<PojazdSterownik> sterownik{
                new PojazdSterownik{pojazd.get(), Graf::wyznaczTrase(poczatek, koniec)}
            };
            aktorzy.emplace_back(std::move(pojazd), std::move(sterownik));
        }
    }

    for (auto it = aktorzy.begin(); it != aktorzy.end(); ) {
        auto& sterownik = it->second;

        if (sterownik->czyBezczynny()) {
            it = aktorzy.erase(it);
        }
        else {
            sterownik->wykonajKrok(sekundy);
            ++it;
        }
    }

    stoper.restart();
    update();
}

void Okno::zmienionoPokazGraf(bool wartosc) {
    pokazGraf = wartosc;
}

void Okno::zmienionoInterwalGeneratora(int wartosc) {
    interwalGeneratora = wartosc;
}
