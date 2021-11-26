#include<iostream>
#include "Engine.h"


int main()
{
	Engine e1 = Engine(1024, 768, "Engine 2D");
	try {
		e1.init();
	}
	catch (const int s) {
		exit(s);
	}
	return 0;
}