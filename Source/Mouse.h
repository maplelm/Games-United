#ifndef MOUSE_H
#define MOUSE_H

#include <SFML\Graphics.hpp>

class Mouse
{
public:

	Mouse(sf::RenderWindow*);

	sf::RenderWindow * targetRenderWindow;
	void updateTargetWindow(sf::RenderWindow*);

	//Position Functions
	static sf::Vector2i getGlobalPos();
	static sf::Vector2i getLocalPos(sf::RenderWindow*);
	static void setLocalPos(sf::Vector2i, sf::RenderWindow*);
	static void setGlobalPos(sf::Vector2i);
	static bool isLeftClicked();
	static bool isRightClicked();
	bool isWithin(sf::FloatRect); 

private:
	void updateLocatoin();
	sf::FloatRect loc;
};

#endif //MOUSE_H
