#pragma once

#include <iostream>
#include "wezel.h"
#include "krawendz.h"
#include "sciezka.h"



using namespace std;

void floyd(vector <Wezel> wezely, vector <Krawendz> krawedzie)
{
	const int size_a=wezely.size();
	double **tablica;//[size_a]size_a];
	int **poloczenia;
	tablica = new double *[size_a];
	poloczenia = new int *[size_a];
	for (int i = 0;i < size_a;i++)
	{
		tablica[i] = new double[size_a];
		poloczenia[i] = new int[size_a];
		for (int n = 0;n < size_a;n++)
		{
			poloczenia [i][n] = 0;
			if (i == n)
				tablica[i][n] = 0;
			else
				tablica[i][n] = INFINITY;
		}
	}
	

	

	for (int i = 0; i < krawedzie.size();i++)
	{
		tablica[krawedzie[i].wezel_a-1][krawedzie[i].wezel_b-1] = krawedzie[i].dlugosc;
	}

	for (int i = 0; i < krawedzie.size();i++)
	{
		tablica[krawedzie[i].wezel_b-1][krawedzie[i].wezel_a-1] = krawedzie[i].dlugosc;
	}

	for (int i = 0;i < size_a;i++)
		{
			for (int n = 0;n < size_a;n++)
			{
				cout << tablica[i][n] <<"     ";
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


	for (int i = 0;i < size_a;i++)
	{
		for (int n = 0;n < size_a;n++)
		{
			cout << tablica[i][n] << "     ";
		}
		cout << "\n";
	}
	int i = 2;
	int j = 4;
	int k = poloczenia[i][j];
	cout << "\n";
	if (poloczenia[i][j] != 0)
	{
		
		cout << k + 1 << "\n";
		while (poloczenia[i][k] != 0)
		{
			cout << k + 1 << "\n";
			k = poloczenia[i][k];
		}
	}
	


	for (int i = 0;i < size_a;i++)
	{
		delete[] poloczenia[i];
		delete[] tablica[i];
	}

	delete[] poloczenia;
	delete[]  tablica; // tu moze byc wyciek pamieci
	
}