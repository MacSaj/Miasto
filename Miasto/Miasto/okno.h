#ifndef OKNO_H
#define OKNO_H

#include<QMainWindow>
#include<QTimer>
#include<QElapsedTimer>

#include<memory>
#include<list>
#include<utility>
#include<memory>

#include"Wierzcholek.h"
#include"Pojazd.h"
#include"PojazdSterownik.h"
#include"Swiatlo.h"
#include"SwiatloSterownik.h"
#include"Mapa.h"
#include"Mgla.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Okno; }
QT_END_NAMESPACE

///Główne okno programu, w którym wyświetlana jest grafika
class Okno : public QMainWindow
{
    Q_OBJECT

public:
    Okno(QWidget *parent = nullptr);
    ~Okno();

public slots:
    void tykniecieZegara();

    void zmienionoPokazGraf(bool wartosc);

    void zmienionoInterwalGeneratora(int wartosc);

protected:
    void paintEvent(QPaintEvent*) override;

private:
    Ui::Okno *ui;

    QTimer zegar;
    QElapsedTimer stoper;

    bool pokazGraf;
    float interwalGeneratora;
    float aktualnyCzas;
    Mapa mapa;
    Mgla mgla;
    std::list<std::pair<std::unique_ptr<Grafika>, std::unique_ptr<Sterownik>>> aktorzy;
};
#endif // OKNO_H
