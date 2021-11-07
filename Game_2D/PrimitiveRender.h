#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>
class PrimitiveRender
{
public:
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2); //the default color is white
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
	void drawCircle(sf::RenderWindow& window, int size, int x, int y);
	void drawCircle(sf::RenderWindow& window, int size, int x, int y, sf::Color color);
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y);
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y, sf::Color color);
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y);
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, int x, int y);
	void drawPoint(sf::RenderWindow& window, int x, int y, sf::Color color);
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2);
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
};




