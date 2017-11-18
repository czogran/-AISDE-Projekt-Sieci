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
	wezel[aktualny_nr - 1].wejscie = 1;
	//while (aktualny_nr =~ end)
	for(int n=0;n<12;n--)
	{
		cout << "\n" << aktualny_nr<<"   "<<end<<"\n";
		for (int i = 0;i < krawendz.size();i++)
		{

			if (krawendz[i].wezel_a == aktualny_nr)// || krawendz.[i].wezel_b == aktualny_nr)
			{
				//cout << wezel[krawendz[i].wezel_b - 1].koszt;
				if (wezel[krawendz[i].wezel_b - 1].wejscie == 0 &(wezel[krawendz[i].wezel_b - 1].koszt == 0 || wezel[krawendz[i].wezel_b - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt))
				{
					wezel[krawendz[i].wezel_b - 1].koszt = krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt;
				//	cout << wezel[krawendz[i].wezel_b - 1].koszt << "\npierwszy if\n";//krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt<<"\npierwszy if\n";
				}
			}
			if (krawendz[i].wezel_b == aktualny_nr)
			{
				if (wezel[krawendz[i].wezel_a - 1].wejscie==0 &(wezel[krawendz[i].wezel_a - 1].koszt == 0 || wezel[krawendz[i].wezel_a - 1].koszt > krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt))
				{
					wezel[krawendz[i].wezel_a - 1].koszt = krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt;
					//cout << krawendz[i].dlugosc + wezel[aktualny_nr - 1].koszt << "\ndrugi if\n";
				}
			}

			
		}
		for (int n = 0; n < wezel.size();n++)
			{
				cout << "\nnr: " << n+1<<"      "<<wezel[n].koszt;
			}
		najmniejszy_koszt = 0;
		for (int i = 0; i < wezel.size();i++)
		{
			//cout << wezel[i].koszt<<"\n";
			if ((najmniejszy_koszt == 0 || wezel[i].koszt < najmniejszy_koszt))
			{
				if (wezel[i].wejscie == 0 &wezel[i].koszt>0)
				{
					//cout << wezel[i].koszt << "\n";
					najmniejszy_koszt = wezel[i].koszt;
					nr_wezla = i; //indeksowanie od 0
				}
			}
			
		}
		//cout << "\n" << aktualny_nr;
		wezel[nr_wezla].wejscie = aktualny_nr;
		aktualny_nr = wezel[nr_wezla].numer;
		if (aktualny_nr == end)
			break;
	}
	/*
	for (int i = 0; i < 12;i++)
	{
		sciezka.wezly.push_back(wezel[aktualny_nr - 1]);
		aktualny_nr = wezel[aktualny_nr - 1].wejscie;

	}
	cout << "\n";
	for (int i = 0; i < 12;i++)
	{
		cout << sciezka.wezly[i].numer;

	}*/
	cout << "\nkoszt to: " << wezel[end - 1].koszt << "\n";
}
