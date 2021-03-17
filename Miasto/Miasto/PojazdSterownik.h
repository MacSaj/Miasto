#ifndef POJAZDSTEROWNIK_H
#define POJAZDSTEROWNIK_H

#include<vector>

#include"Sterownik.h"
#include"Pojazd.h"
#include"Wierzcholek.h"

///Obiekty tej klasy sterują pojazdami
class PojazdSterownik : public Sterownik {
public:
    /**
    * \brief Ustawia wartości początkowe pól klasy
    * \param[in] _pojazd obiekt będzie sterował tym pojazdem
    * \param[in] _trasa nie może być pusta, pojazd będzie poruszał się wzdłuż tej trasy
    */
    PojazdSterownik(Pojazd* _pojazd, std::vector<Wierzcholek*> const& _trasa);

    /**
    * \brief Wykonuje kolejny krok symulacji
    * \param[in] czasSekundy czas, który upłynął od ostatniego wywołania funkcji
    */
    void wykonajKrok(float czasSekundy) override;
private:
    enum class Stan {
        ustawPunktDocelowy,
        ustawKierunekJazdy,
        zmienPolozenie,
        koniecTrasy
    };

    Pojazd* pojazd;
    std::vector<Wierzcholek*> trasa;
    Stan stan;
};

#endif // POJAZDSTEROWNIK_H
