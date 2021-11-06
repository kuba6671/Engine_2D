#include "Engine.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/WindowStyle.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>

Engine::Engine(int screenWidth, int screenHeight, std::string windowTitle) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->windowTitle = windowTitle;
	color = sf::Color::Black;
}
Engine::Engine(int screenWidth, int screenHeight) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	color = sf::Color::Black;
}
int Engine::init() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML");
	while (window.isOpen())
	{
		sf::Time time = clock.restart();
		float frameTime = time.asSeconds();
		sf::Event event;

		if (!square.loadFromFile("square.png"))
			return EXIT_FAILURE;
		sprite.setTexture(square);

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			/*if (sf::Event::KeyReleased) {
				clock.restart();
			}*/
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				sf::Vector2f pos = sprite.getPosition();
				if (pos.x < screenWidth - square.getSize().x) {
					sprite.move(1.f, 0.f);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				sf::Vector2f pos = sprite.getPosition();
				if (pos.y < screenHeight - square.getSize().y) {
					sprite.move(0.f, 1.f);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				sf::Vector2f pos = sprite.getPosition();
				// std::cout << "x=" << pos.x << " y=" << pos.y <<std::endl;
				if (pos.x > 0) {
					sprite.move(-1.f, 0.f);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				sf::Vector2f pos = sprite.getPosition();
				if (pos.y > 0) {
					sprite.move(0.f, -1.f);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
				paintScreen(sf::Color::Red);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
				paintScreen(sf::Color::Blue);
			}
			else if (mouse.isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i pos = mouse.getPosition(window);
				if ((pos.x > 0) && (pos.x < screenWidth - square.getSize().x) && (pos.y > 0) && (pos.y < screenHeight - square.getSize().y)) {
					sprite.setPosition(pos.x, pos.y);
				}
			}
		}
		//sf::Time elapsed = clock.getElapsedTime();
		window.clear(color);
		window.draw(sprite);
		window.display();
	}
	return 0;
}
void Engine::paintScreen(sf::Color color) {
	this->color = color;
}
