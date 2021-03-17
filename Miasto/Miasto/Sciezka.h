#ifndef SCIEZKA_H
#define SCIEZKA_H

///Zawiera definicje ścieżek używanych w programie
class Sciezka {
public:
    ///Nie wolno tworzyć instancji tej klasy
    Sciezka() = delete;

    /**
    * \brief Zwraca ścieżkę do tekstury światła czerwonego
    * \return ścieżka do tekstury światła czerwonego
    */
    static char const* teksturaSwiatloCzerwone();

    /**
    * \brief Zwraca ścieżkę do tekstury światła zielonego
    * \return ścieżka do tekstury światła zielonego
    */
    static char const* teksturaSwiatloZielone();

    /**
    * \brief Zwraca ścieżkę do tekstury mapy
    * \return ścieżka do tekstury mapy
    */
    static char const* teksturaMapa();

    /**
    * \brief Zwraca ścieżkę do tekstury mgły
    * \return ścieżka do tekstury mgły
    */
    static char const* teksturaMgla();

    /**
    * \brief Zwraca ścieżkę do tekstury reprezentującej pojazd
    * \return ścieżka do tekstury reprezentującej pojazd
    */
    static char const* losujTeksturePojazdu();
};

#endif // SCIEZKA_H
