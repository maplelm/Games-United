#include "Mouse.h"

//Constructors---------------------------------------
Mouse::Mouse()
{
	//constructor stuff
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