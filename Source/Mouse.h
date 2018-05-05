#ifndef MOUSE_H
#define MOUSE_H

#include <SFML\Graphics.hpp>

static class Mouse
{
public:
	Mouse();

	//Position Functions
	static sf::Vector2i getGlobalPos();
	static sf::Vector2i getLocalPos(sf::RenderWindow*);
	static void setLocalPos(sf::Vector2i, sf::RenderWindow*);
	static void setGlobalPos(sf::Vector2i);
	static bool isLeftClicked();
	static bool isRightClicked();
};

#endif //MOUSE_H
