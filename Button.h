#pragma once
class Button
{
private:
	sf::Text text;
	sf::Font font;
	sf::RectangleShape shape;
public:
	Button(sf::Vector2f size);
	void setString(std::string);
	void setFillColor(sf::Color color);
	void setOutlineColor(sf::Color color);
	void setOutlineThickness(int size);
	void setPosition(sf::Vector2f position);
	void draw(sf::RenderWindow& window);
	sf::Vector2f workMousePosition();
};

