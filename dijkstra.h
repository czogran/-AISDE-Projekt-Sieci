#pragma once

#include <iostream>
#include <vector>
#include "wezel.h"
#include "sciezka.h"
#include "krawendz.h"


void dijkstra(vector<Wezel> wezel, vector<Krawendz>krawendz, int start, int end)
{
	Sciezka sciezka(1);
	int aktualny_nr;
	double najmniejszy_koszt;
	
	int nr_wezla;
	aktualny_nr = start;
	wezel[aktualny_nr - 1].wejscie = start;
	wezel[aktualny_nr - 1].koszt = 0; //na start trzeba ustawic 0
	//while (aktualny_nr =~ end)
	for(int n=0;n<12;n--) //petla nieskonczona nie wiem czemu z while nie dziala
	{
		//cout << "\n" << aktualny_nr<<"   "<<end<<"\n";
		for (int i = 0;i < krawendz.size();i++)
		{
			if (krawendz[i].wezel_a == aktualny_nr)
			{
				if( wezel[krawendz[i].wezel_b - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt)			// (wezel[krawendz[i].wezel_b - 1].wejscie == 0 &(wezel[krawendz[i].wezel_b - 1].koszt == 0 || wezel[krawendz[i].wezel_b - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt))
				{
					wezel[krawendz[i].wezel_b - 1].koszt = krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt;
					wezel[krawendz[i].wezel_b - 1].wyjscie = krawendz[i].wezel_a;
				}
			}
			if (krawendz[i].wezel_b == aktualny_nr)
			{
				if ( wezel[krawendz[i].wezel_a - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt)       //(wezel[krawendz[i].wezel_a - 1].wejscie==0 &(wezel[krawendz[i].wezel_a - 1].koszt == 0 || wezel[krawendz[i].wezel_a - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt))
				{
					wezel[krawendz[i].wezel_a - 1].koszt = krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt;
					wezel[krawendz[i].wezel_a - 1].wyjscie = krawendz[i].wezel_b;
				}
			}
		}
		/*
		for (int n = 0; n < wezel.size();n++)
			{
				cout << "\nnr: " << n+1<<"      "<<wezel[n].koszt;
			}
			*/
		najmniejszy_koszt = 2147483647;
		for (int i = 0; i < wezel.size();i++)
		{
			if	(wezel[i].koszt < najmniejszy_koszt)  //((najmniejszy_koszt == 0 || wezel[i].koszt < najmniejszy_koszt))
			{
				if (wezel[i].wejscie == 0 &wezel[i].koszt>0)
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
	cout << "\nkoszt to: " << wezel[end - 1].koszt << "\n";
}
