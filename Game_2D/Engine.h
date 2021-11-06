#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/WindowStyle.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
class Engine
{
public:
	int screenWidth = 0, screenHeight = 0;
	std::string windowTitle;
	sf::Clock clock;
	sf::Keyboard keyboard;
	sf::Texture square;
	sf::Sprite sprite;
	sf::Color color;
	sf::Mouse mouse;
public:
	Engine(int screenWidth, int screenHeight, std::string windowTitle);
	Engine(int screenWidth, int screenHeight);
	int init();
	void paintScreen(sf::Color color);

};

