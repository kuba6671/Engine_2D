#include "PrimitiveRender.h"


void PrimitiveRender::drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2) {
	sf::Vertex line2[] = {
		sf::Vertex(sf::Vector2f(x1,y1)),
		sf::Vertex(sf::Vector2f(x2,y2))
	};
	line2->color = sf::Color::Blue;
	window.draw(line2, 10, sf::Lines);
}
void PrimitiveRender::drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color) {
	sf::Vertex line2[] = {
		sf::Vertex(sf::Vector2f(x1,y1)),
		sf::Vertex(sf::Vector2f(x2,y2))
	};
	line2->color = color;
	window.draw(line2, 10, sf::Lines);
}
void PrimitiveRender::drawCircle(sf::RenderWindow& window, int size, int x, int y) {
	sf::CircleShape circle(size);
	circle.setPosition(sf::Vector2f(x, y));
	window.draw(circle);
}
void PrimitiveRender::drawCircle(sf::RenderWindow& window, int size, int x, int y, sf::Color color) {
	sf::CircleShape circle(size);
	circle.setPosition(sf::Vector2f(x, y));
	circle.setFillColor(color);
	window.draw(circle);
}
void PrimitiveRender::drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y) {
	sf::RectangleShape rectangle(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	window.draw(rectangle);
}
void PrimitiveRender::drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y, sf::Color color) {
	sf::RectangleShape rectangle(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(color);
	window.draw(rectangle);
}
void PrimitiveRender::drawTriangle(sf::RenderWindow& window, int size, int x, int y) {
	sf::CircleShape triangle(size, 3);
	triangle.setPosition(sf::Vector2f(x, y));
	window.draw(triangle);
}
void PrimitiveRender::drawTriangle(sf::RenderWindow& window, int size, int x, int y, sf::Color color) {
	sf::CircleShape triangle(size, 3);
	triangle.setPosition(sf::Vector2f(x, y));
	triangle.setFillColor(color);
	window.draw(triangle);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, int x, int y) {
	sf::Vertex point(sf::Vector2f(x, y));
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, int x, int y, sf::Color color) {
	sf::Vertex point(sf::Vector2f(x, y), color);
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2) {
	int x;
	float dy = y2 - y1;
	float dx = x2 - x1;
	float m = dy / dx;
	float y = y1;
	if ((m > -1) || (m < 1)) {
		for (x = x1; x <= x2; x++) {
			drawPoint(window, x, floor(0.5 + y));
			y += m;
		}
	}
	else {
		for (x = y1; x <= y2; x++) {
			drawPoint(window, x, floor(0.5 + y));
			x += 1 / m;
		}
	}
}
void PrimitiveRender::incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color) {
	int x;
	float dy = y2 - y1;
	float dx = x2 - x1;
	float m = dy / dx;
	float y = y1;
	if ((m > -1) || (m < 1)) {
		for (x = x1; x <= x2; x++) {
			drawPoint(window, x, floor(0.5 + y), color);
			y += m;
		}
	}
	else {
		for (x = y1; x <= y2; x++) {
			drawPoint(window, x, floor(0.5 + y), color);
			x += 1 / m;
		}
	}
}

