#include <SFML/Graphics.hpp>
#include <iostream>
#include "Config.h"
#include "Calc.h"

Calculator::Calculator() :window(WINDOW_SIZE, "Calculator")
{
	if (!fontField.loadFromFile("arial.ttf")) {
		//error
	}
	this->textField.setCharacterSize(30);

	this->textField.setFillColor(sf::Color::White);

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
			btn.setString(keyboardSymbols[i - 1][j]);
			btn.setPosition(sf::Vector2f(j * (buttonSize.x + tricknessSize), i * (buttonSize.y + tricknessSize)));
			keyboard.push_back(btn);
		}
	}
}

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
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.mouseButton.button == sf::Mouse::Left) {
				sf::Vector2i mousePosition (sf::Mouse::getPosition(window));

				for (int i = 0; i < keyboard.size(); i++) {
					sf::Vector2f shapePosition (keyboard[i].getPos());

					if (mousePosition.x >= shapePosition.x 
						&& mousePosition.x <= shapePosition.x + buttonSize.x 
						&& mousePosition.y >= shapePosition.y 
						&& mousePosition.y <= shapePosition.y + buttonSize.y) {
							keyboard[i].setFillColor(keyboard[i].getOutlineColor());
							if (keyboard[i].getText() == "." ||
								keyboard[i].getText() >= "0" ||
								keyboard[i].getText() <= "9") {
								if (stringField.getSize() == 1 && stringField == "0") {
									stringField = keyboard[i].getText();
								}
								if (stringField[stringField.getSize()] != "." && keyboard[i] == ".") {
									stringField += keyboard[i].getText();
								}
								else {
									stringField += keyboard[i].getText();
								}
							}
					}
				}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased) {
			for (int i = 0; i < keyboard.size(); i++) {
				keyboard[i].setFillColor(keyboard[i].getColor());
			}
		}
	}
}

void Calculator::update()
{
	this->textField.setString(stringField);
	textField.setPosition(sf::Vector2f(
		WINDOW_SIZE.width - textField.getCharacterSize()/1.76*stringField.getSize(),
		buttonSize.y / 2 - textField.getCharacterSize()));
}

void Calculator::render()
{
	window.clear(colorOutlineButton);
	for (auto i : keyboard) {
		i.draw(window);
	}
	this->textField.setFont(fontField);
	window.draw(textField);
	window.display();
}