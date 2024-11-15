#pragma once
class Firma
{
public:

	static const int RozmiarFirmy_ = 20;
	static const int OkresRozliczeniowy_ = 12;

	unsigned int LiczbaPracowników_ = 0;
	unsigned int LiczbaInz_;
	unsigned int LiczbaMag_;
	unsigned int LiczbaMkt_;
	unsigned int LiczbaRob_;
	unsigned int PojemnoscMagazynu_;
	unsigned int CenaProduktu_;
	unsigned int Popyt_;
	unsigned int ProdukcjaTeoretyczna_;
	unsigned int ProdukcjaRzeczywista_;
	unsigned int IndexPrzychodu_ = 0;

	double HistoriaPrzychodow[OkresRozliczeniowy_] = { 0 };
	double Dochod_;
	double PosiadaneAktywa_;
	double WynikFirmy_;

	std::unique_ptr<Pracownik> FirmaArray[RozmiarFirmy_];
	Pracownik* operator[](int index) { return FirmaArray[index].get(); }
	Firma() {
		for (int i = 0; i < RozmiarFirmy_; ++i) {
			FirmaArray[i] = nullptr;
		}
	}

	void rekrutacja(const::std::string& str)
	{
		if (LiczbaPracowników_ < RozmiarFirmy_)
		{
			if (str == "zinz") { std::cout << "Zatrudniono inzyniera" << std::endl; FirmaArray[LiczbaPracowników_++] = std::make_unique<Inzynier>(); }
			if (str == "zmag") { std::cout << "Zatrudniono magazyniera" << std::endl; FirmaArray[LiczbaPracowników_++] = std::make_unique<Magazynier>(); }
			if (str == "zmkt") { std::cout << "Zatrudniono marketera" << std::endl; FirmaArray[LiczbaPracowników_++] = std::make_unique<Marketer>(); }
			if (str == "zrob") { std::cout << "Zatrudniono robotnika" << std::endl; FirmaArray[LiczbaPracowników_++] = std::make_unique<Robotnik>(); }
		}
		else
			std::cout << "Liczba pracownikow zostala przekroczona" << std::endl;
	}

	void identyfikacja()
	{
		for (int index = 0; index != LiczbaPracowników_; index++)
		{
			std::cout << index + 1 << std::endl;
			FirmaArray[index]->id();
		}
	}

	void headcount()
	{
		LiczbaInz_ = LiczbaMag_ = LiczbaMkt_ = LiczbaRob_ = 0;
		for (int index = 0; index != LiczbaPracowników_; index++)
		{
			if (dynamic_cast <Inzynier*> (FirmaArray[index].get()) != nullptr) { LiczbaInz_++; }
			else if (dynamic_cast <Magazynier*> (FirmaArray[index].get()) != nullptr) { LiczbaMag_++; }
			else if (dynamic_cast <Marketer*> (FirmaArray[index].get()) != nullptr) { LiczbaMkt_++; }
			else if (dynamic_cast <Robotnik*> (FirmaArray[index].get()) != nullptr) { LiczbaRob_++; }
			else { std::cout << "ERROR"; }

		}
	}

	void getparametry()
	{
		headcount();
		CenaProduktu_ = LiczbaInz_ * Inzynier::CI_;
		PojemnoscMagazynu_ = LiczbaMag_ * Magazynier::CMag_;
		Popyt_ = LiczbaMkt_ * Marketer::CMkt_;
		ProdukcjaTeoretyczna_ = LiczbaRob_ * Robotnik::CRob_;

	}

	double sprzedaj()
	{
		if (ProdukcjaTeoretyczna_ < PojemnoscMagazynu_) { ProdukcjaRzeczywista_ = ProdukcjaTeoretyczna_; }
		else { ProdukcjaRzeczywista_ = PojemnoscMagazynu_; }
		if (ProdukcjaRzeczywista_ > Popyt_) { ProdukcjaRzeczywista_ = Popyt_; }
		double Przychod_ = static_cast<double>(CenaProduktu_) * static_cast<double>(ProdukcjaRzeczywista_);

		if (IndexPrzychodu_ < OkresRozliczeniowy_) { HistoriaPrzychodow[IndexPrzychodu_] = Przychod_; IndexPrzychodu_++; }
		else
		{
			for (int i = 1; i != OkresRozliczeniowy_; i++)
			{
				HistoriaPrzychodow[i - 1] = HistoriaPrzychodow[i];
			}
			HistoriaPrzychodow[OkresRozliczeniowy_ - 1] = Przychod_;
		}
		return Przychod_;

	}
	void printprzychod()
	{
		for (int i = 0; i != OkresRozliczeniowy_; i++)
		{
			std::cout << "Przychod z miesiaca " << i << std::endl << HistoriaPrzychodow[i] << std::endl;
		}
	}

	double getwartosc()
	{
		double SumaPrzychodu_=0;
		double SredniPrzychod_=0;
		if (IndexPrzychodu_ < OkresRozliczeniowy_)
		{
			for (int i = 0; i != IndexPrzychodu_; i++)
			{
				SumaPrzychodu_ += HistoriaPrzychodow[i];
			}
			SredniPrzychod_ = SumaPrzychodu_ / static_cast<double>(IndexPrzychodu_);
		}
		else
		{
			for (int i = 0; i != OkresRozliczeniowy_; i++)
			{
				SumaPrzychodu_ += HistoriaPrzychodow[i];
			}
			SredniPrzychod_ = SumaPrzychodu_ / static_cast<double>(OkresRozliczeniowy_);
		}
		return SredniPrzychod_;
	}

	double getwyplaty()
	{
		double Wyplaty_;
		headcount();
		Wyplaty_ = static_cast<double>(LiczbaInz_) * Inzynier::Wynagrodzenie_ + static_cast<double>(LiczbaMag_) * Magazynier::Wynagrodzenie_ + static_cast<double>(LiczbaMkt_) * Marketer::Wynagrodzenie_ + static_cast<double>(LiczbaRob_) * Robotnik::Wynagrodzenie_;
		return Wyplaty_;
	}

	void setdochod()
	{
		Dochod_ = sprzedaj() - getwyplaty();
	}

	void setaktywa()
	{
		PosiadaneAktywa_ += Dochod_;
		WynikFirmy_ += Dochod_;
	}
};