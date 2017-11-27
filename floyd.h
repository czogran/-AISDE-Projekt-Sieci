
#pragma once

#include <iostream>
#include "wezel.h"
#include "krawendz.h"
#include "sciezka.h"



	using namespace std;

	void floyd(vector <Wezel> wezely, vector <Krawendz> krawedzie, int nr_wezla_pocz,int nr_wezla_kon)
	{
		const int size_a = wezely.size();
		double **tablica;//[size_a]size_a];
		int **poloczenia;
		tablica = new double *[size_a];
		poloczenia = new int *[size_a];
		Sciezka sciezka(1);
		for (int i = 0; i < size_a; i++)
		{
			tablica[i] = new double[size_a];
			poloczenia[i] = new int[size_a];
			for (int n = 0; n < size_a; n++)
			{
				poloczenia[i][n] = -1;
				if (i == n)
					tablica[i][n] = 0;
				else
					tablica[i][n] = INFINITY;
			}
		}




		for (int i = 0; i < krawedzie.size(); i++)
		{
			tablica[krawedzie[i].wezel_a - 1][krawedzie[i].wezel_b - 1] = krawedzie[i].dlugosc;
		}

		for (int i = 0; i < krawedzie.size(); i++)
		{
			tablica[krawedzie[i].wezel_b - 1][krawedzie[i].wezel_a - 1] = krawedzie[i].dlugosc;
		}

		for (int i = 0; i < size_a; i++)
		{
			for (int n = 0; n < size_a; n++)
			{
				cout << tablica[i][n] << "     ";
			}
			cout << "\n";
		}
		cout << "\n";
		double w;
		for (int k = 0; k < size_a; k++)
			for (int i = 0; i < size_a; i++)
				for (int j = 0; j < size_a; j++)
				{
					// ((tablica[i][k] == INFINITY) || (tablica[k][j] == INFINITY)) continue;
					w = tablica[i][k] + tablica[k][j];
					if (tablica[i][j] > w)
					{
						poloczenia[i][j] = k;//indeksowanie od 0-> 0 znaczy, ze jest to 1 wezel

						tablica[i][j] = w;
						tablica[j][i] = w; //gdy jest nieskierowany
						poloczenia[j][i] = k;//gdy jest nieskierowany
					}
				}


		for (int i = 0; i < size_a; i++)
		{
			for (int n = 0; n < size_a; n++)
			{
				cout << tablica[i][n] << "     ";
			}
			cout << "\n";
		}

		
		cout << "\n" << "Poloczenia: " << "\n";

		for (int i = 0; i < size_a; i++)
		{
			for (int n = 0; n < size_a; n++)
			{
				cout << poloczenia[i][n] << "     ";
			}
			cout << "\n";
		}



		int start = nr_wezla_pocz - 1;
		int end = nr_wezla_kon - 1;
		int const_end = nr_wezla_kon - 1;
		int new_wezel = nr_wezla_pocz - 1;
		int temp = -1;
		int k = poloczenia[2][4];
		sciezka.wezly.push_back(wezely[start]);	//dodanie peirwszego elementu

		if (poloczenia[start][end] != -1)				//Na pocz?tku zrobi?em petle while ale nie dzia?a?o nwm czemu wiec zrobilem do/while w if
		{
			do
			{
				temp = end;
				end = poloczenia[start][end];
				if (poloczenia[start][end] = -1)
				{
					new_wezel = poloczenia[start][temp];
					sciezka.wezly.push_back(wezely[new_wezel]);		//dodanie elementu nastepnego
					start = new_wezel;
					end = const_end;
				}

			} while (poloczenia[start][end] != -1);
		}

		sciezka.wezly.push_back(wezely[end]);			//dodanie elementu ostatniego


		rysuj_graf_sciezka(wezely,krawedzie, sciezka);


		for (int i = 0; i < size_a; i++)
			{
				delete[] poloczenia[i];
				delete[] tablica[i];
			}

			delete[] poloczenia;
			delete[]  tablica; // tu moze byc wyciek pamieci

		

	}
