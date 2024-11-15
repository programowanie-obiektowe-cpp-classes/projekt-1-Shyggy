#pragma once
const double Cel = 1000000.0;

void start(Firma* firma_)
{

    firma_->PosiadaneAktywa_ = 100000;
    firma_->WynikFirmy_ = firma_->PosiadaneAktywa_;
    std::cout << "Witaj w Grze Ekonomicznej. Twoim celem jest poprowadzenie firmy w takim kierunku aby osiagnela ona wynik: " << Cel << ". " << "Jednoczesnie nie doprowadzajac jej do bakrutctwa." << std::endl;
    std::cout << "W tym celu bedziesz musial uzyskiwac zyski poprzez zatrudnianie pracownikow i branie kredytow." << std::endl;
    std::cout << "Pracownicy ktorych mozesz zatrudnic to :" << std::endl << "Inzynierzy - zwiekszajacy cene produktu," << std::endl << "Magazynierzy - zwiekszajacy pojemnosc magazynu" << std::endl << "Marketerzy - zwiekszajacy popyt na produkt" << std::endl << "Robotnicy - zwiekszajacy ilosc wyprodukowanych produktow" << std::endl;
    std::cout << "W tym celu korzystac bedziesz mogl z nastepujacych akcji:" << std::endl << "lp - wylistuj pracownikow oraz ich atrybuty" << std::endl << "zinz - zatrudnij inzyniera" << std::endl << "zmag - zatrudnij magazyniera" << std::endl << "zmkt - zatrudnij marketera" << std::endl << "zrob - zatrudnij robotnika" << std::endl << "kred - wez kredyt" << std::endl << "gp - wyswietl informacje o przychodach z ostatnich 12 miesiecy" << std::endl << "kt - zakoncz ture i zobacz podsumowanie miesiaca" << std::endl<<"end - zakoncz gre"<<std::endl;
    std::cout << "Na poczatku gry dysponujesz po jednym pracowniku kazdego typu i aktywami firmy wynoszacymi:" << firma_->PosiadaneAktywa_ << std::endl;
    firma_->rekrutacja("zinz");
    firma_->rekrutacja("zmag");
    firma_->rekrutacja("zmkt");
    firma_->rekrutacja("zrob");
}

void kred(Kredyt* kredyt_)
{
    double Kwota_;
    int CzasSplaty_;
    std::cout << "Podaj kwote pozyczki (nie moze przekroczyc pieciokrotnosci wartosci twojej firmy) i czas splaty (nie moze przekroczyc 60 miesiecy) oddzielone spacja" << std::endl;
    std::cin >> Kwota_ >> CzasSplaty_;
    kredyt_->wezkredyt(Kwota_, CzasSplaty_);
}

void kt(Kredyt* kredyt_,Firma* firma_)
{
    firma_->getparametry();
    firma_->setdochod();
    kredyt_->splackredyt();
    firma_->setaktywa();
    std::cout << "Twoj dochod w tym miesiacu: " << firma_->Dochod_ << std::endl;
    std::cout << "Twoje aktywa w tym miesiacu: " << firma_->PosiadaneAktywa_ << std::endl;
    std::cout << "Wynik twojej firmy po tym miesiacu: " << firma_->WynikFirmy_ << std::endl;
}