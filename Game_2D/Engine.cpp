#include "Engine.h"

sf::Vector2f velocity;

Engine::Engine(int screenWidth, int screenHeight, std::string windowTitle) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->windowTitle = windowTitle;
	color = sf::Color(150, 150, 150);
}
Engine::Engine(int screenWidth, int screenHeight) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	color = sf::Color(150, 150, 150);
}

int Engine::init() {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), windowTitle);
	PrimitiveRender p1;
	int columns = 10;
	int rows = 10;
	int i, j;
	int scene[10][10] = { {0,0,0,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,1,0},
	{0,0,0,0,0,0,0,0,0,0},
	{0,0,0,1,1,1,1,0,0,0},
	{1,1,1,1,1,1,1,1,1,1} };

	velocity.y = 0.f;
	velocity.x = 0.f;

	std::vector<Rectangle> walls;
	Rectangle wall(80, 80, 5 * 80, 5 * 80);
	wall.setColor(sf::Color::Red);
	walls.push_back(wall);

	const float gridSize = 50;

	sf::Texture playerTexture;
	playerTexture.loadFromFile("bird.png");

	Player player(&playerTexture, sf::Vector2u(5, 3), 0.1f, 100.0f);

	float deltaTime = 0.0f;

	Rectangle wall2(gridSize, gridSize, gridSize * 5, gridSize * 5);
	wall2.setColor(sf::Color::Red);
	walls.push_back(wall2);
	sf::FloatRect nextPos;

	for (i = 0; i < columns; i++) {
		for (j = 0; j < rows; j++)
		{
			if (scene[j][i] == 1) {
				Rectangle wall3(80, 80, i * 80, j * 80);
				wall3.setColor(sf::Color::Red);
				walls.push_back(wall3);
			}
		}
	}

	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (mouse.isButtonPressed(sf::Mouse::Left)) {
				sf::Vector2i mouse_pos = mouse.getPosition(window);
				Rectangle wall4(80, 80, mouse_pos.x, mouse_pos.y);
				wall4.setColor(sf::Color::Red);
				walls.push_back(wall4);
			}
			if (keyboard.isKeyPressed(sf::Keyboard::R)) {
				for (auto& i : walls)
				{
					i.rotate(window, 10.0);
				}
			}
			else if (keyboard.isKeyPressed(sf::Keyboard::W)) {
				for (auto& i : walls)
				{
					i.scale(window, 0.5, 0.5);
				}
			}
			else if (keyboard.isKeyPressed(sf::Keyboard::D)) {
				for (auto& i : walls)
				{
					i.scale(window, 1, 1);
				}
			}
			else if (keyboard.isKeyPressed(sf::Keyboard::B)) {
				paintScreen(sf::Color::Blue);
			}
			else if (keyboard.isKeyPressed(sf::Keyboard::G)) {
				paintScreen(sf::Color(150, 150, 150));
			}
			else if (keyboard.isKeyPressed(sf::Keyboard::S)) {
				sf::Vector2u windowSize = window.getSize();
				sf::Texture textureBitmap;
				textureBitmap.create(windowSize.x, windowSize.y);
				textureBitmap.update(window);
				sf::Image image = textureBitmap.copyToImage();
				BitmapObject current_window(image);
				current_window.saveImagetoFile("Current_window.png");
			}
		}

		for (auto& wall : walls)
		{
			sf::FloatRect playerBounds = player.getGlobalBounds();
			sf::FloatRect wallBounds = wall.getGlobalBounds();

			nextPos = playerBounds;
			nextPos.left += velocity.x;
			nextPos.top += velocity.y;


			if (wallBounds.intersects(nextPos))
			{
				//Right collision
				if (playerBounds.left < wallBounds.left
					&& playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top)

				{
					velocity.x = 0.f;
					player.setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
				}

				//Left collision
				if (playerBounds.left > wallBounds.left
					&& playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
					&& playerBounds.top < wallBounds.top + wallBounds.height
					&& playerBounds.top + playerBounds.height > wallBounds.top)

				{
					velocity.x = 0.f;
					player.setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
				}

				//top
				if (playerBounds.top > wallBounds.top
					&& playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
					&& playerBounds.left < wallBounds.left + wallBounds.width
					&& playerBounds.left + playerBounds.width > wallBounds.left)

				{
					velocity.y = 0.f;
					player.setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
				}
			}
		}

		window.clear(color);
		p1.drawEllipseSym4(window, 50, 80, 60, 100, sf::Color::White);
		p1.drawCircleSym8(window, 900, 100, 50, sf::Color::Yellow);
		p1.incrementalAlghorithm(window, 10, 10, 1000, 100);
		player.update(deltaTime, screenWidth, screenHeight);
		for (auto& i : walls)
		{
			i.draw(window);
		}
		player.draw(window);
		window.display();
	}
	return 0;
}
void Engine::paintScreen(sf::Color color) {
	this->color = color;
}
