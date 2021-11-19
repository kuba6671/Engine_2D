#include "Engine.h"
#include "GameObject.h"

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
	BitmapObject bitmap1("square.png",300,300);

	while (window.isOpen())
	{
		window.clear(color);
		sf::Time time = clock.restart();
		float frameTime = time.asSeconds();
		sf::Event event;


		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (!bitmap1.getDeleteBitmap()) {
				bitmap1.draw(window);
			}
			if (sf::Event::KeyReleased) {
				clock.restart();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				bitmap1.saveToFile("zapisane.png");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
				bitmap1.loadFromFile("rectangle.png");
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				bitmap1.deleteBitmap();
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
				bitmap1.setBitmapPosition(500,500);
			}
			/*else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
				sf::Vector2f pos = sprite.getPosition();
				if (pos.y < screenHeight - square.getSize().y) {
					sprite.move(0.f, 1.f);
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
				sf::Vector2f pos = sprite.getPosition();
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
		}*/
		//sf::Time elapsed = clock.getElapsedTime();
			window.display();
		}
	}
	return 0;
}
void Engine::paintScreen(sf::Color color) {
	this->color = color;
}
