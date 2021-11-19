#include "GameObject.h"

//Circle
Circle::Circle(int radius, int x, int y) {
	this->radius = radius;
	this->x = x;
	this->y = y;
}

void Circle::draw(sf::RenderWindow& window) {
	circle.setRadius(radius);
	circle.setPosition(sf::Vector2f(x, y));
	window.draw(circle);
}

void Circle::draw(sf::RenderWindow& window, sf::Color color) {
	circle.setRadius(radius);
	circle.setPosition(sf::Vector2f(x, y));
	circle.setFillColor(color);
	window.draw(circle);
}

void Circle::translate(sf::RenderWindow& window, int x, int y) {
	this->x += x;
	this->y += y;
}


void Circle::rotate(sf::RenderWindow& window, float angle) {
	circle.rotate(angle);
}

void Circle::scale(sf::RenderWindow& window, int x, int y) {
	circle.setScale(sf::Vector2f(x, y));
}

Circle* Circle::clone() const {
	return new Circle(*this);
}



//Rectangle
Rectangle::Rectangle(int sizeX, int sizeY, int x, int y) {
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->x = x;
	this->y = y;
}

void Rectangle::draw(sf::RenderWindow& window) {
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	window.draw(rectangle);
}

void Rectangle::draw(sf::RenderWindow& window, sf::Color color) {
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(color);
	window.draw(rectangle);
}

void Rectangle::translate(sf::RenderWindow& window, int x, int y) {
	this->x += x;
	this->y += y;
}

void Rectangle::rotate(sf::RenderWindow& window, float angle) {
	rectangle.rotate(angle);
}

void Rectangle::scale(sf::RenderWindow& window, int x, int y) {
	rectangle.setScale(sf::Vector2f(x, y));
}

Rectangle* Rectangle::clone() const {
	return new Rectangle(*this);
}


//Triangle
Triangle::Triangle(int size, int x, int y) {
	this->size = size;
	this->x = x;
	this->y = y;
}

void Triangle::draw(sf::RenderWindow& window) {
	triangle.setPointCount(3);
	triangle.setRadius(size);
	triangle.setPosition(sf::Vector2f(x, y));
	window.draw(triangle);
}

void Triangle::draw(sf::RenderWindow& window, sf::Color color) {
	triangle.setPointCount(3);
	triangle.setRadius(size);
	triangle.setPosition(sf::Vector2f(x, y));
	triangle.setFillColor(color);
	window.draw(triangle);
}

void Triangle::translate(sf::RenderWindow& window, int x, int y) {
	this->x += x;
	this->y += y;
}

void Triangle::rotate(sf::RenderWindow& window, float angle) {
	triangle.rotate(angle);
}

void Triangle::scale(sf::RenderWindow& window, int x, int y) {
	triangle.setScale(sf::Vector2f(x, y));
}

Triangle* Triangle::clone() const {
	return new Triangle(*this);
}


//Polyline
Polyline::Polyline(std::vector<LineSegment> lineVector) {
	this->lineVector = lineVector;
}

void Polyline::draw(sf::RenderWindow& window) {
	std::vector<LineSegment>::iterator it = lineVector.begin();
	for (LineSegment& x : lineVector) {
		primitive.drawLine(window,x);
	}
}

void Polyline::translate(sf::RenderWindow& window, int x, int y) {
	std::vector<LineSegment>::iterator it = lineVector.begin();
	for (LineSegment& i : lineVector) {
		i.changePoint1(i.getPoint1X() + x, i.getPoint1Y() + y);
		i.changePoint2(i.getPoint2X() + x, i.getPoint2Y() + y);
	}
}

void Polyline::rotate(sf::RenderWindow& window, float angle) {
	std::vector<LineSegment>::iterator it = lineVector.begin();
	float x2, y2;
	for (LineSegment& i : lineVector) {
		x2 = i.getPoint1X() * cos(angle) - i.getPoint1Y() * sin(angle);
		y2 = i.getPoint1X() * sin(angle) + i.getPoint1Y() * cos(angle);
		i.changePoint1((int)x2, (int)y2);

		x2 = i.getPoint2X() * cos(angle) - i.getPoint2Y() * sin(angle);
		y2 = i.getPoint2X() * sin(angle) + i.getPoint2Y() * cos(angle);
		i.changePoint2((int)x2, (int)y2);
	}
}


void Polyline::scale(sf::RenderWindow& window, int x, int y) {
	std::vector<LineSegment>::iterator it = lineVector.begin();
	float x2, y2;
	for (LineSegment& i : lineVector) {
		x2 = i.getPoint1X() * x;
		y2 = i.getPoint1Y() * y;
		i.changePoint1( (int)x2, (int)y2);

		x2 = i.getPoint2X() * x;
		y2 = i.getPoint2Y() * y;
		i.changePoint2( (int)x2, (int)y2);
	}
}

Polyline* Polyline::clone() const {
	return new Polyline(*this);
}

//Ellipse
Ellipse::Ellipse(int rx, int  ry, int positionX, int positionY, sf::Color color) {
	this->rx = rx;
	this->ry = ry;
	this->positionX = positionX;
	this->positionY = positionY;
	this->color = color;
}

void Ellipse::draw(sf::RenderWindow& window) {
	primitive.drawEllipseSym4(window, rx, ry, positionX, positionY, color);
}

void Ellipse::translate(sf::RenderWindow& window, int x, int y) {
	this->positionX += x;
	this->positionY += y;
}

void Ellipse::rotate(sf::RenderWindow& window, float angle) {
	float x2 = positionX * cos(angle) - positionY * sin(angle);
	float y2 = positionX * sin(angle) + positionY * cos(angle);
	this->positionX = (int)x2;
	this->positionY = (int)y2;
}

void Ellipse::scale(sf::RenderWindow& window, int x, int y) {
	float x2 = positionX * x;
	float y2 = positionY * y;

	this->positionX = (int)x2;
	this->positionY = (int)y2;
}

Ellipse* Ellipse::clone() const {
	return new Ellipse(*this);
}




//Polygon
Polygon::Polygon(std::vector<Point2D> P) {
	this->P = P;
}

void Polygon::draw(sf::RenderWindow& window) {

	primitive.drawPolygon(window, P);
}

void Polygon::translate(sf::RenderWindow& window, int x, int y) {
	int n = P.size();
	for (int i = 0; i < n; i++) {
		P[i].changeX(P[i].getX() + x);
		P[i].changeY(P[i].getY() + y);
	}
}

void Polygon::rotate(sf::RenderWindow& window, float angle) {
	int n = P.size();
	for (int i = 0; i < n; i++) {
		float x2 = P[i].getX() * cos(angle) - P[i].getY() * sin(angle);
		float y2 = P[i].getX() * sin(angle) + P[i].getY() * cos(angle);
		P[i].changeX(x2);
		P[i].changeY(y2);
	}
}

void Polygon::scale(sf::RenderWindow& window, int x, int y) {
	int n = P.size();
	for (int i = 0; i < n; i++) {
		float x2 = P[i].getX() * x;
		float y2 = P[i].getY() * y;
		P[i].changeX(x2);
		P[i].changeY(y2);
	}
}

Polygon* Polygon::clone() const {
	return new Polygon(*this);
}

// UpdatableBitmap
UpdatableBitmap::UpdatableBitmap(std::string bitmapPath) {
	if (!texture.loadFromFile(bitmapPath)) {
		throw EXIT_FAILURE;
	}
	sprite.setTexture(texture);
}

void UpdatableBitmap::update(sf::RenderWindow& window, sf::Texture texture) {
	sprite.setTexture(texture);
}

void UpdatableBitmap::setPosition(sf::RenderWindow& window, int x, int y) {
	sprite.setPosition(x, y);
}

void UpdatableBitmap::move(sf::RenderWindow window, int x, int y) {
	sprite.move(x, y);
}


//BitmpaObject
void BitmapObject::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

/*bool deleteSprite = false;

if (!deleteSprite) {
     window.draw(YOUR SPRITE);
}*/

void BitmapObject::deleteBitmap() {
	deleteSprite = true;
}

void BitmapObject::loadFromFile(std::string bitmapPath) {
	if (!texture.loadFromFile(bitmapPath)) {
		throw EXIT_FAILURE;
	}
	sprite.setTexture(texture);
	deleteSprite = false;
}

void BitmapObject::saveToFile(std::string fileName) {
	texture.copyToImage().saveToFile(fileName);
}

BitmapObject* BitmapObject::clone() const {
	return new BitmapObject(*this);
}

bool BitmapObject::getDeleteBitmap() {
	return deleteSprite;
}

void BitmapObject::setBitmapPosition(int x, int y) {
	sprite.setPosition(x,y);
}
