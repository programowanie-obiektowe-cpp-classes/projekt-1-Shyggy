#include <iostream>
#include <string>
#include<cstdlib>
#include<ctime>
#include<RandomNameGenerator.hpp>
#include<RandomWydzialGenerator.hpp>
#include<GetRandomValues.h>
#include<Pracownicy.h>
#include<Firma.h>
#include<Kredyt.h>
#include<OperatorFunctions.h>

double Pracownik::Wynagrodzenie_ = 0.0;
const int Inzynier::CI_ = 35;
const int Magazynier::CMag_ = 100;
const int Marketer::CMkt_ = 130;
const int Robotnik::CRob_ = 110;
int main()
{
    Firma f;
    Kredyt k(&f);
    start(&f);
    std::string komenda;
    while (true)
    {
        std::cout << "\033[31mPodaj komende:\033[0m" << std::endl;
        std::cin >> komenda;
        if (komenda == "lp")
        {
            f.identyfikacja();
        }
        if (komenda == "zinz")
        {
            f.rekrutacja("zinz");
        }
        if (komenda == "zmag")
        {
            f.rekrutacja("zmag");
        }
        if (komenda == "zmkt")
        {
            f.rekrutacja("zmkt");
        }
        if (komenda == "zrob")
        {
            f.rekrutacja("zrob");
        }
        if (komenda == "kred")
        {
            kred(&k);
        }
        if (komenda == "gp")
        {
            f.printprzychod();
        }
        if (komenda == "kt")
        {
            kt(&k, &f);
        }
        if (komenda == "end")
        {
            break;
        }
        if (f.WynikFirmy_ >= Cel)
        {
            std::cout << "Gratulacje! Twoja firma osiagnela wynik " << Cel << " Wygrales gre!" << std::endl;
            break;
        }
        if (f.PosiadaneAktywa_ < 0.0)
        {
            std::cout << "Niestety twoja firma zbankrutowala :c. Przegrales" << std::endl;
            break;
        }
    }

    return 0;
}
