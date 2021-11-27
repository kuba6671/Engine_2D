#include "GameObject.h"

//Point2D
Point2D::Point2D(int x, int y) {
	this->x = x;
	this->y = y;
}
Point2D::Point2D() {
	x = y = 0;
}
int Point2D::getX() {
	return this->x;
}
int Point2D::getY() {
	return this->y;
}
void Point2D::changeX(int x) {
	this->x = x;
}
void Point2D::changeY(int y) {
	this->y = y;
}

void Point2D::draw(sf::RenderWindow& window) {
	primitive.drawPoint(window, x, y);
}

void Point2D::draw(sf::RenderWindow& window, sf::Color color) {
	primitive.drawPoint(window, x, y, color);
}

void Point2D::translate(sf::RenderWindow& window, int x, int y) {
	this->x += x;
	this->y += y;
}

void Point2D::rotate(sf::RenderWindow& window, float angle) {
	float x2 = x * cos(angle) - y * sin(angle);
	float y2 = x * sin(angle) + y * cos(angle);
	this->x = (int)x2;
	this->y = (int)y2;
}

void Point2D::scale(sf::RenderWindow& window, float x, float y) {
	float x2 = this->x * x;
	float y2 = this->y * y;

	this->x = (int)x2;
	this->y = (int)y2;
}

Point2D* Point2D::clone() const {
	return new Point2D(*this);
}
