#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>


using namespace std;

class Wezel
{
public:
	int x;
	int y;
	int obowiazkowy;
	int klijenci;
	double koszt; //do sciezki
	int numer;
	int wejscie; //int a nie bool by moc skorzystac zarowno w skierowanych jak i dijxtry;
	int wyjscie;
	//vector <int> poloczenia;
	//int tablica_poloczen[numer];
	vector < int > poloczenia;
	Wezel(int nr,int os_x,int os_y, int klijen);
	Wezel();
	~Wezel();
	
private:

};

Wezel::Wezel()
{

}

inline Wezel::Wezel(int nr, int os_x, int os_y, int klijen)
{
	x = os_x;
	y = os_y;
	numer = nr;
	koszt = 2147483647;
	wejscie=0;
	//obowiazkowy = obowiaz;
	klijenci = klijen;
}

Wezel::~Wezel()
{
}