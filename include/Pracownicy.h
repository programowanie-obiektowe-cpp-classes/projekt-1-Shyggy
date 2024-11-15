#pragma once


class Pracownik
{
public:
	std::string Imie_;
	static double Wynagrodzenie_;
	Pracownik() {};
	virtual void id()=0;
};

class Inzynier: public Pracownik
{
public:
	static const int CI_;
	std::string Wydzial_;
	Inzynier()
	{
		Imie_ = getRandomName();
		Wydzial_ = getWydzialName();
		Wynagrodzenie_=5000.0;
	}
	void id() override
	{
		std::cout << "Imie pracownika: " << Imie_ << std::endl << "Wynagrodzenie pracownika: " << Wynagrodzenie_ << std::endl << "Ukonczony wydzial: " << Wydzial_ << std::endl;
	}
};

class Magazynier : public Pracownik
{
public:
	static const int CMag_;
	bool Wozek_;
	Magazynier()
	{
		Imie_ = getRandomName();
		Wozek_ = get_random_wozek();
		Wynagrodzenie_=3500.0;
	}
	void id() override
	{
		if (Wozek_==1) { std::cout << "Imie pracownika: " << Imie_ << std::endl << "Wynagrodzenie pracownika: " << Wynagrodzenie_ << std::endl << "Pracownik posiada uprawnienia na wozki widlowe" << std::endl; }
		else { std::cout << "Imie pracownika: " << Imie_ << std::endl << "Wynagrodzenie pracownika: " << Wynagrodzenie_ << std::endl << "Pracownik nie posiada uprawnien na wozki widlowe" << std::endl; }
	}
};

class Marketer : public Pracownik
{
public:
	static const int CMkt_;
	int Obserwujacy_;
	Marketer()
	{
		Imie_ = getRandomName();
		Obserwujacy_ = get_random_obserwujacy();
		Wynagrodzenie_=4500.0;

	}
	void id() override
	{
		std::cout << "Imie pracownika: " << Imie_ << std::endl << "Wynagrodzenie pracownika: " << Wynagrodzenie_ << std::endl << "Liczba obserwujacych: "<<Obserwujacy_<<std::endl;
	}
};

class Robotnik : public Pracownik
{
public:
	static const int CRob_;
	double But_;
	Robotnik()
	{
		Imie_ = getRandomName();
		But_ = get_random_but();
		Wynagrodzenie_=3250.0;
	}
	void id() override
	{
		std::cout << "Imie pracownika: " << Imie_ << std::endl << "Wynagrodzenie pracownika: " << Wynagrodzenie_ << std::endl<<"Rozmiar buta pracownika: "<<But_<<std::endl;
	}
};
