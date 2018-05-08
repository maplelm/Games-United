#include "Mouse.h"

//Constructors------------------------------------------
Mouse::Mouse(sf::RenderWindow* window)
{
	loc = sf::FloatRect(sf::Vector2f(0, 0), sf::Vector2f(1, 1));
	targetRenderWindow = window;
}
//Position Functions-----------------------------------
sf::Vector2i Mouse::getGlobalPos()
{
	return sf::Mouse::getPosition();
}
sf::Vector2i Mouse::getLocalPos(sf::RenderWindow* rw)
{
	return sf::Mouse::getPosition(*rw);
}
void Mouse::setLocalPos(sf::Vector2i pos, sf::RenderWindow* rw)
{
	sf::Mouse::setPosition(pos, *rw);
}
void Mouse::setGlobalPos(sf::Vector2i pos)
{
	sf::Mouse::setPosition(pos);
}
bool Mouse::isLeftClicked()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Left);
}
bool Mouse::isRightClicked()
{
	return sf::Mouse::isButtonPressed(sf::Mouse::Right);
}
void Mouse::updateLocatoin()
{
	loc.left = Mouse::getLocalPos(targetRenderWindow).x;
	loc.top = Mouse::getLocalPos(targetRenderWindow).y;
}
bool Mouse::isWithin(sf::FloatRect rect)
{
	updateLocatoin();
	return rect.intersects(loc);
}
void Mouse::updateTargetWindow(sf::RenderWindow* window)
{
	targetRenderWindow = window;
}