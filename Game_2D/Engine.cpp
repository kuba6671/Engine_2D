#include "Engine.h"
#include "PrimitiveRender.h"
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
	Point2D point1(100, 100);
	Point2D point2(110, 50);
	Point2D point3(150, 50);
	Point2D point4(250, 250);
	Point2D point5(300, 250);
	Point2D point6(200, 300);

	Point2D point7(190, 225);


	/*LineSegment line1(point1, point2);
	LineSegment line2(point3, point4);
	LineSegment line3(point5, point6);
	std::vector<LineSegment> lines;
	lines.push_back(line1);
	lines.push_back(line2);
	lines.push_back(line3);*/

	std::vector<Point2D> points;
	points.push_back(point1);
	points.push_back(point2);
	points.push_back(point3);
	points.push_back(point4);
	points.push_back(point5);
	points.push_back(point6);

	Circle c1(50, 100, 100);
	Circle c2 = *c1.clone();
	c2.draw(window);

	while (window.isOpen())
	{
		window.clear(color);
		sf::Time time = clock.restart();
		float frameTime = time.asSeconds();
		sf::Event event;
		//p1.drawCircle(window, 50, 100, 100, sf::Color::Blue);
		/*p1.drawRectangle(window, 50, 50, 300, 300);
		p1.drawTriangle(window, 50, 100, 300, sf::Color::Red);
		p1.drawPoint(window, 10, 15, sf::Color::Green);
		p1.drawLine(window, 100, 100, 200, 200, sf::Color::Red);
		p1.incrementalAlghorithm(window, 250, 250, 350, 350, sf::Color::Green);
		p1.drawPoint(window, point1, sf::Color::Yellow);
		p1.drawLine(window, line1);
		p1.drawPolyline(window,lines);*/
		//p1.drawCircleSym8(window, 200, 200, 50, sf::Color::Blue);
		//p1.drawEllipseSym4(window, 50,150,150,150, sf::Color::Red);

		//p1.boundryFill(window,point1,sf::Color::Blue, sf::Color::White);

		//p1.drawPoint(window,190,225);

		p1.drawPolygon(window, points);

		c1.draw(window);
		//c1.translate(window, -200, 200);
		c2.draw(window);
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
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
				//c1.translate(window, 50, 50);
				//c1.scale(window,3,3);
				c2.scale(window, 3, 3);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
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
