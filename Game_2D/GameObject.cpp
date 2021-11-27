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

void Circle::scale(sf::RenderWindow& window, float x, float y) {
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
	//angle = 0.0;
	rectangle.setRotation(angle);
}

void Rectangle::draw(sf::RenderWindow& window) {
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setRotation(angle);
	window.draw(rectangle);
}

void Rectangle::draw(sf::RenderWindow& window, sf::Color color) {
	rectangle.setSize(sf::Vector2f(sizeX, sizeY));
	rectangle.setPosition(sf::Vector2f(x, y));
	rectangle.setFillColor(color);
	rectangle.setRotation(angle);
	window.draw(rectangle);
}

void Rectangle::translate(sf::RenderWindow& window, int x, int y) {
	this->x += x;
	this->y += y;
}

void Rectangle::rotate(sf::RenderWindow& window, float angle) {
	this->angle += angle;
	//std::cout << "angle=" << this->angle << std::endl;
	//rectangle.rotate(angle);
}

void Rectangle::scale(sf::RenderWindow& window, float x, float y) {
	rectangle.setScale(sf::Vector2f(x, y));
}

void Rectangle::setColor(sf::Color color)
{
	rectangle.setFillColor(color);
}

sf::FloatRect Rectangle::getGlobalBounds()
{
	return rectangle.getGlobalBounds();
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

void Triangle::scale(sf::RenderWindow& window, float x, float y) {
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
		primitive.drawLine(window, x);
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


void Polyline::scale(sf::RenderWindow& window, float x, float y) {
	std::vector<LineSegment>::iterator it = lineVector.begin();
	float x2, y2;
	for (LineSegment& i : lineVector) {
		x2 = i.getPoint1X() * x;
		y2 = i.getPoint1Y() * y;
		i.changePoint1((int)x2, (int)y2);

		x2 = i.getPoint2X() * x;
		y2 = i.getPoint2Y() * y;
		i.changePoint2((int)x2, (int)y2);
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

void Ellipse::scale(sf::RenderWindow& window, float x, float y) {
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

void Polygon::scale(sf::RenderWindow& window, float x, float y) {
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
	if (!textureBitmap.loadFromFile(bitmapPath)) {
		throw EXIT_FAILURE;
	}
	sprite.setTexture(textureBitmap);
}

void UpdatableBitmap::update(sf::RenderWindow& window, sf::Texture textureBitmap) {
	sprite.setTexture(textureBitmap);
}

void UpdatableBitmap::setPosition(sf::RenderWindow& window, int x, int y) {
	sprite.setPosition(x, y);
}

void UpdatableBitmap::move(sf::RenderWindow window, int x, int y) {
	sprite.move(x, y);
}

//BitmpaObject
BitmapObject::BitmapObject(std::string bitmapPath)
{
	if (!textureBitmap.loadFromFile(bitmapPath)) {
		throw EXIT_FAILURE;
	}
	sprite.setTexture(textureBitmap);
	deleteSprite = false;
}

BitmapObject::BitmapObject(std::string bitmapPath, int x, int y)
{
	if (!textureBitmap.loadFromFile(bitmapPath)) {
		throw EXIT_FAILURE;
	}
	sprite.setTexture(textureBitmap);
	setBitmapPosition(x, y);
	deleteSprite = false;
}

BitmapObject::BitmapObject(sf::Image image)
{
	this->image = image;
}

void BitmapObject::draw(sf::RenderWindow& window) {
	if (!deleteSprite)
		window.draw(sprite);
}

void BitmapObject::deleteBitmap() {
	deleteSprite = true;
}

void BitmapObject::loadFromFile(std::string bitmapPath) {
	if (!textureBitmap.loadFromFile(bitmapPath)) {
		throw EXIT_FAILURE;
	}
	sprite.setTexture(textureBitmap);
	deleteSprite = false;
}

void BitmapObject::saveToFile(std::string fileName) {
	textureBitmap.copyToImage().saveToFile(fileName);
}

void BitmapObject::saveImagetoFile(std::string fileName)
{
	image.saveToFile(fileName);
}

BitmapObject* BitmapObject::clone() const {
	return new BitmapObject(*this);
}

bool BitmapObject::getBitmapState() {
	return deleteSprite;
}

void BitmapObject::setBitmapPosition(int x, int y) {
	sprite.setPosition(x, y);
}

sf::Sprite BitmapObject::getSprite() {
	return sprite;
}

SpriteObject::SpriteObject(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;
	currentImage.x = 0;

	uvRect.width = texture->getSize().x / float(imageCount.x);
	uvRect.height = texture->getSize().y / float(imageCount.y);
}

void SpriteObject::animate(int row, float deltaTime, bool faceRight)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x) {
			currentImage.x = 0;
		}
	}


	uvRect.top = currentImage.y * uvRect.height;

	if (faceRight) {
		uvRect.left = currentImage.x * uvRect.width;
		uvRect.width = abs(uvRect.width);
	}
	else {
		uvRect.left = (currentImage.x + 1) * abs(uvRect.width);
		uvRect.width = -abs(uvRect.width);
	}
}

SpriteObject* SpriteObject::clone() const
{
	return new SpriteObject(*this);
}

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed)
	: anim(texture, imageCount, switchTime)
{
	this->speed = speed;
	row = 0;
	faceRight = true;
	bool upDown = true;
	body.setSize(sf::Vector2f(100.0f, 150.0f));
	body.setPosition(100.0f, 500.0f);
	body.setTexture(texture);
}

void Player::update(float deltaTime, int screenWidth, int screenHeight)
{
	sf::Vector2f movement(0.0f, 0.0f);

	sf::Vector2f bodyPosition = body.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if (bodyPosition.x > 0)
			movement.x -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if (bodyPosition.x < screenWidth - body.getSize().x)
			movement.x += speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if (bodyPosition.y > 0)
			movement.y -= speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if (bodyPosition.y < screenHeight - body.getSize().y)
			movement.y += speed * deltaTime;
	}

	if (movement.x == 0.0f) {
		row = 0;
	}
	else {
		row = 1;

		if (movement.x > 0.0f) {
			faceRight = true;
		}
		else {
			faceRight = false;
		}
	}

	anim.animate(row, deltaTime, faceRight);
	body.setTextureRect(anim.uvRect);
	body.move(movement);
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(body);
}

sf::FloatRect Player::getGlobalBounds()
{
	return body.getGlobalBounds();
}

void Player::setPosition(int x, int y)
{
	body.setPosition(x, y);
}
