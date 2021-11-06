#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include<SFML/Window/WindowStyle.hpp>
#include<SFML/System/Clock.hpp>
#include<iostream>
#include "Engine.h"

int main()
{
	Engine e1 = Engine(500, 500, "SFML");
	e1.init();

	return 0;
}