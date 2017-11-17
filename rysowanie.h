#pragma once
#include <iostream>
#include <Windows.h>
#include "graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

void rysuj_wezel(int x, int y)
{
	int gdriver = 0, gmode, errorcode;
	initgraph();
	setcolor(7);

	circle(x + 30, y + 30, 30); // jest x,y + 30 zeby nie wchodziło na tekst w konsoli
}

void rysuj_krawedz(int x1, int y1, int x2, int y2)
{
	int gdriver = 0, gmode, errorcode;
	initgraph();
	setcolor(7);

	line(x1 + 30, y1 +30, x2 + 30, y2 + 30);
}