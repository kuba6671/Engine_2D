#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include "PrimitiveRender.h"

class GameObject
{
public:
	virtual GameObject* clone() const = 0;
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
protected:
	Point2D point1;
	LineSegment line1;
public:
	virtual void draw(sf::RenderWindow& window) = 0;
};

class TransformableObject : public virtual GameObject {
public:
	virtual void translate(sf::RenderWindow& window, int x, int y) = 0;
	virtual void rotate(sf::RenderWindow& window, float angle) = 0;
	virtual void scale(sf::RenderWindow& window, int x, int y) = 0;
};

class ShapeObject : public DrawableObject, TransformableObject {
protected:
	PrimitiveRender primitive;
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


