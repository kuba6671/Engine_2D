#include "GameObject.h"

//LineSegment
LineSegment::LineSegment() {
	point1.changeX(0);
	point1.changeY(0);
	point2.changeX(0);
	point2.changeY(0);
}
LineSegment::LineSegment(Point2D point1, Point2D point2) {
	this->point1.changeX(point1.getX());
	this->point1.changeY(point1.getY());
	this->point2.changeX(point2.getX());
	this->point2.changeY(point2.getY());
}
LineSegment::LineSegment(int x1, int y1, int x2, int y2) {
	this->point1.changeX(x1);
	this->point1.changeY(y1);
	this->point2.changeX(x2);
	this->point2.changeY(y2);
}
void LineSegment::changePoint1(Point2D point1) {
	this->point1.changeX(point1.getX());
	this->point1.changeY(point1.getY());
}
void LineSegment::changePoint2(Point2D point2) {
	this->point2.changeX(point2.getX());
	this->point2.changeY(point2.getY());
}
void LineSegment::changePoint1(int x1, int y1) {
	this->point1.changeX(x1);
	this->point1.changeY(y1);
}
void LineSegment::changePoint2(int x2, int y2) {
	this->point2.changeX(x2);
	this->point2.changeY(y2);
}
int LineSegment::getPoint1X() {
	return point1.getX();
}
int LineSegment::getPoint1Y() {
	return point1.getY();
}
int LineSegment::getPoint2X() {
	return point2.getX();
}
int LineSegment::getPoint2Y() {
	return point2.getY();
}

void LineSegment::draw(sf::RenderWindow& window) {
	primitive.drawLine(window, point1, point2);
}

void LineSegment::draw(sf::RenderWindow& window, sf::Color color) {
	primitive.drawLine(window, point1, point2, color);
}

void LineSegment::translate(sf::RenderWindow& window, int x, int y) {
	point1.changeX(point1.getX() + x);
	point1.changeY(point1.getY() - y);

	point2.changeX(point1.getX() + x);
	point2.changeY(point1.getY() - y);
}

void LineSegment::rotate(sf::RenderWindow& window, float angle) {
	float x2 = point1.getX() * cos(angle) - point1.getY() * sin(angle);
	float y2 = point1.getX() * sin(angle) + point1.getY() * cos(angle);
	point1.changeX((int)x2);
	point1.changeY((int)y2);

	x2 = point2.getX() * cos(angle) - point2.getY() * sin(angle);
	y2 = point2.getX() * sin(angle) + point2.getY() * cos(angle);
	point2.changeX((int)x2);
	point2.changeY((int)y2);
}

void LineSegment::scale(sf::RenderWindow& window, float x, float y) {
	float x2 = point1.getX() * x;
	float y2 = point1.getY() * y;

	point1.changeX((int)x2);
	point1.changeY((int)y2);

	x2 = point2.getX() * x;
	y2 = point2.getY() * y;

	point2.changeX((int)x2);
	point2.changeY((int)y2);
}

LineSegment* LineSegment::clone() const {
	return new LineSegment(*this);
}
