#include <iostream>
#include "wezel.h"
using namespace std;
int main()
//adnotacja 2
{
	int x, y, nr;
	int pozycja_w_pliku;
	int dlugos_lini;
	fstream plik;
	plik.open("dane.txt", ios::in); //otwieramy plik w trybie tylko do odczytu - parametr "r"

	char znak;
	string linia;
	//do
	while (!plik.eof())
	{

		getline(plik, linia);
		//if (znak == '#')
		if (linia[0] == '#')
		{
			cout << "#\n";
		}
		else if (linia[0] == 'W' || linia[0] == 'L' || linia[0] == 'A')
		{
			cout << "\nznalzlem";
			cout << "\n";
		}
		else
		{
			pozycja_w_pliku = plik.tellp(); // dostajemy pozycje pliku
			dlugos_lini = linia.size();     //jak d³uga jest linia
			plik.seekp(pozycja_w_pliku - dlugos_lini - 2);//wraca by odczytac wartosc x, y nr do poprzedniego wiersza, 2 jest empiryczna
			plik >> nr >> x >> y; //wczytuje x y nr
			cout << nr << "   " << x << "  " << y << "\n";
			pozycja_w_pliku = plik.tellp();//znowu sprawdza pozycje
			plik.seekp(pozycja_w_pliku + 2);// ustawia pozycje na poczotek nowego wiersza, by mozna bylo getlinem sprawdzic co tam jest
		}
	}


	plik.close(); //zamykamy plik
	return 0;
}