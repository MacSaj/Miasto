#ifndef MGLA_H
#define MGLA_H

#include"Grafika.h"

///Graficzna reprezentacja mgły
class Mgla : public Grafika {
public:
    Mgla();

    /**
    * \brief Generuje graficzną reprezentację mgły w oknie
    * \param[in] painter obiekt, który generuje grafikę
    */
    void rysuj(QPainter& painter) override;
private:
    QPixmap wyglad;
};

#endif // MGLA_H
