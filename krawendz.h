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
	double dlugosc;

	Krawendz(Wezel a, Wezel b, int nr);
	~Krawendz();

private:

};

Krawendz::Krawendz(Wezel a, Wezel b, int nr)
{
	wezel_a = a.numer;
	wezel_b = b.numer;
	numer = nr;
	int pomocnicza;
	pomocnicza = (a.x - b.x) * (a.x - b.x)+(a.y - b.y)*(a.y - b.y);
	

	dlugosc = sqrt(pomocnicza);

}

Krawendz::~Krawendz()
{
}