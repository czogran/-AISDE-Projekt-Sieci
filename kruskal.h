#pragma once
#include "krawendz.h"
#include "wezel.h"
#include "sciezka.h"
#include <math.h>



void kruskal(vector<Krawendz> kraw, vector<Wezel> wezel)
{
	Sciezka sciezka(1);
	int test;
	test = 0;
	int indeks_1, indeks_2, indeks_3, indeks_4;
	int wezel_pierwszy;
	int wezel_drugi;
	vector <int> zapasowy;
	vector<Krawendz> operacyjny;
	operacyjny = kraw;
	int size;
	size = operacyjny.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - 1; j++)
		{
			if (operacyjny[j].dlugosc > operacyjny[j + 1].dlugosc)
				swap(operacyjny[j], operacyjny[j + 1]);

		}
	}
/*
	for (int n = 0;n < operacyjny.size();n++)
	{
		cout << operacyjny[n].dlugosc << "\n";
	}
*/

	for (int n = 0;n < wezel.size();n++)							//do tworzenia sztywnej tablicy, by ³atwiej by³o siê po niej poruszac
	{
		for (int i = 0;i < wezel.size();i++)
			wezel[n].poloczenia.push_back(0);
	}


	
		for (int n = 0;n < operacyjny.size();n++) //chodzimy po wszystkich krawendziach az znajdziemy te które lacza
		{
			wezel_pierwszy = operacyjny[n].wezel_a-1; //minus 1 by indeksowac od 0
			wezel_drugi = operacyjny[n].wezel_b-1;
			test = 0;
			for (int i = 0;i < wezel.size();i++) //szuka czy siê pokrywaja
			{
				if (wezel[wezel_pierwszy].poloczenia[i] == 1 & wezel[wezel_drugi].poloczenia[i] == 1)
				{
					
					test = 1;
				}
			}
			
			if (test == 0) //test 0 znaczy sukces, gdybysmy musieli pozniej przeprowadzac wiecej, taka konwencja jest latwiejsza w obsludze
			{
				sciezka.wezly.push_back(wezel[wezel_pierwszy]); //tutaj z nadmiarem si dodaja, ale pozniej widac ktore wezly po kolei sa dodawane
				sciezka.wezly.push_back(wezel[wezel_drugi]);
				sciezka.krawendzie.push_back(operacyjny[n]);
				//tym nizej mozna zobaczyc na szybko w jakiej kolejnosci sa dodawane wezly
				/*
				for (int i = 0; i < sciezka.wezly.size();i++)
				{
					cout << sciezka.wezly[i].numer;
				}
				cout << "\n";
				*/


				wezel[wezel_pierwszy].poloczenia[wezel_pierwszy] = 1; //jest z nadmiarem, ale poswiecilem szybkosc dla mniejszej liczby lini kodu
				wezel[wezel_drugi].poloczenia[wezel_drugi] = 1;
				wezel[wezel_pierwszy].poloczenia[wezel_drugi] = 1;
				wezel[wezel_drugi].poloczenia[wezel_pierwszy] =1;

				for (int i = 0;i < wezel.size();i++) //by zaktualizowac tablice
				{
					if (wezel[wezel_pierwszy].poloczenia[i] == 1)
					{
						for (int n = 0;n < wezel.size();n++)
						{
							indeks_1 = wezel[wezel_drugi].poloczenia[n];
							if (indeks_1 == 1)
							{
								wezel[n].poloczenia[i] = 1;
							}
							
						}
					}
				}

				for (int i = 0;i < wezel.size();i++)  //by zaktualizowac tablice
				{
					if (wezel[wezel_drugi].poloczenia[i] == 1)
					{
						for (int n = 0; n < wezel.size();n++)
						{
							indeks_2 = wezel[wezel_pierwszy].poloczenia[n];
							if (indeks_2 == 1)
							{
								wezel[n].poloczenia[i] = 1;
								
							}
							
						}
					}
				}



			}


		}
		

	cout << "\n";

	for (int n = 0;n < 4;n++) //wyswietlanie by pokazac, ze jest OK
	{
		cout << sciezka.krawendzie[n].dlugosc<<"\n";

	}
}

























	/*
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
				//wezel[wezel_pierwszy - 1].poloczenia.push_back(wezel_drugi);
				//wezel[wezel_drugi - 1].poloczenia.push_back(wezel_pierwszy);

				/// próba aktualizowania wektorow poloczen
				//zapasowy.clear();
				//zapasowy = wezel[wezel_drugi].poloczenia;
				wezel[wezel_pierwszy - 1].poloczenia.push_back(wezel_drugi);
				indeks_1 = wezel[wezel_pierwszy - 1].poloczenia.size();
				indeks_2=wezel[wezel_drugi - 1].poloczenia.size();

				for (int n = 0; n <indeks_1; n++) 
				{
					//cout << "A";
					for (int i = 0;i < indeks_2;i++)
					{
						
						wezel[wezel[wezel_drugi-1].poloczenia[n]-1].poloczenia.push_back(wezel[wezel_pierwszy - 1].poloczenia[i]);
						//cout << "b";
					}
				}

				wezel[wezel_drugi - 1].poloczenia.push_back(wezel_pierwszy);
				
				for (int n = 0;n <indeks_2 ;n++)
				{
					cout << "t";
					for (int i = 0;i <  indeks_1;i++)
					{
						wezel[wezel[wezel_pierwszy - 1].poloczenia[n]-1].poloczenia.push_back(wezel[wezel_drugi - 1].poloczenia[i]);
					}
				}


				//wezel[wezel_pierwszy - 1].poloczenia.push_back(wezel_drugi);
				
				//cout << "t";
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
*/