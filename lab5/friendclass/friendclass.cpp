//
// Created by Bartek on 27.03.2018.
//

#include "friendclass.h"

Rodzic::Rodzic(string name,string surname,int age,Dziecko * child){
    imie = name;
    nazwisko = surname;
    wiek = age;
    &dziecko = child;
}

Rodzic::~Rodzic(){};

Dziecko::Dziecko (string name, string surname, int age, string school){
    imie = name;
    nazwisko = surname;
    wiek = age;
    szkola = school;
}

Dziecko::~Dziecko(){};

void Rodzic::przepiszDoInnejSzkoly (std::string nazwa){
    dziecko->szkola = nazwa;
}