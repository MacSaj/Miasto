#ifndef SWIATLO_H
#define SWIATLO_H

#include"Grafika.h"

///Graficzna reprezentacja światła
class Swiatlo : public Grafika {
public:
    ///Aktualny stan światła
    enum class Stan {
        czerwony,
        zielony
    };

    ///Ustawia wartości początkowe pól klasy
    Swiatlo(Wektor2f _pozycja, float _katStapnie, Stan _stan = Stan::zielony);

    /**
    * \brief Generuje graficzną reprezentację światła w oknie
    * \param[in] painter obiekt, który generuje grafikę
    */
    void rysuj(QPainter& painter) override;

    ///Ustawia nową wartość pola klasy
    void ustawStanCzerwony();

    ///Ustawia nową wartość pola klasy
    void ustawStanZielony();

    ///Testuje stan obiektu
    bool czyStanCzerwony() const;

    ///Testuje stan obiektu
    bool czyStanZielony() const;
private:
    void ustawWygladZeStanu();

    Stan stan;
    QPixmap wygladCzerwony;
    QPixmap wygladZielony;
    QPixmap* wyglad;
};

#endif // SWIATLO_H
