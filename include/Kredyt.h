#pragma once
class Kredyt
{
public:
	static const int WspolczynnikKredytu_ = 5;
	static const int MaksKredytow_ = 5;

	int IloscKredytow_;
	int MaksOkresSplaty = 60;
	int CzasKredytu_;

	double Rata_;
	double Odsetki_;
	double KwotaSplacona_;
	double WysokoscKredytu_;



	Firma* firma_{ nullptr };

	std::unique_ptr<Kredyt> KredytArray[MaksKredytow_]{ nullptr };
	Kredyt* operator[](int index) { return KredytArray[index].get(); }

	Kredyt(Firma* firma)
	{
		firma_ = firma;
		for (int i = 0; i < MaksKredytow_; ++i)
		{
			KredytArray[i] = nullptr;
		}
	}

	Kredyt(double kwota_, int OkresSplaty_)
	{
		{
			WysokoscKredytu_ = kwota_;
			CzasKredytu_ = OkresSplaty_;
			if (CzasKredytu_ <= 6) { Odsetki_ = 0.01 * WysokoscKredytu_; }
			else if (CzasKredytu_ <= 12) { Odsetki_ = 0.05 * WysokoscKredytu_; }
			else { Odsetki_ = 0.1 * WysokoscKredytu_; }
			Rata_ = (WysokoscKredytu_ + Odsetki_) / static_cast<double>(CzasKredytu_);
		}

	}


	


	void wezkredyt(double kwota_, int OkresSplaty_)
	{
		if (OkresSplaty_ > MaksOkresSplaty)
		{
			std::cout << "Maksymalny okres splaty zostal przekroczony" << std::endl;
			return;
		}
		if (kwota_ > WspolczynnikKredytu_ * firma_->getwartosc())
		{
			std::cout << "Maksymalna kwota zostala przekroczona" << std::endl;
			return;
		}
		if (IloscKredytow_ >= MaksKredytow_)
		{
			std::cout << "Limit kredytow zostal przekroczony" << std::endl;
			return;
		}
		if (firma_->getwartosc() != firma_->getwartosc())
		{
			std::cout << "Nie mozna zaciagnac kredytu bez wygenerowania przychodu. Zakoncz ture aby wygenerowac przychod" << std::endl;
			return;
		}
		for (int i = 0; i != MaksKredytow_; ++i)
			if (KredytArray[i] == nullptr)
			{
				KredytArray[i] = std::make_unique<Kredyt>(kwota_, OkresSplaty_);
				IloscKredytow_++;
				firma_->PosiadaneAktywa_ += KredytArray[i]->WysokoscKredytu_;
				firma_->WynikFirmy_ -= KredytArray[i]->WysokoscKredytu_;
				std::cout << "Zaciagnieto kredyt na " << KredytArray[i]->WysokoscKredytu_ << "do splacenia w ciagu " << KredytArray[i]->CzasKredytu_ << std::endl;
				std::cout << "Odestki wyniosa " << KredytArray[i]->Odsetki_ << ", a rata kredytu " << KredytArray[i]->Rata_ << std::endl;
				return;
			}
		if (IloscKredytow_ <= MaksKredytow_)
		{
			KredytArray[IloscKredytow_++] = std::make_unique<Kredyt>(kwota_, OkresSplaty_);
			firma_->PosiadaneAktywa_ += KredytArray[IloscKredytow_]->WysokoscKredytu_;
			firma_->WynikFirmy_ -= KredytArray[IloscKredytow_]->WysokoscKredytu_;
			std::cout << "Zaci¹gnieto kredyt na " << KredytArray[IloscKredytow_]->WysokoscKredytu_ << "do spacenia w ciagu " << KredytArray[IloscKredytow_]->CzasKredytu_ << std::endl;
			std::cout << "Odestki wyniosa " << KredytArray[IloscKredytow_]->Odsetki_ << ", a rata kredytu " << KredytArray[IloscKredytow_]->Rata_ << std::endl;
			return;
		}
	}

	void splackredyt()
	{
		for (int i = 0; i != IloscKredytow_; ++i)
		{
			if (KredytArray[i]->KwotaSplacona_ == (KredytArray[i]->WysokoscKredytu_ + KredytArray[i]->Odsetki_) && KredytArray[i] != nullptr)
			{
				firma_->WynikFirmy_ += KredytArray[i]->WysokoscKredytu_;
				delete[] KredytArray[i].get();
				KredytArray[i] = nullptr;
				IloscKredytow_--;
			}
			else if (KredytArray[i] != nullptr)
			{
				KredytArray[i]->KwotaSplacona_ += KredytArray[i]->Rata_;
				firma_->Dochod_ -= KredytArray[i]->Rata_;
			}
		}
	}
};