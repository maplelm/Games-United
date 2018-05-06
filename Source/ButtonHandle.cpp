#include "ButtonHandle.h"

//Cosntructors---------------------------------
ButtonHandle::ButtonHandle()
{
	//Constructor stuff
}
//Destructor'----------------------------------
ButtonHandle::~ButtonHandle()
{
	//Deconstrucor stuff
}
//Manipulation Functions-----------------------
void ButtonHandle::move(float x, float y)
{
	objectSprite.move(x, y);
	buttonText.move(x, y);
}
void ButtonHandle::move(sf::Vector2f pos)
{
	objectSprite.move(pos);
	buttonText.move(pos);
}
void ButtonHandle::setPosition(float x, float y)
{
	objectSprite.setPosition(x, y);
	buttonText.setPosition(x, y);
}
void ButtonHandle::setPosition(sf::Vector2f pos)
{
	objectSprite.setPosition(pos);
	buttonText.setPosition(pos);
}
//Theta is in degrees
void ButtonHandle::setRotation(float theta)
{
	objectSprite.setRotation(theta);
	buttonText.setRotation(theta);
}
void ButtonHandle::Rotate(float theta)
{
	objectSprite.rotate(theta);
	buttonText.rotate(theta);
}
void ButtonHandle::setScale(float x, float y)
{
	objectSprite.setScale(x, y); 
	buttonText.setScale(x, y); 
}
void ButtonHandle::setScale(sf::Vector2f scl)
{
	objectSprite.setScale(scl);
	buttonText.setScale(scl);
}