#ifndef GRAFIKA_H
#define GRAFIKA_H

#include<QPainter>
#include"Wektor2.h"

///Interfejs dla obiektów, które można narysować w oknie
class Grafika {
public:
    /**
    * \brief Używam "painter" do narysowania strzałki, która wskazuje od "poczatek" do "koniec"
    * \param[in] poczatek początek strzałki
    * \param[in] koniec koniec strzałki
    * \param[in] painter obiekt, który generuje strzałkę
    */
    static void rysujStrzalke(Wektor2f const& poczatek, Wektor2f const& koniec, QPainter& painter);

    /**
    * \brief Ustawia wartości początkowe pól klasy
    * \param[in] _pozycja miejsce grafiki w oknie
    * \param[in] _katStopnie kąt obrotu grafiki (dodatni kąt oznacza obrót zgodny z ruchem wskazówek zegara)
    */
    explicit Grafika(Wektor2f const& _pozycja, float _katStopnie);

    /**
    * \brief Ustawia nową wartość pola klasy
    * \param[in] _pozycja miejsce grafiki w oknie
    */
    void ustawPozycja(Wektor2f const& _pozycja);

    /**
    * \brief Zwraca wartość pola klasy
    * \return miejsce grafiki w oknie
    */
    Wektor2f const& zwrocPozycja() const;

    /**
    * \brief Zwraca wartość pola klasy
    * \return miejsce grafiki w oknie
    */
    Wektor2f& zwrocPozycja();

    /**
    * \brief Ustawia nową wartość pola klasy
    * \param[in] _katStopnie kąt obrotu grafiki (dodatni kąt oznacza obrót zgodny z ruchem wskazówek zegara)
    */
    void ustawKatStopnie(float _katStopnie);

    /**
    * \brief Zwraca wartość pola klasy
    * \return kąt obrotu grafiki (dodatni kąt oznacza obrót zgodny z ruchem wskazówek zegara)
    */
    float const& zwrocKatStopnie() const;

    /**
    * \brief Zwraca wartość pola klasy
    * \return kąt obrotu grafiki (dodatni kąt oznacza obrót zgodny z ruchem wskazówek zegara)
    */
    float& zwrocKatStopnie();

    /**
    * \brief Klasy pochodne muszą przygotować implementację funkcji, która używa "painter" do narysowania obiektu
    * \param[in] painter obiekt, który generuje grafikę
    */
    virtual void rysuj(QPainter& painter) = 0;

    virtual ~Grafika() = default;
protected:
    ///miejsce grafiki w oknie
    Wektor2f pozycja;

    ///kąt obrotu grafiki
    float katStopnie;
};

#endif // GRAFIKA_H
