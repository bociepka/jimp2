//
// Created by Bartek on 27.03.2018.
//

#ifndef JIMP_EXERCISES_FRIENDCLASS_H
#define JIMP_EXERCISES_FRIENDCLASS_H
#include <string>
using namespace std;

class Rodzic {
private:
    std::string imie;
    std::string nazwisko;
    int wiek;
    Dziecko * dziecko;
public:
    Rodzic(string imie, string nazwisko, int wiek, Dziecko * dziecko);
    ~Rodzic();
    void przepiszDoInnejSzkoly (std::string nazwa);
};

class Dziecko {
private:
    std::string imie;
    std::string nazwisko;
    int wiek;
    std::string szkola;
    friend class Rodzic;
public:
    Dziecko (string imie, string nazwisko, int wiek, string szkola);
    ~Dziecko();
};


#endif //JIMP_EXERCISES_FRIENDCLASS_H
