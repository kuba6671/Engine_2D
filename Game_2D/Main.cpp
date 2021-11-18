#include<iostream>
#include "Engine.h"


int main()
{
	Engine e1 = Engine(1000, 1000, "SFML");
	try {
		e1.init();
	}
	catch (const int s) {
		exit(s);
	}
	return 0;
}