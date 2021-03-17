#include"Graf.h"
#include<queue>
#include<unordered_map>
#include"Stala.h"

std::vector<Wierzcholek> Graf::wierzcholki {
    Wierzcholek{wierszKolumnaNaPozycje(6, 0), Wierzcholek::Typ::poczatekTrasy},   //0
    Wierzcholek{wierszKolumnaNaPozycje(6, 1)},                                    //1
    Wierzcholek{wierszKolumnaNaPozycje(6, 2)},                                    //2
    Wierzcholek{wierszKolumnaNaPozycje(6, 3)},                                    //3
    Wierzcholek{wierszKolumnaNaPozycje(6, 4)},                                    //4
    Wierzcholek{wierszKolumnaNaPozycje(6, 5)},                                    //5
    Wierzcholek{wierszKolumnaNaPozycje(7, 5)},                                    //6
    Wierzcholek{wierszKolumnaNaPozycje(8, 5)},                                    //7
    Wierzcholek{wierszKolumnaNaPozycje(9, 5), Wierzcholek::Typ::skrzyzowanie},    //8
    Wierzcholek{wierszKolumnaNaPozycje(10, 5), Wierzcholek::Typ::skrzyzowanie},   //9
    Wierzcholek{wierszKolumnaNaPozycje(11, 5)},                                   //10
    Wierzcholek{wierszKolumnaNaPozycje(12, 5)},                                   //11
    Wierzcholek{wierszKolumnaNaPozycje(13, 5), Wierzcholek::Typ::skrzyzowanie},   //12
    Wierzcholek{wierszKolumnaNaPozycje(13, 4)},                                   //13
    Wierzcholek{wierszKolumnaNaPozycje(13, 3)},                                   //14
    Wierzcholek{wierszKolumnaNaPozycje(13, 2)},                                   //15
    Wierzcholek{wierszKolumnaNaPozycje(13, 1)},                                   //16
    Wierzcholek{wierszKolumnaNaPozycje(13, 0), Wierzcholek::Typ::koniecTrasy},    //17
    Wierzcholek{wierszKolumnaNaPozycje(10, 6), Wierzcholek::Typ::skrzyzowanie},   //18
    Wierzcholek{wierszKolumnaNaPozycje(9, 6), Wierzcholek::Typ::skrzyzowanie},    //19
    Wierzcholek{wierszKolumnaNaPozycje(8, 6)},                                    //20
    Wierzcholek{wierszKolumnaNaPozycje(10, 7)},                                   //21
    Wierzcholek{wierszKolumnaNaPozycje(14, 5), Wierzcholek::Typ::skrzyzowanie},   //22
    Wierzcholek{wierszKolumnaNaPozycje(14, 6), Wierzcholek::Typ::skrzyzowanie},   //23
    Wierzcholek{wierszKolumnaNaPozycje(13, 6), Wierzcholek::Typ::skrzyzowanie},   //24
    Wierzcholek{wierszKolumnaNaPozycje(14, 7)},                                   //25
    Wierzcholek{wierszKolumnaNaPozycje(12, 6)},                                   //26
    Wierzcholek{wierszKolumnaNaPozycje(11, 6)},                                   //27
    Wierzcholek{wierszKolumnaNaPozycje(7, 6)},                                    //28
    Wierzcholek{wierszKolumnaNaPozycje(6, 6)},                                    //29
    Wierzcholek{wierszKolumnaNaPozycje(5, 6)},                                    //30
    Wierzcholek{wierszKolumnaNaPozycje(5, 5)},                                    //31
    Wierzcholek{wierszKolumnaNaPozycje(5, 4)},                                    //32
    Wierzcholek{wierszKolumnaNaPozycje(5, 3)},                                    //33
    Wierzcholek{wierszKolumnaNaPozycje(5, 2)},                                    //34
    Wierzcholek{wierszKolumnaNaPozycje(5, 1)},                                    //35
    Wierzcholek{wierszKolumnaNaPozycje(5, 0), Wierzcholek::Typ::koniecTrasy},     //36
    Wierzcholek{wierszKolumnaNaPozycje(10, 8)},                                   //37
    Wierzcholek{wierszKolumnaNaPozycje(10, 9)},                                   //38
    Wierzcholek{wierszKolumnaNaPozycje(10, 10)},                                  //39
    Wierzcholek{wierszKolumnaNaPozycje(9, 10)},                                   //40
    Wierzcholek{wierszKolumnaNaPozycje(8, 10)},                                   //41
    Wierzcholek{wierszKolumnaNaPozycje(7, 10)},                                   //42
    Wierzcholek{wierszKolumnaNaPozycje(6, 10), Wierzcholek::Typ::skrzyzowanie},   //43
    Wierzcholek{wierszKolumnaNaPozycje(5, 10), Wierzcholek::Typ::skrzyzowanie},   //44
    Wierzcholek{wierszKolumnaNaPozycje(5, 9), Wierzcholek::Typ::skrzyzowanie},    //45
    Wierzcholek{wierszKolumnaNaPozycje(6, 9), Wierzcholek::Typ::skrzyzowanie},    //46
    Wierzcholek{wierszKolumnaNaPozycje(7, 9)},                                    //47
    Wierzcholek{wierszKolumnaNaPozycje(4, 10)},                                   //48
    Wierzcholek{wierszKolumnaNaPozycje(6, 11)},                                   //49
    Wierzcholek{wierszKolumnaNaPozycje(3, 10)},                                   //50
    Wierzcholek{wierszKolumnaNaPozycje(2, 10)},                                   //51
    Wierzcholek{wierszKolumnaNaPozycje(1, 10)},                                   //52
    Wierzcholek{wierszKolumnaNaPozycje(0, 10), Wierzcholek::Typ::koniecTrasy},    //53
    Wierzcholek{wierszKolumnaNaPozycje(8, 9)},                                    //54
    Wierzcholek{wierszKolumnaNaPozycje(9, 9)},                                    //55
    Wierzcholek{wierszKolumnaNaPozycje(9, 8)},                                    //56
    Wierzcholek{wierszKolumnaNaPozycje(9, 7)},                                    //57
    Wierzcholek{wierszKolumnaNaPozycje(14, 8)},                                   //58
    Wierzcholek{wierszKolumnaNaPozycje(14, 9)},                                   //59
    Wierzcholek{wierszKolumnaNaPozycje(14, 10)},                                  //60
    Wierzcholek{wierszKolumnaNaPozycje(14, 11)},                                  //61
    Wierzcholek{wierszKolumnaNaPozycje(14, 12)},                                  //62
    Wierzcholek{wierszKolumnaNaPozycje(14, 13), Wierzcholek::Typ::skrzyzowanie},  //63
    Wierzcholek{wierszKolumnaNaPozycje(14, 14), Wierzcholek::Typ::skrzyzowanie},  //64
    Wierzcholek{wierszKolumnaNaPozycje(13, 14), Wierzcholek::Typ::skrzyzowanie},  //65
    Wierzcholek{wierszKolumnaNaPozycje(13, 13), Wierzcholek::Typ::skrzyzowanie},  //66
    Wierzcholek{wierszKolumnaNaPozycje(12, 14)},                                  //67
    Wierzcholek{wierszKolumnaNaPozycje(13, 12)},                                  //68
    Wierzcholek{wierszKolumnaNaPozycje(15, 13)},                                  //69
    Wierzcholek{wierszKolumnaNaPozycje(16, 13), Wierzcholek::Typ::koniecTrasy},   //70
    Wierzcholek{wierszKolumnaNaPozycje(13, 11)},                                  //71
    Wierzcholek{wierszKolumnaNaPozycje(13, 10)},                                  //72
    Wierzcholek{wierszKolumnaNaPozycje(13, 9)},                                   //73
    Wierzcholek{wierszKolumnaNaPozycje(13, 8)},                                   //74
    Wierzcholek{wierszKolumnaNaPozycje(13, 7)},                                   //75
    Wierzcholek{wierszKolumnaNaPozycje(11, 14)},                                  //76
    Wierzcholek{wierszKolumnaNaPozycje(10, 14)},                                  //77
    Wierzcholek{wierszKolumnaNaPozycje(9, 14)},                                   //78
    Wierzcholek{wierszKolumnaNaPozycje(8, 14)},                                   //79
    Wierzcholek{wierszKolumnaNaPozycje(7, 14)},                                   //80
    Wierzcholek{wierszKolumnaNaPozycje(6, 14)},                                   //81
    Wierzcholek{wierszKolumnaNaPozycje(5, 14)},                                   //82
    Wierzcholek{wierszKolumnaNaPozycje(5, 13)},                                   //83
    Wierzcholek{wierszKolumnaNaPozycje(5, 12)},                                   //84
    Wierzcholek{wierszKolumnaNaPozycje(5, 11)},                                   //85
    Wierzcholek{wierszKolumnaNaPozycje(6, 12)},                                   //86
    Wierzcholek{wierszKolumnaNaPozycje(6, 13)},                                   //87
    Wierzcholek{wierszKolumnaNaPozycje(7, 13)},                                   //88
    Wierzcholek{wierszKolumnaNaPozycje(8, 13)},                                   //89
    Wierzcholek{wierszKolumnaNaPozycje(9, 13)},                                   //90
    Wierzcholek{wierszKolumnaNaPozycje(10, 13)},                                  //91
    Wierzcholek{wierszKolumnaNaPozycje(11, 13)},                                  //92
    Wierzcholek{wierszKolumnaNaPozycje(12, 13)},                                  //93
    Wierzcholek{wierszKolumnaNaPozycje(16, 14), Wierzcholek::Typ::poczatekTrasy}, //94
    Wierzcholek{wierszKolumnaNaPozycje(15, 14)},                                  //95
    Wierzcholek{wierszKolumnaNaPozycje(14, 0), Wierzcholek::Typ::poczatekTrasy},  //96
    Wierzcholek{wierszKolumnaNaPozycje(14, 1)},                                   //97
    Wierzcholek{wierszKolumnaNaPozycje(14, 2)},                                   //98
    Wierzcholek{wierszKolumnaNaPozycje(14, 3)},                                   //99
    Wierzcholek{wierszKolumnaNaPozycje(14, 4)},                                   //100
    Wierzcholek{wierszKolumnaNaPozycje(0, 9), Wierzcholek::Typ::poczatekTrasy},   //101
    Wierzcholek{wierszKolumnaNaPozycje(1, 9)},                                    //102
    Wierzcholek{wierszKolumnaNaPozycje(2, 9)},                                    //103
    Wierzcholek{wierszKolumnaNaPozycje(3, 9)},                                    //104
    Wierzcholek{wierszKolumnaNaPozycje(4, 9)},                                    //105
};
//pamiejtaj aby sprawdzic wierzchołki
std::vector<std::vector<int>> Graf::krawedzie{
    {1},        //0
    {2},        //1
    {3},        //2
    {4},        //3
    {5},        //4
    {6},        //5
    {7},        //6
    {8},        //7
    {9},        //8
    {10, 18},   //9
    {11},       //10
    {12},       //11
    {13, 22},   //12
    {14},       //13
    {15},       //14
    {16},       //15
    {17},       //16
    {},         //17
    {19, 21},   //18
    {8, 20},    //19
    {28},       //20
    {37},       //21
    {23},       //22
    {24, 25},   //23
    {12, 26},   //24
    {58},       //25
    {27},       //26
    {18},       //27
    {29},       //28
    {30},       //29
    {31},       //30
    {32},       //31
    {33},       //32
    {34},       //33
    {35},       //34
    {36},       //35
    {},         //36
    {38},       //37
    {39},       //38
    {40},       //39
    {41},       //40
    {42},       //41
    {43},       //42
    {44, 49},   //43
    {45, 48},   //44
    {46},       //45
    {47, 43},   //46
    {54},       //47
    {50},       //48
    {86},       //49
    {51},       //50
    {52},       //51
    {53},       //52
    {},         //53
    {55},       //54
    {56},       //55
    {57},       //56
    {19},       //57
    {59},       //58
    {60},       //59
    {61},       //60
    {62},       //61
    {63},       //62
    {64, 69},   //63
    {65},       //64
    {66, 67},   //65
    {63, 68},   //66
    {76},       //67
    {71},       //68
    {70},       //69
    {},         //70
    {72},       //71
    {73},       //72
    {74},       //73
    {75},       //74
    {24},       //75
    {77},       //76
    {78},       //77
    {79},       //78
    {80},       //79
    {81},       //80
    {82},       //81
    {83},       //82
    {84},       //83
    {85},       //84
    {44},       //85
    {87},       //86
    {88},       //87
    {89},       //88
    {90},       //89
    {91},       //90
    {92},       //91
    {93},       //92
    {66},       //93
    {95},       //94
    {64},       //95
    {97},       //96
    {98},       //97
    {99},       //98
    {100},      //99
    {22},       //100
    {102},      //101
    {103},      //102
    {104},      //103
    {105},      //104
    {45},       //105
};

int Graf::utworzKlucz(int wiersz, int kolumna) {
    return wiersz * 100 + kolumna;
}

int Graf::liczbaWierzcholkow() {
    return wierzcholki.size();
}

int Graf::losujPoczatekTrasy() {
    static std::vector<int> const indeks{0, 94, 96, 101};
    return indeks[qrand() % indeks.size()];
}

int Graf::losujKoniecTrasy() {
    static std::vector<int> const indeks{17, 36, 53, 70};
    return indeks[qrand() % indeks.size()];
}

Wektor2f Graf::wierszKolumnaNaPozycje(int wiersz, int kolumna) {
    return Wektor2f{kolumna * Stala::rozmiarKafelka(), wiersz * Stala::rozmiarKafelka()};
}

Wierzcholek* Graf::wierszKolumnaNaWierzcholek(int wiersz, int kolumna) {
    return &wierzcholki[wierszKolumnaNaIndeks(wiersz, kolumna)];
}

Wierzcholek* Graf::indeksNaWierzcholek(int indeksWierzcholka) {
    return &wierzcholki[indeksWierzcholka];
}

int Graf::wierszKolumnaNaIndeks(int wiersz, int kolumna) {
    static std::unordered_map<int, int> const indeks{
        {utworzKlucz(6, 0), 0},
        {utworzKlucz(6, 1), 1},
        {utworzKlucz(6, 2), 2},
        {utworzKlucz(6, 3), 3},
        {utworzKlucz(6, 4), 4},
        {utworzKlucz(6, 5), 5},
        {utworzKlucz(7, 5), 6},
        {utworzKlucz(8, 5), 7},
        {utworzKlucz(9, 5), 8},
        {utworzKlucz(10, 5), 9},
        {utworzKlucz(11, 5), 10},
        {utworzKlucz(12, 5), 11},
        {utworzKlucz(13, 5), 12},
        {utworzKlucz(13, 4), 13},
        {utworzKlucz(13, 3), 14},
        {utworzKlucz(13, 2), 15},
        {utworzKlucz(13, 1), 16},
        {utworzKlucz(13, 0), 17},
        {utworzKlucz(10, 6), 18},
        {utworzKlucz(9, 6), 19},
        {utworzKlucz(8, 6), 20},
        {utworzKlucz(10, 7), 21},
        {utworzKlucz(14, 5), 22},
        {utworzKlucz(14, 6), 23},
        {utworzKlucz(13, 6), 24},
        {utworzKlucz(14, 7), 25},
        {utworzKlucz(12, 6), 26},
        {utworzKlucz(11, 6), 27},
        {utworzKlucz(7, 6), 28},
        {utworzKlucz(6, 6), 29},
        {utworzKlucz(5, 6), 30},
        {utworzKlucz(5, 5), 31},
        {utworzKlucz(5, 4), 32},
        {utworzKlucz(5, 3), 33},
        {utworzKlucz(5, 2), 34},
        {utworzKlucz(5, 1), 35},
        {utworzKlucz(5, 0), 36},
        {utworzKlucz(10, 8), 37},
        {utworzKlucz(10, 9), 38},
        {utworzKlucz(10, 10), 39},
        {utworzKlucz(9, 10), 40},
        {utworzKlucz(8, 10), 41},
        {utworzKlucz(7, 10), 42},
        {utworzKlucz(6, 10), 43},
        {utworzKlucz(5, 10), 44},
        {utworzKlucz(5, 9), 45},
        {utworzKlucz(6, 9), 46},
        {utworzKlucz(7, 9), 47},
        {utworzKlucz(4, 10), 48},
        {utworzKlucz(6, 11), 49},
        {utworzKlucz(3, 10), 50},
        {utworzKlucz(2, 10), 51},
        {utworzKlucz(1, 10), 52},
        {utworzKlucz(0, 10), 53},
        {utworzKlucz(8, 9), 54},
        {utworzKlucz(9, 9), 55},
        {utworzKlucz(9, 8), 56},
        {utworzKlucz(9, 7), 57},
        {utworzKlucz(14, 8), 58},
        {utworzKlucz(14, 9), 59},
        {utworzKlucz(14, 10), 60},
        {utworzKlucz(14, 11), 61},
        {utworzKlucz(14, 12), 62},
        {utworzKlucz(14, 13), 63},
        {utworzKlucz(14, 14), 64},
        {utworzKlucz(13, 14), 65},
        {utworzKlucz(13, 13), 66},
        {utworzKlucz(12, 14), 67},
        {utworzKlucz(13, 12), 68},
        {utworzKlucz(15, 13), 69},
        {utworzKlucz(16, 13), 70},
        {utworzKlucz(13, 11), 71},
        {utworzKlucz(13, 10), 72},
        {utworzKlucz(13, 9), 73},
        {utworzKlucz(13, 8), 74},
        {utworzKlucz(13, 7), 75},
        {utworzKlucz(11, 14), 76},
        {utworzKlucz(10, 14), 77},
        {utworzKlucz(9, 14), 78},
        {utworzKlucz(8, 14), 79},
        {utworzKlucz(7, 14), 80},
        {utworzKlucz(6, 14), 81},
        {utworzKlucz(5, 14), 82},
        {utworzKlucz(5, 13), 83},
        {utworzKlucz(5, 12), 84},
        {utworzKlucz(5, 11), 85},
        {utworzKlucz(6, 12), 86},
        {utworzKlucz(6, 13), 87},
        {utworzKlucz(7, 13), 88},
        {utworzKlucz(8, 13), 89},
        {utworzKlucz(9, 13), 90},
        {utworzKlucz(10, 13), 91},
        {utworzKlucz(11, 13), 92},
        {utworzKlucz(12, 13), 93},
        {utworzKlucz(16, 14), 94},
        {utworzKlucz(15, 14), 95},
        {utworzKlucz(14, 0), 96},
        {utworzKlucz(14, 1), 97},
        {utworzKlucz(14, 2), 98},
        {utworzKlucz(14, 3), 99},
        {utworzKlucz(14, 4), 100},
        {utworzKlucz(0, 9), 101},
        {utworzKlucz(1, 9), 102},
        {utworzKlucz(2, 9), 103},
        {utworzKlucz(3, 9), 104},
        {utworzKlucz(4, 9), 105}
    };

    return indeks.at(utworzKlucz(wiersz, kolumna));
}

std::vector<Wierzcholek*> Graf::wyznaczTrase(int indeksWierzcholekStart, int indeksWierzcholekKoniec) {
    //wagi wszystkich krawędzi są takie same, więc najkrótszą drogę znajdujemy przeszukując graf wszerz

    std::vector<int> rodzic(wierzcholki.size(), -1);

    std::queue<int> kolejka;
    kolejka.push(indeksWierzcholekStart);

    while (!kolejka.empty()) {
        int wierzcholek = kolejka.front();
        kolejka.pop();

        if (wierzcholek == indeksWierzcholekKoniec) {
            break;
        }

        for (int sasiad : krawedzie[wierzcholek]) {
            if (rodzic[sasiad] == -1) {
                rodzic[sasiad] = wierzcholek;
                kolejka.push(sasiad);
            }
        }
    }

    //wierzchołki trasy są w odwróconej kolejności (wierzchołek początkowy jest na końcu)
    std::vector<Wierzcholek*> trasa{&wierzcholki[indeksWierzcholekKoniec]};

    for (int w = indeksWierzcholekKoniec; w != indeksWierzcholekStart; ) {
        w = rodzic[w];
        trasa.push_back(&wierzcholki[w]);
    }

    return trasa;
}

void Graf::rysuj(QPainter& painter) {
    for (Wierzcholek& w : wierzcholki) {
        w.rysuj(painter);
    }

    for (int i = 0; i < liczbaWierzcholkow(); ++i) {
        Wierzcholek* wierzcholek = indeksNaWierzcholek(i);

        Wektor2f pozycja = wierzcholek->zwrocPozycja();
        pozycja.x += Stala::rozmiarPolowaKafelka();
        pozycja.y += Stala::rozmiarPolowaKafelka();

        for (int sasiadIndeks : krawedzie[i]) {
            Wierzcholek* sasiad = indeksNaWierzcholek(sasiadIndeks);

            Wektor2f pozycjaSasiad = sasiad->zwrocPozycja();
            pozycjaSasiad.x += Stala::rozmiarPolowaKafelka();
            pozycjaSasiad.y += Stala::rozmiarPolowaKafelka();

            Grafika::rysujStrzalke(pozycja, pozycjaSasiad, painter);
        }
    }
}
