#pragma once
#include "Button.h"

class Calculator {
private:
	sf::RenderWindow window;
	std::vector<Button> keyboard;
	std::string keyboardSymbols[5][4] = { {"C", "CE", "x^2", "x^y"},
										  {"7", "8", "9", "+"},
										  {"6", "5", "4", "-"},
										  {"3", "2", "1", "*"},
										  {".", "0", "=", "/"} };
public:
	Calculator();
	void Run();
private:
	void processEvents();
	void update();
	void render();
};