#pragma once
const int tricknessSize = 4;

const sf::VideoMode WINDOW_SIZE(400.f - tricknessSize, 600.f - tricknessSize);
const sf::Vector2f buttonSize(100.f - tricknessSize, 100.f - tricknessSize);

const sf::Color colorFillButton(43, 43, 43, 255);
const sf::Color colorOutlineButton(28, 28, 28, 255);

const sf::Color colorFillButtonOrange(190, 130, 20, 255);
const sf::Color colorOutlineButtonOrange(138, 90, 8, 255);

const std::string textArray[5][4] = { {"C", "CE", "x^2", "x^y"},
									{"7", "8", "9", "+"},
									{"6", "5", "4", "-"},
									{"3", "2", "1", "*"},
									{"0", ".", "=", "/"} };
