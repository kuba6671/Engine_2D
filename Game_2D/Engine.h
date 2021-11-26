#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/WindowStyle.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
#include <cmath>
#include "GameObject.h"

class Engine
{
private:
	/**
	 * \param screenWidth - szerokosc ekranu
	 * \param screenHeight - wysokosc ekranu
	 * \param windowTitle - nazwa okna
	 * \param clock - zegar
	 * \param keyboard - klawiatura
	 * \param mouse - myszka
	 * \param color - kolor tla
	 */
	int screenWidth = 0;
	int screenHeight = 0;
	std::string windowTitle;
	sf::Clock clock;
	sf::Keyboard keyboard;
	sf::Mouse mouse;
	sf::Color color;
	/**
	 * Metoda sluzaca do zmiany koloru ekranu
	 * \param color
	 */
	void paintScreen(sf::Color color);
public:
	Engine(int screenWidth, int screenHeight, std::string windowTitle);
	Engine(int screenWidth, int screenHeight);
	/**
	 * Metoda inicjujaca glowna petle gry
	 * \return 
	 */
	int init();
	//~Engine();
};

