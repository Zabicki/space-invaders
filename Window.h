#pragma once
#include <SFML/Graphics.hpp>

//Singleton class
//TODO
//[]Erase setFramerateLimit(60) and swap it on the proper 60 fps loop with use of Time class in main.cpp

class Window
{
private:
	Window();
	sf::RenderWindow window;
	float width;
	float height;
public:
	static Window & instance()
	{
		static Window a;
		return a;
	}
	~Window();
	sf::RenderWindow* getWindow();
};
