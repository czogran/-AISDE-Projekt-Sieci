#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <math.h>
#include"wezel.h"
#include "krawendz.h"


class Sciezka
{
public:
	vector <Krawendz> krawendzie;
	vector <Wezel> wezly;
	int a;
	Sciezka(int b);
	Sciezka();
	~Sciezka();
};

Sciezka::Sciezka(int b)
{
	a = b;
}
Sciezka::~Sciezka()
{

}