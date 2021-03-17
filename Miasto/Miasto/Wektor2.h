/**
* \file
* \brief Zawiera deklaracje i definicje szablonu używanego w obliczeniach
*/

#ifndef WEKTOR2_H
#define WEKTOR2_H

#include<cmath>

///Szablon, z którego kompilator generuje klasę używaną do obliczeń
template<typename T>
struct Wektor2 {
    ///komponent "X" wektora
    T x;

    ///komponent "Y" wektora
    T y;

    ///Nie ustawia wartości komponentów
    Wektor2() = default;

    ///Ustawia wartości komponentów
    Wektor2(T const& _x, T const& _y)
    : x{_x}, y{_y}
    {}

    ///Dodaje do tego wektora "inny"
    Wektor2& operator+=(Wektor2 const& inny) {
        x += inny.x;
        y += inny.y;
        return *this;
    }

    ///Odejmuje od tego wektora "inny"
    Wektor2& operator-=(Wektor2 const& inny) {
        x -= inny.x;
        y -= inny.y;
        return *this;
    }

    ///Skaluje ten wektor
    Wektor2& operator*=(T const& skalar) {
        x *= skalar;
        y *= skalar;
        return *this;
    }

    /**
    * \brief Skaluje ten wektor
    * \param[in] skalar nie może być równy 0
    * \return ten wektor po skalowaniu
    */
    Wektor2& operator/=(T const& skalar) {
        x /= skalar;
        y /= skalar;
        return *this;
    }

    /**
    * \brief Tworzy nowy wektor o przeciwnym zwrocie
    * \return nowy wektor o przeciwnym zwrocie
    */
    Wektor2 operator-() const {
        return Wektor2{-x, -y};
    }

    /**
    * \brief Oblicza iloczyn skalarny dwóch wektorów
    * \return iloczyn skalarny dwóch wektorów
    */
    T iloczynSkalarny(Wektor2<T> const& inny) {
        return x * inny.x + y * inny.y;
    }
};

/**
* \brief Dodaje dwa wektory
* \return suma dwóch wektorów
*/
template<typename T>
Wektor2<T> operator+(Wektor2<T> const& a, Wektor2<T> const& b) {
    Wektor2<T> wynik{a};
    return wynik += b;
}

/**
* \brief Odejmuje dwa wektory
* \return różnica dwóch wektorów
*/
template<typename T>
Wektor2<T> operator-(Wektor2<T> const& a, Wektor2<T> const& b) {
    Wektor2<T> wynik{a};
    return wynik -= b;
}

/**
* \brief Mnoży wektor przez skalar
* \return przeskalowany wektor
*/
template<typename T>
Wektor2<T> operator*(T const& skalar, Wektor2<T> const& b) {
    Wektor2<T> wynik{b};
    return wynik *= skalar;
}

/**
* \brief Mnoży wektor przez skalar
* \return przeskalowany wektor
*/
template<typename T>
Wektor2<T> operator*(Wektor2<T> const& a, T const& skalar) {
    return skalar * a;
}

/**
* \brief Dzieli wektor przez skalar
* \return przeskalowany wektor
*/
template<typename T>
Wektor2<T> operator/(Wektor2<T> const& a, T const& skalar) {
    Wektor2<T> wynik{a};
    return wynik /= skalar;
}

///Wektor używany w programie przy ustalaniu położenia
using Wektor2f = Wektor2<float>;

/**
* \brief Zwraca długość wektora
* \return długość wektora
*/
inline float dlugosc(Wektor2f const& a) {
    return sqrtf(a.x * a.x + a.y * a.y);
}

/**
* \brief Zwraca odległość między punktami "a" i "b"
* \return odległość między punktami
*/
inline float odleglosc(Wektor2f const& a, Wektor2f const& b) {
    return dlugosc(b - a);
}

/**
* \brief Zwraca wektor jednostkowy
* \param[in] a długość musi być różna od 0
* \return wektor jednostkowy
*/
inline Wektor2f normalizuj(Wektor2f const& a) {
    float dl = dlugosc(a);
    Wektor2f wynik{a};
    return wynik / dl;
}

#endif // WEKTOR2_H
