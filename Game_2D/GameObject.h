#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include<SFML/Graphics/Image.hpp>
#include<SFML/Graphics/RenderTexture.hpp>
#include<stack>
#include <iostream>

class Point2D;
class LineSegment;

class GameObject
{
public:
	virtual GameObject* clone() const = 0;
};

class AnimatedObject : public GameObject {
public:
	virtual void animate() = 0;
};


class UpdatableObject : public GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	virtual void update(sf::RenderWindow& window, sf::Texture texture) = 0;
	virtual void setPosition(sf::RenderWindow window, int x, int y) = 0;
	virtual void move(sf::RenderWindow window, int x, int y) = 0;
};

class UpdatableBitmap : public UpdatableObject {
public:
	UpdatableBitmap(std::string bitmapPath);
	void update(sf::RenderWindow& window, sf::Texture texture);
	void setPosition(sf::RenderWindow& window, int x, int y);
	void move(sf::RenderWindow window, int x, int y);
};

class DrawableObject : public virtual GameObject {
public:
	virtual void draw(sf::RenderWindow& window) = 0;
};

class BitmapHandler : public virtual GameObject {
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	bool deleteSprite;
public:
	BitmapHandler(std::string bitmapPath) {
		if (!texture.loadFromFile(bitmapPath)) {
			throw EXIT_FAILURE;
		}
		sprite.setTexture(texture);
		deleteSprite = false;
	}
	virtual void deleteBitmap() = 0;
	virtual void loadFromFile(std::string bitmapPath) = 0;
	virtual void saveToFile(std::string fileName) = 0;
};

class BitmapObject : public DrawableObject, BitmapHandler {
public:
	BitmapObject(std::string bitmapPath) : BitmapHandler(bitmapPath) {}
	BitmapObject(std::string bitmapPath, int x, int y) : BitmapHandler(bitmapPath) { setBitmapPosition(x, y); }
	void draw(sf::RenderWindow& window);
	virtual void deleteBitmap();
	virtual void loadFromFile(std::string bitmapPath);
	virtual void saveToFile(std::string fileName);
	virtual BitmapObject* clone() const override;
	bool getDeleteBitmap();
	void setBitmapPosition(int x, int y);
};

class TransformableObject : public virtual GameObject {
public:
	virtual void translate(sf::RenderWindow& window, int x, int y) = 0;
	virtual void rotate(sf::RenderWindow& window, float angle) = 0;
	virtual void scale(sf::RenderWindow& window, int x, int y) = 0;
};

class PrimitiveRender : public GameObject
{
public:
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2); //the default color is white
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
	void drawLine(sf::RenderWindow& window, LineSegment line);
	void drawLine(sf::RenderWindow& window, LineSegment line, sf::Color color);
	void drawLine(sf::RenderWindow& window, Point2D point1, Point2D point2);
	void drawLine(sf::RenderWindow& window, Point2D point1, Point2D point2, sf::Color color);
	void drawCircle(sf::RenderWindow& window, int radius, int x, int y);
	void drawCircle(sf::RenderWindow& window, int radius, int x, int y, sf::Color color);
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y);
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y, sf::Color color);
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y);
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, int x, int y);
	void drawPoint(sf::RenderWindow& window, int x, int y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, float x, float y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, Point2D point2D);
	void drawPoint(sf::RenderWindow& window, Point2D point2D, sf::Color color);
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2);
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
	void drawPolyline(sf::RenderWindow& window, std::vector<LineSegment> lineVector);
	void drawCircleSym8(sf::RenderWindow& window, float xCenter, float yCenter, float radius, sf::Color color);
	void drawEllipseSym4(sf::RenderWindow& window, int rx, int ry, int positionX, int positionY, sf::Color color);
	double cross(Point2D O, Point2D A, Point2D B);
	void drawPolygon(sf::RenderWindow& window, std::vector<Point2D> P);
	void boundryFill(sf::RenderWindow& window, int x, int y, sf::Color fill_color, sf::Color boundry_color);
	void floodFill(sf::RenderWindow& window, int x, int y, sf::Color fill_color, sf::Color boundry_color);
	virtual PrimitiveRender* clone() const override;
};

class ShapeObject : public DrawableObject, TransformableObject {
protected:
	PrimitiveRender primitive;
};


class Point2D : public ShapeObject {
	int x, y;
public:
	Point2D(int x, int y);
	Point2D();
	int getX();
	int getY();
	void changeX(int x);
	void changeY(int y);
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual Point2D* clone() const override;
};

class LineSegment : public ShapeObject {
	Point2D point1, point2;
public:
	LineSegment();
	LineSegment(Point2D point1, Point2D point2);
	LineSegment(int x1, int y1, int x2, int y2);
	void changePoint1(Point2D point1);
	void changePoint2(Point2D point2);
	void changePoint1(int x1, int y1);
	void changePoint2(int x2, int y2);
	int getPoint1X();
	int getPoint1Y();
	int getPoint2X();
	int getPoint2Y();
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual LineSegment* clone() const override;
};

class Circle : public ShapeObject {
	sf::CircleShape circle;
	int radius, x, y;
public:
	Circle(int radius, int x, int y);
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual Circle* clone() const override;

};

class Rectangle : public ShapeObject {
	sf::RectangleShape rectangle;
	int sizeX, sizeY, x, y;
public:
	Rectangle(int sizeX, int sizeY, int x, int y);
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual Rectangle* clone() const override;
};

class Triangle : public ShapeObject {
	int size, x, y;
	sf::CircleShape triangle;
public:
	Triangle(int size, int x, int y);
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual Triangle* clone() const override;
};

class Polyline : public ShapeObject {
	std::vector<LineSegment> lineVector;
public:
	Polyline(std::vector<LineSegment> lineVector);
	void draw(sf::RenderWindow& window);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual Polyline* clone() const override;
};

class Ellipse : public ShapeObject {
	int rx, ry, positionX, positionY;
	sf::Color color;
public:
	Ellipse(int rx, int  ry, int positionX, int positionY, sf::Color color);
	void draw(sf::RenderWindow& window);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual Ellipse* clone() const override;
};

class Polygon : public ShapeObject {
	std::vector<Point2D> P;
public:
	Polygon(std::vector<Point2D> P);
	void draw(sf::RenderWindow& window);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, int x, int y);
	virtual Polygon* clone() const override;
};


