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
	Drut(int nr, int pojemnosc, int koszt_jednostkowy)
	{
		nr = numer;
		this->pojemnosc = pojemnosc;
		this->koszt_jednostkowy = koszt_jednostkowy;
		oplacalnosc = pojemnosc / koszt_jednostkowy;
	}

};