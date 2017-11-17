#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include "wezel.h"
#include "krawendz.h"
#include "rysowanie.h"

using namespace std;
int main()

{
	
	int x, y, nr;
	fstream plik;
	plik.open("dane.txt", ios::in); //otwieramy plik w trybie tylko do odczytu - parametr "r"

	char znak;
	string linia;
	do
	{
		
		getline(plik, linia);
		//if (znak == '#')
		if(linia[0]=='#')
		{
			cout << "#";
		}
		else if (linia[0]=='W'||linia[0]=='L')
		{
			cout << "\nznalzlem";
		}
		else
		{
			//x = linia;
			
			//cout << linia;
			//cout << "\n";
		}
		//getline(plik, linia);
		 //linia.begin();

		
		//zapisujê jeden znak z pliku
		//cout << linia << endl; //wypsiujê na ekran
	} while (!plik.eof()); //End Of File - koniec pliku

	plik.close(); //zamykamy plik

	Wezel a(5, 4, 1);
	Wezel b(1, 1, 2);
	Krawendz c(a, b, 3);

	//rysuj_krawedz(a.x, a.y, b.x, b.y);
	//rysuj_wezel(a.x, a.y);					//Tak mozna uzywac funkcji rysowania
	//rysuj_wezel(b.x, b.y);
	
	return 0;
}
