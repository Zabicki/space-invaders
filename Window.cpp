#include "Window.h"

Window::Window()
:width(800),
 height(600)
{
	window.create(sf::VideoMode(width,height), "Space Invaders v0.1", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(60);
}

Window::~Window() {}

sf::RenderWindow* Window::getWindow() { return &window; }
