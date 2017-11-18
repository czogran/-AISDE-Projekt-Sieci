#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include "wezel.h"
#include "krawendz.h"
#include "kruskal.h"
#include "dijkstra.h"

using namespace std;
int main()
//adnotacja
{
	
	vector <Krawendz> krawendzie;
	vector<Wezel> wezly;

	int x, y, nr;
	int pozycja_w_pliku;
	int dlugos_lini;
	//int ile_wezlow;
	//int ile_krawendzie;
	char znak; //by wiedziec czy wczytujemy do krawendzi, czy wezlow
	fstream plik;
	plik.open("dane1.txt", ios::in); //otwieramy plik w trybie tylko do odczytu - parametr "in"
	cout << "test\n";
	
	string linia;
	while (!plik.eof())
	{

		getline(plik, linia);
		cout << linia << "\n";
		if (linia[0] == '#')
		{
			cout << "#\n";
		}
		else if (linia[0] == 'W'|| linia[0] == 'L')//||linia[0]=='A')
		{
			
			znak = linia[0];
			cout << "\nznalzlem";// << ile_wezlow << "aa\n";
			cout << "\n";
		}

		else if (linia[0] == 'A')
		{
			break;
		}
		else
		{
			pozycja_w_pliku = plik.tellp(); // dostajemy pozycje pliku
			dlugos_lini = linia.size();     //jak d³uga jest linia
			plik.seekp(pozycja_w_pliku - dlugos_lini - 2);//wraca by odczytac wartosc x, y nr do poprzedniego wiersza, 2 jest empiryczna
			plik >> nr >> x >> y; //wczytuje x y nr
			if (znak=='W')
			{
				wezly.push_back(Wezel(nr,x,y));
			}
			else
			{
				krawendzie.push_back(Krawendz(wezly[x - 1], wezly[y - 1], nr));
			}
			//cout << nr << "   " << x << "  " << y << "\n";
			pozycja_w_pliku = plik.tellp();//znowu sprawdza pozycje
			plik.seekp(pozycja_w_pliku+2);// ustawia pozycje na poczotek nowego wiersza, by mozna bylo getlinem sprawdzic co tam jest
		}
	}
	

	plik.close(); //zamykamy plik

	
	cout << "\n"<<"\n"<<"\n";
	//cout << "\n" << wezly.size();
	for (int n = 0;n < 5;n++)
	{
		cout << "\n" << krawendzie[n].dlugosc;
	}
	cout << "\n";
	kruskal(krawendzie, wezly);
	//cout << "\ndixtry wiercholek 3 z 5\n";
	dijkstra(wezly, krawendzie, 2, 5);
	for (int n = 1;n < 4;n++)
	{
		//cout << "sss";
		//cout << wezly[1].poloczenia[n] << "\n";
	}
	
	
	return 0;
}
