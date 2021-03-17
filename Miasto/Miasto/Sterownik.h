#ifndef STEROWNIK_H
#define STEROWNIK_H

///Interfejs dla obiektów, które sterują innymi obiektami
class Sterownik {
public:
    ///Ustawia wartości początkowe pól klasy
    Sterownik(bool _bezczynny);

    ///Ustawia nową wartość pola klasy
    void ustawBezczynny(bool wartosc);

    ///Testuje stan obiektu
    bool const& czyBezczynny() const;

    ///Testuje stan obiektu
    bool& czyBezczynny();

    /**
    * \brief Klasy pochodne muszą przygotować implementację funkcji,
    * która używa "czasSekundy" do wykonania kolejnego kroku symulacji
    * \param[in] czasSekundy czas, który upłynął od ostatniego wywołania funkcji
    */
    virtual void wykonajKrok(float czasSekundy) = 0;

    ///Standardowy destruktor
    virtual ~Sterownik() = default;
private:
    bool bezczynny;
};

#endif // STEROWNIK_H
