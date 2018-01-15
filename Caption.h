#pragma once
#include <SFML/Graphics.hpp>
#include "Window.h"

class Caption
{
private:
	sf::Font font;
	sf::Text text;
	sf::String string;
	sf::Vector2f position;
	int size;
	sf::Vector2f textSize;
	std::string fontPath;
	sf::Color color;

	void setOrigin();

public:
	Caption();
	~Caption();
	Caption(std::string,float = 0,float = 0,std::string s = "data/General/font1.ttf");
	sf::Text& getText();
	sf::String& getString();
	void add(char);
	void add(sf::Event);
	void escape();
	void draw();
	void setPosition(float,float);
	void setPosition(sf::Vector2f);
	void setSize(int);
	sf::Vector2f getTextSize();
	void setColor(sf::Color);
	void setFont(std::string);
	void setString(std::string);
	void clear();
	bool isEmpty();
};
