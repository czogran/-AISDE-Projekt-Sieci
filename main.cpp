#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include<SFML\Graphics.hpp>
#include<SFML\Window.hpp>
#include<cmath>


#include "wezel.h"
#include "krawendz.h"
#include "kruskal.h"
#include "dijkstra.h"
#include "graphics.h"
#include "rysowanie.h"
#include"GL\glew.h"
#include"GL\freeglut.h"
#include"GLFW\glfw3.h"
#include "floyd.h"
#include "sfml_rysowanie.h"
#include "steiner.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

using namespace std;












int main(int argc, char * argv[])
//adnotacja
{
	



	vector <Krawendz> krawendzie;
	vector<Wezel> wezly;

	

	int x, y, nr;
	int pozycja_w_pliku;
	int dlugos_lini;
	int obowiazkowe;
	//int ile_wezlow;
	//int ile_krawendzie;
	char znak; //by wiedziec czy wczytujemy do krawendzi, czy wezlow
	fstream plik;
	plik.open("dane2.txt", ios::in); //otwieramy plik w trybie tylko do odczytu - parametr "in"
	
	
	string linia;
	while (!plik.eof())
	{

		getline(plik, linia);
		cout << linia << "\n";
		if (linia[0] == '#')
		{
			//cout << "#\n";
		}
		else if (linia[0] == 'W'|| linia[0] == 'L')
		{
			znak = linia[0];
		
		}

		else if (linia[0]=='A')
		{
			if (linia[11] == 'M')
			{
				kruskal(krawendzie, wezly);
				break;
			}
			else if (linia[11]=='S')
			{ 
				getline(plik,linia);
				//pozycja_w_pliku = plik.tellp(); // dostajemy pozycje pliku
				//dlugos_lini = linia.size();     //jak d³uga jest linia
				//plik.seekp(pozycja_w_pliku - dlugos_lini - 2);//wraca by odczytac wartosc x, y nr do poprzedniego wiersza, 2 jest empiryczna
				plik >> x >> y;
				steiner(wezly, krawendzie, false);
				//dijkstra(wezly, krawendzie, x, y,false);
				break;
			}
			//cout << linia[11];
			else if (linia[11] == 'F')
			{
				getline(plik, linia);
				getline(plik, linia);
				getline(plik, linia);
				while (!plik.eof())
				{
					plik >> x >> y;
					floyd(wezly, krawendzie, x, y, false);
				}
				break;
			}
			//else if(linia)
		}
		else
		{
			pozycja_w_pliku = plik.tellp(); // dostajemy pozycje pliku
			dlugos_lini = linia.size();     //jak d³uga jest linia
			plik.seekp(pozycja_w_pliku - dlugos_lini - 2);//wraca by odczytac wartosc x, y nr do poprzedniego wiersza, 2 jest empiryczna
			 //wczytuje x y nr
			if (znak=='W')
			{
				plik >> nr >> x >> y >>obowiazkowe;
				wezly.push_back(Wezel(nr,x,y,obowiazkowe));
			}
			else
			{
				plik >> nr >> x >> y;
				krawendzie.push_back(Krawendz(wezly[x - 1], wezly[y - 1], nr));
			}
			//cout << nr << "   " << x << "  " << y << "\n";
			pozycja_w_pliku = plik.tellp();//znowu sprawdza pozycje
			plik.seekp(pozycja_w_pliku+2);// ustawia pozycje na poczotek nowego wiersza, by mozna bylo getlinem sprawdzic co tam jest
		}
	}
	

	plik.close(); //zamykamy plik
	

	

	for (int i = 0; i < wezly.size();i++)
	{
	
		//cout << wezly[i].numer;
		
	}

	//Sciezka sc(1);
	//sc = kruskal(krawendzie, wezly);
	//kruskal(krawendzie,wezly);
	//floyd(wezly, krawendzie,2,7);
	
	
	return 0;
}
