#pragma once

#pragma once

#include <iostream>
#include <vector>
#include "wezel.h"
#include "sciezka.h"
#include "krawendz.h"
#include "sfml_rysowanie.h"
#include "dijkstra.h"


void steiner(vector<Wezel> wezel, vector<Krawendz>krawendz, bool czy_skierowane)
{

	Sciezka sc(1);
	Sciezka koncowa(1);
	vector <Sciezka>koncowe;
	vector <Krawendz>zapasowa;
	zapasowa = krawendz;
	int end;
	double koszt=0;
	int start;
	for (int i = 0; i < wezel.size();i++)
	{
		if (wezel[i].obowiazkowy == 1)
		{
			start = wezel[i].numer;
			
			//koncowe.push_back(Sciezka(1));
		
		
		for (int k = 0; k < wezel.size();k++)
		{
			if (wezel[k].obowiazkowy == 1 && wezel[k].numer != start)
			{
				end = wezel[k].numer;
				sc = dijkstra(wezel, krawendz, start, end, false);
				koszt = koszt + sc.koszt;
				for (int i = 0;i < sc.wezly.size() - 1;i++) //
				{
					for (int n = 0; n < krawendz.size();n++)
					{

						if (krawendz[n].wezel_a == sc.wezly[i].numer && krawendz[n].wezel_b == sc.wezly[i + 1].numer)
						{
							koncowa.krawendzie.push_back(krawendz[n]);
							krawendz[n].dlugosc = 0.01;
						}
						if (krawendz[n].wezel_b == sc.wezly[i].numer && krawendz[n].wezel_a == sc.wezly[i + 1].numer)
						{
							koncowa.krawendzie.push_back(krawendz[n]);
							krawendz[n].dlugosc = 0.01;
						}

					}
					
				}
				
			}
			
			}
			koncowe.push_back(koncowa);
				koncowe[koncowe.size()-1].koszt = koszt;
				koncowa.krawendzie.clear();
				koszt = 0;
				krawendz = zapasowa;
		}
	}
	int indeks = 0;
//	indkes = koncowe[0].koszt;
	for (int i = 1; i < koncowe.size();i++)
	{
		if (koncowe[i].koszt < koncowe[indeks].koszt)
			indeks = i;
	}

	for (int n = 0; n < krawendz.size();n++)
	{
		cout << krawendz[n].dlugosc << "\n";
	}
	rysuj_graf_sciezka_steiner(wezel, krawendz, koncowe[indeks]);
}
