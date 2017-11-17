#pragma once
#include "krawendz.h"
#include "wezel.h"
#include "sciezka.h"
#include <math.h>

void kruskal(vector<Krawendz> kraw,vector<Wezel> wezel)
{
	Sciezka sciezka(1);
	int test;
	test = 0;
	int wezel_pierwszy;
	int wezel_drugi;
	vector<Krawendz> operacyjny;
	operacyjny = kraw;
	int size;
	size= operacyjny.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (operacyjny[j].dlugosc > operacyjny[j + 1].dlugosc)
				swap(operacyjny[j], operacyjny[j + 1]);

		}
	}




	
	for (int n = 0;n < operacyjny.size();n++)
	{
		cout << operacyjny[n].dlugosc << "\n";
	}
	
	

	for (int ile_poloczonych = 1; ile_poloczonych < wezel.size();)
	{
		
		for (int n = 0;n < operacyjny.size();n++)
		{
			test = 0;
			wezel_pierwszy = operacyjny[n].wezel_a;
			wezel_drugi = operacyjny[n].wezel_b;
			for (int i = 0;i < wezel[wezel_pierwszy - 1].poloczenia.size();i++)
			{
				if (wezel[wezel_pierwszy - 1].poloczenia[i] == wezel_drugi)
				{
					test = 1;
				}
				
			}
			if (test == 0)
			{
				sciezka.wezly.push_back(wezel[wezel_pierwszy - 1]);
				sciezka.wezly.push_back(wezel[wezel_drugi - 1]);
				wezel[wezel_pierwszy - 1].poloczenia.push_back(wezel_drugi);
				wezel[wezel_drugi - 1].poloczenia.push_back(wezel_pierwszy);

				/// próba aktualizowania wektorow poloczen
				/*
				for (int n = 0; n < wezel[wezel_drugi - 1].poloczenia.size();n++) 
				{
					for (int i = 0;i < wezel[wezel_pierwszy - 1].poloczenia.size();i++)
					{

						wezel[wezel[wezel_drugi-1].poloczenia[n]].poloczenia.push_back(wezel[wezel_pierwszy - 1].poloczenia[i]);
					}
				}


				for (int n = 0;n < wezel[wezel_pierwszy - 1].poloczenia.size();n++)
				{
					for (int i = 0;i < wezel[wezel_drugi - 1].poloczenia.size() - 1;i++)
					{
						wezel[wezel[wezel_pierwszy - 1].poloczenia[n]].poloczenia.push_back(wezel[wezel_drugi - 1].poloczenia[i]);
					}
				}*/
				sciezka.krawendzie.push_back(operacyjny[n]);
				ile_poloczonych++;
			}
		}
		//cout << "t jestem";
		for (int i = 0;i < 4;i++)
		{
			cout << "\n" << sciezka.krawendzie[i].dlugosc;
		}
	}


}
