#include <SFML/Graphics.hpp>
#include "Config.h"
#include "Calc.h"
#include "Button.h"

Calculator::Calculator()
	:window(WINDOW_SIZE, "Calculator")
{

	for (int i = 1; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			Button btn(buttonSize);
			if (j == 3 && i > 1) {
				btn.setFillColor(colorFillButtonOrange);
				btn.setOutlineColor(colorOutlineButtonOrange);
				btn.setOutlineThickness(tricknessSize / 2);
			}
			else {
				btn.setFillColor(colorFillButton);
				btn.setOutlineColor(colorOutlineButton);
				btn.setOutlineThickness(tricknessSize);
			}
			btn.setString(keyboardSymbols[i-1][j]);
			btn.setPosition(sf::Vector2f(j * (buttonSize.x + tricknessSize), i * (buttonSize.y + tricknessSize)));
			keyboard.push_back(btn);
		}
	}
}

	//if (!font.loadFromFile("arial.ttf")) {
	//	//error
	//}

	//int posX = buttonSize.x + tricknessSize, posY = buttonSize.y + tricknessSize;

	//for (int i = 1; i < 6; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		sf::Text text;
	//		text.setFont(font);
	//		text.setString(textArray[i - 1][j]);
	//		text.setCharacterSize(35);
	//		text.setFillColor(sf::Color::White);
	//		text.setPosition(sf::Vector2f(j * posX + buttonSize.x / 3, i * posY + buttonSize.y / 3));
	//		textForButton.push_back(text);
	//	}
	//}

	//for (int i = 1; i < 6; i++) {
	//	for (int j = 0; j < 4; j++) {
	//		sf::RectangleShape btn(buttonSize);

	//		if (j == 3 && i > 1) {
	//			btn.setFillColor(colorFillButtonOrange);
	//			btn.setOutlineColor(colorOutlineButtonOrange);
	//			btn.setOutlineThickness(tricknessSize / 2);
	//		}
	//		else {
	//			btn.setFillColor(colorFillButton);
	//			btn.setOutlineColor(colorOutlineButton);
	//			btn.setOutlineThickness(tricknessSize);
	//		}
	//		btn.setPosition(sf::Vector2f(j * (buttonSize.x + tricknessSize), i * (buttonSize.y + tricknessSize)));
	//		keyboard.push_back(btn);
	//	}
	//}

void Calculator::Run()
{
	while (window.isOpen()) {
		processEvents();
		update();
		render();
	}
}

void Calculator::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window.close();
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i localPosition = sf::Mouse::getPosition(window);
			keyboard.
		}
	}
}

void Calculator::update()
{

}

void Calculator::render()
{
	window.clear(colorOutlineButton);
	for (auto i : keyboard) {
		i.draw(window);
	}
	window.display();
}
