#include "Engine.h"
#include "GameObject.h"

Engine::Engine(int screenWidth, int screenHeight, std::string windowTitle) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->windowTitle = windowTitle;
	color = sf::Color(150, 150, 150);
}
Engine::Engine(int screenWidth, int screenHeight) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	color = sf::Color(150, 150, 150);
}
int Engine::init() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "SFML");
	PrimitiveRender p1;
	sf::Event event;

	sf::Texture playerTexture;
	playerTexture.loadFromFile("dragon.png");

	Player player(&playerTexture, sf::Vector2u(3,4), 0.1f, 100.0f);

	float deltaTime = 0.0f;

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//if (mouse.isButtonPressed(sf::Mouse::Left)) {
			//	sf::Vector2i pos = mouse.getPosition(window);
			//	p1.boundryFill(window,pos.x,pos.y,sf::Color::Red,sf::Color::Blue);
			//}
			/*if (!bitmap1.getBitmapState()) {
				bitmap1.draw(window);
			}*/
			//animation.addFrame({ sf::IntRect(0,0,100,100), 0.1 });
			//window.draw(myCharacter);
			//window.draw(myCharacter);
			/*if (sf::Event::KeyReleased) {
				clock.restart();
			}*/
			/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
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
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
				//animation.update(elapsed.asMicroseconds());
			}*/
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
		}
		player.update(deltaTime);
		window.clear(color);
		player.draw(window);
		window.display();
	}
	return 0;
}
void Engine::paintScreen(sf::Color color) {
	this->color = color;
}
