#ifndef STALA_H
#define STALA_H

///Zawiera definicje stałych używanych w programie
class Stala {
public:
    Stala() = delete;

    /**
    * \brief Zwraca rozmiar komórki w pikselach
    * \return rozmiar komórki w pikselach
    */
    static float rozmiarKafelka();

    /**
    * \brief Zwraca połowę rozmiaru komórki w pikselach
    * \return połowa rozmiaru komórki w pikselach
    */
    static float rozmiarPolowaKafelka();
};

#endif // STALA_H
