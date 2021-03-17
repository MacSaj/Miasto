#ifndef GRAF_H
#define GRAF_H

#include<QPainter>
#include<vector>
#include"Wierzcholek.h"
#include"Wektor2.h"

///Przykładowy zestaw danych opisujący graf i jego krawędzie. Udostępnia metody przetwarzające graf
class Graf {
private:
    static int utworzKlucz(int wiersz, int kolumna);
public:
    static std::vector<Wierzcholek> wierzcholki;

    static std::vector<std::vector<int>> krawedzie;

    Graf() = delete;

    /**
    * \brief Zwraca liczbę wierzchołków w grafie
    * \return liczba wierzchołków w grafie
    */
    static int liczbaWierzcholkow();

    /**
    * \brief Zwraca indeks wierzchołka początkowego trasy
    * \return indeks wierzchołka początkowego trasy
    */
    static int losujPoczatekTrasy();

    /**
    * \brief Zwraca indeks wierzchołka końcowego trasy
    * \return indeks wierzchołka końcowego trasy
    */
    static int losujKoniecTrasy();

    /**
    * \brief Wyznacza trasę z "indeksWierzcholekStart" do "indeksWierzcholekKoniec".
    * Trasa między wierzchołkami musi istnieć. Metoda zakłada, że oba indeksy są poprawne.
    * \param[in] indeksWierzcholekStart wierzchołek początkowy trasy
    * \param[in] indeksWierzcholekKoniec wierzchołek końcowy trasy
    * \return wierzchołki trasy w odwróconej kolejności (wierzchołek początkowy jest na końcu)
    */
    static std::vector<Wierzcholek*> wyznaczTrase(int indeksWierzcholekStart, int indeksWierzcholekKoniec);

    /**
    * \brief Zwraca pozycję komórki
    * \return pozycja komórki
    */
    static Wektor2f wierszKolumnaNaPozycje(int wiersz, int kolumna);

    /**
    * \brief Zwraca wierzchołek przypisany do komórki. Metoda zakłada, że współrzędne są poprawne
    * \return wierzchołek przypisany do komórki
    */
    static Wierzcholek* wierszKolumnaNaWierzcholek(int wiersz, int kolumna);

    /**
    * \brief Zwraca wierzchołek przypisany do indeksu. Metoda zakłada, że indeks jest poprawny
    * \return wierzchołek przypisany do indeksu
    */
    static Wierzcholek* indeksNaWierzcholek(int indeksWierzcholka);

    /**
    * \brief Zamienia komórkę na indeks. Metoda zakłada, że współrzędne są poprawne
    * \return indeks komórki
    */
    static int wierszKolumnaNaIndeks(int wiersz, int kolumna);

    /**
    * \brief Generuje graficzną reprezentację grafu w oknie
    * \param[in] painter obiekt, który generuje grafikę
    */
    static void rysuj(QPainter& painter);
};

#endif // GRAF_H
