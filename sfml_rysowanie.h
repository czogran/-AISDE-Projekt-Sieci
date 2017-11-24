#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <string>
#include <sstream>		
#include <Windows.h>
#include "wezel.h"
#include "krawendz.h"
#include "sciezka.h"
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


using namespace std;



int rysuj_graf(vector <Wezel> wezly, vector <Krawendz> krawedzie)
{
	sf::RenderWindow okno(sf::VideoMode(700, 500, 32), "Network Optimizer");
	sf::Font font;
	font.loadFromFile("arial.ttf");
	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();

		}
		okno.clear();

		for (int i = 0; i < krawedzie.size(); i++)
		{
			sf::Vertex vertex1(sf::Vector2f(wezly[krawedzie[i].wezel_a - 1].x * 5, wezly[krawedzie[i].wezel_a - 1].y *5));
			sf::Vertex vertex2(sf::Vector2f(wezly[krawedzie[i].wezel_b - 1].x *5, wezly[krawedzie[i].wezel_b - 1].y *5));
			sf::Vertex line[2] = { vertex1, vertex2 };
			okno.draw(line, 2, sf::Lines);
			
		}

		for (int i = 0; i < wezly.size(); i++)
		{
			int numer = wezly[i].numer;
			sf::Text mytext;
			mytext.setFont(font);
			std::stringstream ss;
			ss << numer;
			mytext.setString(ss.str().c_str());
			mytext.setPosition(wezly[i].x * 5, wezly[i].y * 5);
			mytext.setScale(0.5, 0.5);

			
			
			sf::CircleShape circle(5);
			circle.setFillColor(sf::Color::Blue);
			circle.setOutlineColor(sf::Color::Magenta);
			circle.setOutlineThickness(1);
			circle.setPosition(wezly[i].x * 5 - 2.5, wezly[i].y * 5 -2.5);
		
			okno.draw(circle);
			okno.draw(mytext);
		}
		okno.display();
	}
	
	return 0;
}

int rysuj_graf_sciezka(vector <Wezel> wezly, vector <Krawendz> krawedzie, Sciezka sciezka)
{
	sf::RenderWindow okno(sf::VideoMode(700, 500, 32), "Network Optimizer");
	sf::Font font;
	font.loadFromFile("arial.ttf");
	while (okno.isOpen())
	{
		sf::Event event;
		while (okno.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				okno.close();

		}
		okno.clear();

		for (int i = 0; i < krawedzie.size(); i++)
		{
			sf::Vertex vertex1(sf::Vector2f(wezly[krawedzie[i].wezel_a - 1].x * 5, wezly[krawedzie[i].wezel_a - 1].y * 5));
			sf::Vertex vertex2(sf::Vector2f(wezly[krawedzie[i].wezel_b - 1].x * 5, wezly[krawedzie[i].wezel_b - 1].y * 5));
			sf::Vertex line[2] = { vertex1, vertex2 };
			
			
			okno.draw(line, 2, sf::Lines);

		}
		

		for (int i = 0; i < sciezka.wezly.size() - 1; i++)
		{
			sf::Vertex vertex1(sf::Vector2f(sciezka.wezly[i].x * 5,sciezka.wezly[i].y * 5),sf::Color::Red);
			sf::Vertex vertex2(sf::Vector2f(sciezka.wezly[i+1].x * 5, sciezka.wezly[i+1].y * 5), sf::Color::Red);
			sf::Vertex line[2] = { vertex1, vertex2 };
		
			
			okno.draw(line, 2, sf::Lines);
		}

		for (int i = 0; i < wezly.size(); i++)
		{
			int numer = wezly[i].numer;
			sf::Text mytext;
			mytext.setFont(font);
			std::stringstream ss;
			ss << numer;
			mytext.setString(ss.str().c_str());
			mytext.setPosition(wezly[i].x * 5, wezly[i].y * 5);
			mytext.setScale(0.5, 0.5);



			sf::CircleShape circle(5);
			circle.setFillColor(sf::Color::Blue);
			circle.setOutlineColor(sf::Color::Magenta);
			circle.setOutlineThickness(1);
			circle.setPosition(wezly[i].x * 5 - 2.5, wezly[i].y * 5 - 2.5);

			okno.draw(circle);
			okno.draw(mytext);
		}
		okno.display();
	}

	return 0;
}


