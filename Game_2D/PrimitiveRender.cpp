#include "PrimitiveRender.h"
#include <iostream>


void PrimitiveRender::drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2) {
	sf::Vertex line2[] = {
		sf::Vertex(sf::Vector2f(x1,y1)),
		sf::Vertex(sf::Vector2f(x2,y2))
	};
	line2->color = sf::Color::White;
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
void PrimitiveRender::drawLine(sf::RenderWindow& window, LineSegment line) {
	sf::Vertex line2[] = {
	sf::Vertex(sf::Vector2f(line.getPoint1X(),line.getPoint1Y())),
	sf::Vertex(sf::Vector2f(line.getPoint2X(),line.getPoint2Y()))
	};
	line2->color = sf::Color::White;
	window.draw(line2, 10, sf::Lines);
}
void PrimitiveRender::drawLine(sf::RenderWindow& window, LineSegment line, sf::Color color) {
	sf::Vertex line2[] = {
	sf::Vertex(sf::Vector2f(line.getPoint1X(),line.getPoint1Y())),
	sf::Vertex(sf::Vector2f(line.getPoint2X(),line.getPoint2Y()))
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
void PrimitiveRender::drawCircleSym8(sf::RenderWindow& window, float xCenter, float yCenter, float radius, sf::Color color) {
	float x, y, r2;
	r2 = radius * radius;
	drawPoint(window, xCenter, yCenter + radius, color);
	drawPoint(window, xCenter, yCenter - radius, color);
	drawPoint(window, xCenter + radius, yCenter, color);
	drawPoint(window, xCenter - radius, yCenter, color);
	y = radius;
	x = 1;
	y = sqrt(r2 - 1) + 0.5;
	while (x < y) {
		drawPoint(window, float(xCenter + x), float(yCenter + y), color);
		drawPoint(window, float(xCenter + x), float(yCenter - y), color);
		drawPoint(window, float(xCenter - x), float(yCenter + y), color);
		drawPoint(window, float(xCenter - x), float(yCenter - y), color);
		drawPoint(window, float(xCenter + y), float(yCenter + x), color);
		drawPoint(window, float(xCenter + y), float(yCenter - x), color);
		drawPoint(window, float(xCenter - y), float(yCenter + x), color);
		drawPoint(window, float(xCenter - y), float(yCenter - x), color);
		x += 1;
		y = sqrt(r2 - x * x) + 0.5;
	}
	if (x == y) {
		drawPoint(window, float(xCenter + x), float(yCenter + y), color);
		drawPoint(window, float(xCenter + x), float(yCenter - y), color);
		drawPoint(window, float(xCenter - x), float(yCenter + y), color);
		drawPoint(window, float(xCenter - x), float(yCenter - y), color);

	}

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
void PrimitiveRender::drawPoint(sf::RenderWindow& window, float x, float y, sf::Color color) {
	sf::Vertex point(sf::Vector2f(x, y), color);
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, int x, int y, sf::Color color) {
	sf::Vertex point(sf::Vector2f(x, y), color);
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, Point2D point2D) {
	sf::Vertex point(sf::Vector2f(point2D.getX(), point2D.getY()));
	window.draw(&point, 1, sf::Points);
}
void PrimitiveRender::drawPoint(sf::RenderWindow& window, Point2D point2D, sf::Color color) {
	sf::Vertex point(sf::Vector2f(point2D.getX(), point2D.getY()), color);
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
void PrimitiveRender::drawPolyline(sf::RenderWindow& window, std::vector<LineSegment> lineVector) {
	std::vector<LineSegment>::iterator it = lineVector.begin();

	for (LineSegment& x : lineVector) {
		drawLine(window, x);
	}
}

void PrimitiveRender::drawEllipseSym4(sf::RenderWindow& window, int rx, int ry, int positionX, int positionY, sf::Color color) {
	float dx, dy, d1, d2, x, y;
	x = 0;
	y = ry;

	d1 = (ry * ry) - (rx * rx * ry) +
		(0.25 * rx * rx);
	dx = 2 * ry * ry * x;
	dy = 2 * rx * rx * y;

	while (dx < dy)
	{
		drawPoint(window, x + positionX, y + positionY, color);
		drawPoint(window, -x + positionX, y + positionY, color);
		drawPoint(window, x + positionX, -y + positionY, color);
		drawPoint(window, -x + positionX, -y + positionY, color);

		if (d1 < 0)
		{
			x++;
			dx = dx + (2 * ry * ry);
			d1 = d1 + dx + (ry * ry);
		}
		else
		{
			x++;
			y--;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d1 = d1 + dx - dy + (ry * ry);
		}
	}

	d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) +
		((rx * rx) * ((y - 1) * (y - 1))) -
		(rx * rx * ry * ry);

	while (y >= 0)
	{
		drawPoint(window, x + positionX, y + positionY, color);
		drawPoint(window, -x + positionX, y + positionY, color);
		drawPoint(window, x + positionX, -y + positionY, color);
		drawPoint(window, -x + positionX, -y + positionY, color);

		if (d2 > 0)
		{
			y--;
			dy = dy - (2 * rx * rx);
			d2 = d2 + (rx * rx) - dy;
		}
		else
		{
			y--;
			x++;
			dx = dx + (2 * ry * ry);
			dy = dy - (2 * rx * rx);
			d2 = d2 + dx - dy + (rx * rx);
		}
	}

}

double PrimitiveRender::cross(Point2D O, Point2D A, Point2D B) {
	return (A.getX() - O.getX()) * (B.getY() - O.getY()) - (A.getY() - O.getY()) * (B.getX() - O.getX());
}


void PrimitiveRender::drawPolygon(sf::RenderWindow& window, std::vector<Point2D> P) {
	int n = P.size(), k = 0;
	if (n <= 3) {
		return;
	}
	std::vector<Point2D> H(n);

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k - 2], H[k - 1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	for (int i = n - 1, t = k + 1; i > 0; --i) {
		while (k >= t && cross(H[k - 2], H[k - 1], P[i - 1]) <= 0) k--;
		H[k++] = P[i - 1];
	}

	for (int i = 1; i < H.size(); i++) {
		drawLine(window, H[i - 1].getX(), H[i - 1].getY(), H[i].getX(), H[i].getY());
	}
}

void PrimitiveRender::boundryFill(sf::RenderWindow& window, int x, int y, sf::Color fill_color, sf::Color boundry_color) {
	sf::Vector2u windowSize = window.getSize();
	sf::Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(window);
	sf::Image image = texture.copyToImage();

	if ((image.getPixel(x, y) != boundry_color) && (image.getPixel(x, y) == fill_color)) {
		drawPoint(window, x, y, fill_color);
		boundryFill(window, x + 1, y, fill_color, boundry_color);
		boundryFill(window, x, y + 1, fill_color, boundry_color);
		boundryFill(window, x - 1, y, fill_color, boundry_color);
		boundryFill(window, x, y - 1, fill_color, boundry_color);
	}
}

void PrimitiveRender::floodFill(sf::RenderWindow& window, int x, int y, sf::Color fill_color, sf::Color background) {
	sf::Vector2u windowSize = window.getSize();
	sf::Texture texture;
	texture.create(windowSize.x, windowSize.y);
	texture.update(window);
	sf::Image image = texture.copyToImage();

	if ((image.getPixel(x, y) == background) && (image.getPixel(x, y) == fill_color)) {
		drawPoint(window, x, y, fill_color);
		boundryFill(window, x + 1, y, fill_color, background);
		boundryFill(window, x, y + 1, fill_color, background);
		boundryFill(window, x - 1, y, fill_color, background);
		boundryFill(window, x, y - 1, fill_color, background);
	}
}


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

