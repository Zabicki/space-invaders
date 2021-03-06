#include "Window.h"

Window::Window()
:width(800),
 height(600)
{
	window.create(sf::VideoMode(width,height), "Space Invaders", sf::Style::Close | sf::Style::Titlebar);
}

Window::~Window() {}

sf::RenderWindow* Window::getWindow() { return &window; }
