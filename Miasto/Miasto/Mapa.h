#ifndef MAPA_H
#define MAPA_H

#include"Grafika.h"

///Graficzna reprezentacja mapy
class Mapa : public Grafika {
public:
    ///Ustawia wartości początkowe pól klasy
    Mapa();

    /**
    * \brief Generuje graficzną reprezentację mapy w oknie
    * \param[in] painter obiekt, który generuje grafikę
    */
    void rysuj(QPainter& painter) override;
private:
    QPixmap tlo;
};

#endif // MAPA_H
