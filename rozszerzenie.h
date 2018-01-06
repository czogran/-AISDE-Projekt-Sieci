#pragma once
#pragma once

#include <iostream>
#include <vector>
#include "wezel.h"
#include "sciezka.h"
#include "krawendz.h"
#include"drut.h"
#include<algorithm>
#include<math.h>

bool myfunction(Drut i, Drut j) { return (i.cena_za_wiazke < j.cena_za_wiazke); }// moze vyc >??? na czuja

float wiazka(vector<Drut> druty,Wezel wezel)
{
	 float wiazka=INFINITE;
	 vector<int>tablica;
	 vector<float> koszt_alternatywny;
	 //const int a=druty.size();
	
	// int tablica[11];

	 //int koszt_alternatywny=INFINITE;
	// int koszt_dopelnienia = 100000;
	 int klijenci;
	 int indeks = 0;
	 klijenci = wezel.klijenci;
	 sort(druty.begin(), druty.end(), myfunction);
	 tablica.push_back( floor(klijenci / druty[indeks].pojemnosc));
	 koszt_alternatywny.push_back( druty[indeks].koszt_jednostkowy*tablica[indeks]);
	 klijenci=klijenci - tablica[indeks] * druty[indeks].pojemnosc;
	 indeks++;
	 while (klijenci > 0)
	 {
		 if (druty.size() > indeks) {

			 tablica.push_back(floor(klijenci / druty[indeks].pojemnosc));

			 koszt_alternatywny.push_back(tablica[indeks] * druty[indeks].koszt_jednostkowy);
			 klijenci = klijenci - tablica[indeks] * druty[indeks].pojemnosc;
			 indeks++;
		 }
		 else
		 {
			 tablica.push_back(floor(klijenci / druty[indeks].pojemnosc) );
			
			 klijenci = klijenci - tablica[indeks] * druty[indeks].pojemnosc; 
			 if (klijenci != 0)
				 tablica[indeks]++;
			 koszt_alternatywny.push_back(tablica[indeks] * druty[indeks].koszt_jednostkowy);
		 }
		 
	 }
	//wiazka = koszt_alternatywny[0];
	 //int min=INFINITE;
	 float suma = 0;//koszt_alternatywny[0];
	 for (int i = 0;i < koszt_alternatywny.size()-1;i++)
	 {
		 suma = suma + koszt_alternatywny[i];
		 if (wiazka > suma + druty[i].koszt_jednostkowy)
			 wiazka = suma + druty[i].koszt_jednostkowy;

		cout << "\n" << suma;
	 }
	 suma = suma + koszt_alternatywny[koszt_alternatywny.size()-1];
	 if (wiazka > suma)
		 wiazka = suma ;

	 cout << "\nsuma to:" << suma;

	 /*while (klijenci > 0)
	 {
		 tablica = floor(klijenci / druty[indeks].pojemnosc);
		 klijenci = klijenci - druty[indeks].pojemnosc * tablica;
		 if (koszt_alternatywny < tablica*druty[indeks].pojemnosc)
		 {
			 wiazka = wiazka + koszt_alternatywny;

		 }
		 if (koszt_alternatywny > (tablica + 1)*druty[indeks].pojemnosc)
		 {
				if (klijenci>0)
				 koszt_alternatywny = (tablica + 1)*druty[indeks].pojemnosc);
				else
				{
					wiazka = wiazka + tablica *druty[indeks].pojemnosc);
					break;
				}
		 }
		
	 }
 */
	 cout << "\n wiazka to: " << wiazka << "\n";
	return wiazka;
}

Sciezka rozszerzenie(vector<Wezel> wezel, vector<Krawendz>krawendz, int start, int end,int koszt_drutu)
{
	Sciezka sciezka(1);
	int aktualny_nr;
	double najmniejszy_koszt;

	int nr_wezla;
	aktualny_nr = start;
	wezel[aktualny_nr - 1].wejscie = start;
	wezel[aktualny_nr - 1].koszt = 0; //na start trzeba ustawic 0
									  //while (aktualny_nr =~ end)
	for (int n = 0;n<wezel.size();n++) //zmienione z petli nisekonczonej na przypadek gdy jakis wezel jest niepoloczony
	{
		//cout << "\n" << aktualny_nr<<"   "<<end<<"\n";
		for (int i = 0;i < krawendz.size();i++)
		{
			if (krawendz[i].wezel_a == aktualny_nr)
			{
				if (wezel[krawendz[i].wezel_b - 1].koszt > krawendz[i].dlugosc*koszt_drutu+krawendz[i].koszt_zakopania + wezel[aktualny_nr - 1].koszt)			// (wezel[krawendz[i].wezel_b - 1].wejscie == 0 &(wezel[krawendz[i].wezel_b - 1].koszt == 0 || wezel[krawendz[i].wezel_b - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt))
				{
					wezel[krawendz[i].wezel_b - 1].koszt = krawendz[i].dlugosc*koszt_drutu + krawendz[i].koszt_zakopania + wezel[aktualny_nr - 1].koszt;
					wezel[krawendz[i].wezel_b - 1].wyjscie = krawendz[i].wezel_a;
				}
			}
			if (krawendz[i].wezel_b == aktualny_nr)
			{

				if (wezel[krawendz[i].wezel_a - 1].koszt > krawendz[i].dlugosc*koszt_drutu + krawendz[i].koszt_zakopania + wezel[aktualny_nr - 1].koszt)       //(wezel[krawendz[i].wezel_a - 1].wejscie==0 &(wezel[krawendz[i].wezel_a - 1].koszt == 0 || wezel[krawendz[i].wezel_a - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt))
				{
					wezel[krawendz[i].wezel_a - 1].koszt = krawendz[i].dlugosc*koszt_drutu + krawendz[i].koszt_zakopania + wezel[aktualny_nr - 1].koszt;
					wezel[krawendz[i].wezel_a - 1].wyjscie = krawendz[i].wezel_b;
				}
			}
		}

		najmniejszy_koszt = 2147483647;
		for (int i = 0; i < wezel.size();i++)
		{
			if (wezel[i].koszt < najmniejszy_koszt)  //((najmniejszy_koszt == 0 || wezel[i].koszt < najmniejszy_koszt))
			{
				if (wezel[i].wejscie == 0 & wezel[i].koszt>0) // zalozenie ze nie do poloczonego nie da sie dojsc szybciej, koszt>0 by nie dodac jeszcze raz startowego
				{
					najmniejszy_koszt = wezel[i].koszt;
					nr_wezla = i; //indeksowanie od 0
				}
			}

		}
		wezel[nr_wezla].wejscie = wezel[nr_wezla].wyjscie;
		aktualny_nr = wezel[nr_wezla].numer;
		if (aktualny_nr == end)
			break;
	}

	for (int i = 0; i >-11;i++)
	{
		sciezka.wezly.push_back(wezel[aktualny_nr - 1]);
		aktualny_nr = wezel[aktualny_nr - 1].wejscie;
		if (aktualny_nr == start)
		{
			sciezka.wezly.push_back(wezel[aktualny_nr - 1]);
			break;
		}

	}
	cout << "\n";

	for (int i = 0; i < sciezka.wezly.size();i++)
	{
		cout << sciezka.wezly[i].numer;

	}
	sciezka.koszt = wezel[end - 1].koszt;
	cout << "\nrozszerzenie koszt to: " << wezel[end - 1].koszt << "\n";
	rysuj_graf_sciezka(wezel, krawendz, sciezka);
	return sciezka;
}
