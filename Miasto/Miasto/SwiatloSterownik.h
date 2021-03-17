#ifndef SWIATLOSTEROWNIK_H
#define SWIATLOSTEROWNIK_H

#include"Sterownik.h"
#include"Swiatlo.h"
#include"Wierzcholek.h"

///Obiekty tej klasy sterują światłami
class SwiatloSterownik : public Sterownik {
public:
    /**
    * \brief Ustawia wartości początkowe pól klasy
    * \param[in] _swiatlo obiekt będzie sterował tym światłem
    * \param[in] _wierzcholek może być zablokowany przez światło
    */
    SwiatloSterownik(Swiatlo* _swiatlo, Wierzcholek* _wierzcholek);

    /**
    * \brief Wykonuje kolejny krok symulacji
    * \param[in] czasSekundy czas, który upłynął od ostatniego wywołania funkcji
    */
    void wykonajKrok(float czasSekundy) override;
private:
    Swiatlo* swiatlo;
    Wierzcholek* wierzcholek;
    float czas;
};

#endif // SWIATLOSTEROWNIK_H
