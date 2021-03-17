#ifndef WIERZCHOLEK_H
#define WIERZCHOLEK_H

#include"Grafika.h"

///Graficzna reprezentacja wierzchołka
class Wierzcholek : public Grafika {
public:
    ///Typ nawierzchni przypisany do wierzchołka
    enum class Typ {
        droga,
        skrzyzowanie,
        poczatekTrasy,
        koniecTrasy
    };

    ///Aktualny stan wierzchołka
    enum class Stan {
        zajety,
        wolny
    };

    ///Ustawia wartości początkowe pól klasy
    explicit Wierzcholek(Wektor2f const& _pozycja, Typ _typ = Typ::droga, Stan _stan = Stan::wolny);

    /**
    * \brief Generuje graficzną reprezentację wierzchołka w oknie
    * \param[in] painter obiekt, który generuje grafikę
    */
    void rysuj(QPainter& painter) override;

    ///Testuje stan obiektu
    bool czyTypSkrzyzowanie() const;

    ///Testuje stan obiektu
    bool czyTypPoczatekTrasy() const;

    ///Testuje stan obiektu
    bool czyTypKoniecTrasy() const;

    ///Ustawia nową wartość pola klasy
    void ustawStanWolny();

    ///Ustawia nową wartość pola klasy
    void ustawMoznaZjechac(bool wartosc);

    ///Testuje stan obiektu
    bool czyMoznaZjechac() const;

    /**
    * \brief Ustawia nową wartość pola klasy
    * \param[in] _przeszkoda adres obiektu, który blokuje wierzchołek
    */
    void ustawStanZajety(void* _przeszkoda);

    /**
    * \brief Testuje stan obiektu
    * \param[in] _przeszkoda ustaw na nullptr, gdy nie chcesz sprawdzać, kto blokuje wierzchołek
    * \return "true", gdy wierzchołek jest zajęty i blokuje go ktoś inny niż "_przeszkoda"
    */
    bool czyStanZajety(void* _przeszkoda = nullptr) const;
private:
    Typ typ;
    Stan stan;
    void* przeszkoda;
    bool moznaZjechac;
};

#endif // WIERZCHOLEK_H
