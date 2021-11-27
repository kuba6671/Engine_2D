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

/**
 * Struktura reprezentujaca pojedyncza klatke
 */
struct Frame {
	sf::IntRect rect;
	double duration; // in seconds
};
/**
*	Glowna klasa znajdujaca sie najwyzej w hierarchii.
*/
class GameObject
{
public:
	/**
	 * Metoda sluzaca do kopiowania obiektow
	 */
	virtual GameObject* clone() const = 0;
};

/**
*	Abstrkcyjna klasa dla obiektow gry, ktore moga byc animowane
*/
class AnimatedObject : virtual public GameObject {
public:
	/**
	 * Metoda sluzaca do animacji tekstur
	 * \param row - zmienna okresla numer aktualnego wiersza bitmapy
	 * \param deltaTime - zmienna okresla czas zwrocony przez zegar w glownej petli gry
	 * \param faceRight - zmienna okresla w ktora strone zrotowana jest bitmapa
	 */
	virtual void animate(int row, float deltaTime, bool faceRight) = 0;
};

/**
*	Abstrkcyjna klasa dla obiektow gry, ktore moga byc aktualizowane
*/
class UpdatableObject : public GameObject {
protected:
	/**
	 * \param textureBitmap - zmienna przechowujca bitmape
	 */
	sf::Texture textureBitmap;
	/**
	 * \param sprite - zmienna przechowujca sprite
	 */
	sf::Sprite sprite;
public:
	/**
	 * Abstrakcyjna metoda sluzaca do aktualizacji obiektow
	 * \param window - zmienna okresla aktualnie przetwarzane okno
	 * \param textureBitmap - zmienna przechowujca bitmape
	 */
	virtual void update(sf::RenderWindow& window, sf::Texture textureBitmap) = 0;
	/**
	 * abstrakcyjna metoda sluzaca do ustalenia pozycji na ekranie
	 * \param window - zmienna okresla aktualnie przetwarzane okno
	 * \param x - pozycja x
	 * \param y - pozycja y
	 */
	virtual void setPosition(sf::RenderWindow window, int x, int y) = 0;
	/**
	 * Abstrkcyjna metoda sluzaca do poruszania obiektu po ekranie
	 * \param window - zmienna okresla aktualnie przetwarzane okno
	 * \param x - pozycja x
	 * \param y - pozycja y
	 */
	virtual void move(sf::RenderWindow window, int x, int y) = 0;
};

/**
 * Klasa przechowujca bitmapy, ktore moga byc aktualizowane
 */
class UpdatableBitmap : public UpdatableObject {
public:
	/**
	 * Konstruktor klasy
	 * \param bitmapPath - sciezka do bitmapy
	 */
	UpdatableBitmap(std::string bitmapPath);
	/**
	 * Metoda sluzaca do aktualizacji obiektow
	 * \param window - zmienna okresla aktualnie przetwarzane okno
	 * \param textureBitmap - zmienna przechowujca bitmape
	 */
	void update(sf::RenderWindow& window, sf::Texture textureBitmap);
	/**
	* Metoda sluzaca do ustalenia pozycji na ekranie
	* \param window - zmienna okresla aktualnie przetwarzane okno
	* \param x - pozycja x
	* \param y - pozycja y
	*/
	void setPosition(sf::RenderWindow& window, int x, int y);
	/**
	 * Metoda sluzaca do poruszania obiektu po ekranie
	 * \param window - zmienna okresla aktualnie przetwarzane okno
	 * \param x - pozycja x
	 * \param y - pozycja y
	 */
	void move(sf::RenderWindow window, int x, int y);
};
/**
 * Klasa bazowa dla obiektow, ktore moga zostac narysowane na ekranie
 */
class DrawableObject : public virtual GameObject {
public:
	/**
	 * Metoda sluzaca do rysowania obiektow
	 * \param window - zmienna okresla aktualnie przetwarzane okno
	 */
	virtual void draw(sf::RenderWindow& window) = 0;
};

/**
 * Klasa obslugujaca podstawowe funkcjonalnosci zwiazane z bitmapami
 */
class BitmapHandler : public virtual GameObject {
public:
	/**
	 * Abstrkcyjna metoda sluzaca do usuwania bitmapy
	 */
	virtual void deleteBitmap() = 0;
	/**
	 * Abstrkcyjna metoda sluzaca do ladowania bitmapy z pliku
	 * \param bitmapPath
	 */
	virtual void loadFromFile(std::string bitmapPath) = 0;
	/**
	 * Abstrakcyjna metoda sluzaca do zapisania bitmapy do pliku
	 * \param fileName - nazwa pliku
	 */
	virtual void saveToFile(std::string fileName) = 0;
};
/**
 * Klasa bazowa dla obiektow, ktore moga zostac narysowane na ekranie z uzyciem bitmap
 */
class BitmapObject : public virtual DrawableObject, BitmapHandler {
protected:
	sf::Texture textureBitmap;
	sf::Sprite sprite;
	/**
	 * \param - zmienna okresla czy bitmapa ma byc usunieta
	 */
	bool deleteSprite;
	sf::Image image;
public:
	/**
	 * Konstruktor domyslny
	 */
	BitmapObject() { deleteSprite = false; };
	/**
	 *  Konstruktor
	 * \param bitmapPath - sciezka do bitmapy
	 */
	BitmapObject(std::string bitmapPath);
	/**
	 * Konstruktor
	 * \param bitmapPath - sciezka do bitmapy
	 * \param x - pozycja x
	 * \param y - pozycja y
	 */
	BitmapObject(std::string bitmapPath, int x, int y);
	BitmapObject(sf::Image image);
	/**
	 * Metoda sluzaca do rysowania obiektow
	 */
	void draw(sf::RenderWindow& window);
	virtual void deleteBitmap();
	virtual void loadFromFile(std::string bitmapPath);
	virtual void saveToFile(std::string fileName);
	void saveImagetoFile(std::string fileName);
	/**
	 * Metoda sluzaca do klonowania obiektu
	 * \return - zwraca sklonowany obiekt
	 */
	virtual BitmapObject* clone() const override;
	sf::Sprite getSprite();
	/**
	 * Metoda okresla stan bitmapy(czy bitmapa zostala usunieta)
	 * \return - zwraca true w przypadku gdy bitmapa jest usunieta
	 */
	bool getBitmapState();
	void setBitmapPosition(int x, int y);
};
/**
 * Klasa bazowa dla obiektow, ktore moga zostac narysowane na ekranie z uzyciem bitmap, i ktore
 *  moga zostac animowane na zasadzie wykorzystania spriteow
 */
class SpriteObject : public BitmapObject, AnimatedObject {
public:
	/**
	 * Konstruktor
	 * \param texture - zmienna przechowuje bitmape
	 * \param imageCount - zmienna ustala szerokosc i wysokosc bitmapy
	 * \param switchTime - szybkosc animacji obiektu
	 */
	SpriteObject(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	/**
	 * Metoda sluzaca do animacji tekstur
	 * \param row - zmienna okresla numer aktualnego wiersza bitmapy
	 * \param deltaTime - zmienna okresla czas zwrocony przez zegar w glownej petli gry
	 * \param faceRight - zmienna okresla w ktora strone zrotowana jest bitmapa
	 */
	void animate(int row, float deltaTime, bool faceRight);

	virtual SpriteObject* clone() const override;
	/**
	 * zmienna przechowuje szerokosc i wysokosc bitmapy
	 */
	sf::IntRect uvRect;
private:
	sf::Vector2u imageCount;
	/**
	 * Zmienna okresla aktualnie przetwarzana bitmape
	 */
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

/**
 * Klasa reprezentuje gracza, gracz jest animowany i sterowany za pomoca klawiatury
 */
class Player {
public:
	/**
	 * Konstruktor
	 * \param speed - szybkosc poruszania gracza
	 */
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	void update(float deltaTime, int screenWidth, int screenHeight);
	void draw(sf::RenderWindow& window);
	sf::FloatRect getGlobalBounds();
	void setPosition(int x, int y);
private:
	sf::RectangleShape body;
	SpriteObject anim;
	unsigned int row;
	float speed;
	bool faceRight;
	bool upDown;
};
/**
 * Klasa bazowa dla obiektow gry, ktore moga ulegac przeksztalceniom
 */
class TransformableObject : public virtual GameObject {
public:
	/**
	 *  Metoda sluzaca do przesuwania obiektow
	 * \param window
	 * \param x
	 * \param y
	 */
	virtual void translate(sf::RenderWindow& window, int x, int y) = 0;
	/**
	 * Metoda sluzaca do rotowania obiektow
	 * \param angle - zmienna okresla o ile stopni obiekt zostanie zrotowany
	 */
	virtual void rotate(sf::RenderWindow& window, float angle) = 0;
	/**
	 * Metoda sluzaca do skalowania obiektow
	 * \param window
	 * \param x
	 * \param y
	 */
	virtual void scale(sf::RenderWindow& window, float x, float y) = 0;
};
/**
 * Klasa sluzaca do rysowania prymitywow
 */
class PrimitiveRender : public GameObject
{
public:
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2); //the default color is white
	/**
	 * Metoda sluzaca do rysowania linii
	 * \param x1 - wspolrzedne x pierwszego konca linii
	 * \param y1 - - wspolrzedne y pierwszego konca linii
	 * \param x2 - - wspolrzedne x drugiego konca linii
	 * \param y2 - - wspolrzedne y drugiego konca linii
	 * \param color - kolor linii
	 */
	void drawLine(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
	/**
	 * Metoda sluzca do rysowania linii
	 * \param line - obiekt reprezentujacy linie
	 */
	void drawLine(sf::RenderWindow& window, LineSegment line);
	void drawLine(sf::RenderWindow& window, LineSegment line, sf::Color color);
	/**
	 * Metoda rysujaca linie
	 * \param point1 - obiekt przechowujacy wspolrzedne pierwszego konca linii
	 * \param point2 -  obiekt przechowujacy wspolrzedne drugiego konca linii
	 */
	void drawLine(sf::RenderWindow& window, Point2D point1, Point2D point2);
	void drawLine(sf::RenderWindow& window, Point2D point1, Point2D point2, sf::Color color);
	/**
	 * Metoda rysujaca okrag
	 * \param radius - promien okregu
	 * \param x - wspolrzedna x
	 * \param y - wspolrzedna y
	 */
	void drawCircle(sf::RenderWindow& window, int radius, int x, int y);
	void drawCircle(sf::RenderWindow& window, int radius, int x, int y, sf::Color color);
	/**
	 * Metoda rysujaca prostokat
	 * \param sizeX - dlugosc jednego boku
	 * \param sizeY - dlugosc drugiego boku
	 */
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y);
	void drawRectangle(sf::RenderWindow& window, int sizeX, int sizeY, int x, int y, sf::Color color);
	/**
	 * Metoda sluzaca do rysowania trojkata
	 * \param size - wielkosc trojkata
	 */
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y);
	void drawTriangle(sf::RenderWindow& window, int size, int x, int y, sf::Color color);
	/**
	 * Metoda sluzaca do rysowania punktu
	 * \param window
	 * \param x
	 * \param y
	 */
	void drawPoint(sf::RenderWindow& window, int x, int y);
	void drawPoint(sf::RenderWindow& window, int x, int y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, float x, float y, sf::Color color);
	void drawPoint(sf::RenderWindow& window, Point2D point2D);
	void drawPoint(sf::RenderWindow& window, Point2D point2D, sf::Color color);
	/**
	 * Metoda rysowania linii z wykorzystaniem algorytmu przyrostowego
	 */
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2);
	void incrementalAlghorithm(sf::RenderWindow& window, int x1, int y1, int x2, int y2, sf::Color color);
	/**
	 * Metoda umozliwiajaca narysowanie wielokata(lamanej zwyczajnej zamknietej)
	 * \param lineVector - kontener klasy vector przechowujacy linie
	 */
	void drawPolyline(sf::RenderWindow& window, std::vector<LineSegment> lineVector);
	/**
	 * Metoda rysujaca okrag z wykorzystaniem 8-krotnej symetrii
	 * \param xCenter - wspolrzedna x
	 * \param yCenter - wspolrzedan y
	 * \param radius - promien
	 * \param color - kolor okregu
	 */
	void drawCircleSym8(sf::RenderWindow& window, float xCenter, float yCenter, float radius, sf::Color color);
	/**
	 * Metoda umozliwiajaca narysowanie elipsy z wykorzysytaniem 4-krotnej symetrii
	 */
	void drawEllipseSym4(sf::RenderWindow& window, int rx, int ry, int positionX, int positionY, sf::Color color);
	double cross(Point2D O, Point2D A, Point2D B);
	/**
	 * Metoda rysujaca wielokat
	 * \param P - kontener klasy vector przechowujacy obiekty klasy Point
	 */
	void drawPolygon(sf::RenderWindow& window, std::vector<Point2D> P);
	/**
	 * Algorytm wypelniajacy obszar kolorem przez spojnosc
	 * \param fill_color - kolor wypelnienia
	 * \param boundry_color - kolor krawedzi
	 */
	void boundryFill(sf::RenderWindow& window, int x, int y, sf::Color fill_color, sf::Color boundry_color);
	/**
	* Algorytm wypelniajacy obszar kolorem przez spojnosc
	* \param fill_color - kolor wypelnienia
	* \param boundry_color - kolor krawedzi
	*/
	void floodFill(sf::RenderWindow& window, int x, int y, sf::Color fill_color, sf::Color boundry_color);
	virtual PrimitiveRender* clone() const override;
};
/**
 * Klasa bazowa dla obiektow, ktore moga zostac narysowane z uzyciem prymitywow
 */
class ShapeObject : public DrawableObject, TransformableObject {
protected:
	PrimitiveRender primitive;
};

/**
 * Klasa repreznetuje punkt(x,y)
 */
class Point2D : public ShapeObject {
	int x, y;
public:
	/**
	 * Konstruktor
	 * \param x - wspolrzedna x
	 * \param y - wspolrzedna y
	 */
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
	void scale(sf::RenderWindow& window, float x, float y);
	virtual Point2D* clone() const override;
};
/**
 * Klasa reprezentuje linie
 */
class LineSegment : public ShapeObject {
	Point2D point1, point2;
public:
	LineSegment();
	/**
	 * Konstruktor
	 * \param point1 - obiekt klasy Point2D przechowujacy wspolrzedne jednego konca linii
	 * \param point2 - obiekt klasy Point2D przechowujacy wspolrzedne drugiego konca linii
	 */
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
	void scale(sf::RenderWindow& window, float x, float y);
	virtual LineSegment* clone() const override;
};
/**
 * Klasa reprezentuje okrag
 */
class Circle : public ShapeObject {
	sf::CircleShape circle;
	int radius, x, y;
public:
	Circle(int radius, int x, int y);
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, float x, float y);
	virtual Circle* clone() const override;
};

/** Klasa repreznetujca prostokat */
class Rectangle : public ShapeObject {
	sf::RectangleShape rectangle;
	int sizeX, sizeY, x, y;
	float angle = 0.0;
public:
	Rectangle(int sizeX, int sizeY, int x, int y);
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, float x, float y);
	void setColor(sf::Color color);
	sf::FloatRect getGlobalBounds();
	virtual Rectangle* clone() const override;
};
/** Klasa reprezentujaca trojkat */
class Triangle : public ShapeObject {
	int size, x, y;
	sf::CircleShape triangle;
public:
	Triangle(int size, int x, int y);
	void draw(sf::RenderWindow& window);
	void draw(sf::RenderWindow& window, sf::Color color);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, float x, float y);
	virtual Triangle* clone() const override;
};
/** Klasa repreznetujaca wielokat zbudowany z wielu linii */
class Polyline : public ShapeObject {
	std::vector<LineSegment> lineVector;
public:
	Polyline(std::vector<LineSegment> lineVector);
	void draw(sf::RenderWindow& window);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, float x, float y);
	virtual Polyline* clone() const override;
};
/**
 * Klasa reprezentujaca elipse
 */
class Ellipse : public ShapeObject {
	int rx, ry, positionX, positionY;
	sf::Color color;
public:
	Ellipse(int rx, int  ry, int positionX, int positionY, sf::Color color);
	void draw(sf::RenderWindow& window);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, float x, float y);
	virtual Ellipse* clone() const override;
};
/** Klasa reprezentujaca wielokat */
class Polygon : public ShapeObject {
	std::vector<Point2D> P;
public:
	Polygon(std::vector<Point2D> P);
	void draw(sf::RenderWindow& window);
	void translate(sf::RenderWindow& window, int x, int y);
	void rotate(sf::RenderWindow& window, float angle);
	void scale(sf::RenderWindow& window, float x, float y);
	virtual Polygon* clone() const override;
};


