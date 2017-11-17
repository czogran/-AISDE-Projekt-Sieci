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
	int numer;
	//vector <int> poloczenia;
	vector < int > poloczenia;
	Wezel(int os_x,int os_y,int nr);
	Wezel();
	~Wezel();

private:

};

Wezel::Wezel()
{

}

inline Wezel::Wezel(int os_x, int os_y, int nr)
{
	x = os_x;
	y = os_y;
	numer = nr;
}

Wezel::~Wezel()
{
}