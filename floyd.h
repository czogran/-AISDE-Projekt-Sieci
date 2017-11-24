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
	tablica = new double *[size_a];
	for (int i = 0;i < size_a;i++)
	{
		tablica[i] = new double[size_a];
		for (int n = 0;n < size_a;n++)
		{
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
				if ((tablica[i][k] == INFINITY) || (tablica[k][j] == INFINITY)) continue;
				w = tablica[i][k] + tablica[k][j];
				if (tablica[i][j] > w)
				{
					tablica[i][j] = w;
					tablica[j][i] = w; //gdy jest nieskierowany
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





	for (int i = 0;i < size_a;i++)
	{
		delete[] tablica[i];
	}

	delete[]  tablica; // tu moze byc wyciek pamieci
	
}