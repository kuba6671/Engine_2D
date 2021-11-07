#include "Engine.h"
#include "PrimitiveRender.h"

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
	PrimitiveRender p1;
	while (window.isOpen())
	{
		window.clear(color);
		sf::Time time = clock.restart();
		float frameTime = time.asSeconds();
		sf::Event event;
		p1.drawCircle(window, 50, 100, 100, sf::Color::Blue);
		p1.drawRectangle(window, 50, 50, 300, 300);
		p1.drawTriangle(window, 50, 100, 300, sf::Color::Red);
		p1.drawPoint(window, 10, 15, sf::Color::Green);
		p1.drawLine(window, 100, 100, 200, 200, sf::Color::Red);
		p1.incrementalAlghorithm(window, 250, 250, 350, 350, sf::Color::Green);

		if (!square.loadFromFile("square.png")) {
			throw EXIT_FAILURE;
			//return EXIT_FAILURE;
		}
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
		window.draw(sprite);
		window.display();
	}
	return 0;
}
void Engine::paintScreen(sf::Color color) {
	this->color = color;
}
