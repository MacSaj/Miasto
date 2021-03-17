#ifndef POJAZD_H
#define POJAZD_H

#include"Grafika.h"

///Graficzna reprezentacja pojazdu
class Pojazd : public Grafika {
public:
    ///Ustawia wartości początkowe pól klasy
    Pojazd(char const* sciezkaTeksturyPojazdu, Wektor2f _pozycja, float _katStapnie);

    /**
    * \brief Generuje graficzną reprezentację pojazdu w oknie
    * \param[in] painter obiekt, który generuje grafikę
    */
    void rysuj(QPainter& painter) override;
private:
    QPixmap wyglad;
};

#endif // POJAZD_H
