#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

class Drut
{
public:
	int numer;
	int pojemnosc;
	int koszt_jednostkowy;
	float oplacalnosc;
	float cena_za_wiazke;
	Drut(int nr, int pojemnosc, int koszt_jednostkowy)
	{
		nr = numer;
		this->pojemnosc = pojemnosc;
		this->koszt_jednostkowy = koszt_jednostkowy;
		oplacalnosc =  pojemnosc/koszt_jednostkowy;
		cena_za_wiazke = koszt_jednostkowy / pojemnosc;
	}

};