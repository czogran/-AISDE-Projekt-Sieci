#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include"wezel.h"

using namespace std;

class Krawendz
{
public:
	int wezel_a;
	int wezel_b;
	int numer;
	bool uzyta;
	double dlugosc;
	int koszt_zakopania;

	//Krawendz(Wezel a, Wezel b, int nr);
	Krawendz(Wezel a, Wezel b, int nr, int koszty=0);
	~Krawendz();

private:

};

Krawendz::Krawendz(Wezel a, Wezel b, int nr, int koszty)
{
	koszt_zakopania = koszty;
	wezel_a = a.numer;
	wezel_b = b.numer;
	numer = nr;
	uzyta = false;
	int pomocnicza;
	
	pomocnicza = (a.x - b.x) * (a.x - b.x)+(a.y - b.y)*(a.y - b.y);
	

	dlugosc = sqrt(pomocnicza);

}

Krawendz::~Krawendz()
{
}