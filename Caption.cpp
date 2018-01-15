#include "Caption.h"
#include <iostream>

Caption::Caption()
:size(30),
 position(0,0),
 fontPath("data/StateOptions/Capture_it.ttf"),
 string("Caption"),
 color(sf::Color::White)
{
	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setColor(color);
	text.setString(string);

	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f,
					textRect.top  + textRect.height/2.0f);
}

Caption::~Caption() {}

Caption::Caption(std::string string, float x, float y, std::string fontPath)
:color(sf::Color::White),
 size(30)
{
	this->string = string;
	this->fontPath = fontPath;

	font.loadFromFile(fontPath);
	text.setFont(font);
	text.setCharacterSize(size);
	text.setColor(color);
	text.setString(string);

	setOrigin();

	position = {x,y};
	text.setPosition(position);
}

sf::Text& Caption::getText() { return text; }

void Caption::setPosition(float x, float y)
{
	position = {x,y};
	text.setPosition(position);
}

void Caption::setSize(int size)
{
	this->size = size;
	text.setCharacterSize(size);

	setOrigin();
}

void Caption::setColor(sf::Color color)
{
	this->color = color;
	text.setColor(color);
}

void Caption::setFont(std::string fontPath)
{
	this->fontPath = fontPath;
	font.loadFromFile(fontPath);
	text.setFont(font);
}

void Caption::setString(std::string string)
{
	this->string = string;
	text.setString(string);
	setOrigin();
}

void Caption::clear()
{
	string.clear();
	text.setString(string);
	setOrigin();
}

bool Caption::isEmpty()
{
	return string.isEmpty();
}

sf::String& Caption::getString()
{
	return string;
}

void Caption::add(sf::Event event)
{
	string += event.text.unicode;
	text.setString(string);
	setOrigin();
}

void Caption::setOrigin()
{
	sf::FloatRect textRect = text.getLocalBounds();
	text.setOrigin(textRect.left + textRect.width/2.0f,
					textRect.top  + textRect.height/2.0f);

	textSize = { textRect.width, textRect.height };
}

void Caption::draw()
{
	Window::instance().getWindow()->draw(text);
}

void Caption::setPosition(sf::Vector2f pos)
{
	position = pos;
	text.setPosition(position);
}

void Caption::add(char sign)
{
	string += sign;
}

sf::Vector2f Caption::getTextSize()
{
	return textSize;
}

void Caption::escape()
{
    std::string str  = string;
    str = str.substr(0, str.size() - 1);
    string.clear();
    string = str;
    text.setString(string);
    setOrigin();
}
