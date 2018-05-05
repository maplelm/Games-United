#include "ScreenObject.h"

//Constructors-----------------------------------------------------
ScreenObject::ScreenObject()
{
	selected = false;
}

//Destructor's-----------------------------------------------------
ScreenObject::~ScreenObject()
{
	//nothing to destruct
}

//Toggle Queries-----------------------------------------------------
bool ScreenObject::isRepeated()
{
	return objectTexture.isRepeated();
}
bool ScreenObject::isSmooth()
{
	return objectTexture.isSmooth();
}
bool ScreenObject::isSelect()
{
	return selected;
}

//Toggle Functions-----------------------------------------------------
void ScreenObject::toggleSelect()
{
	if (selected)
		selected = false;
	else
		selected = true;

	/*Change the texture to glow or something
	add functionality later*/
}

void ScreenObject::toggleRepeated()
{
	if (this->objectTexture.isRepeated())
		this->objectTexture.setRepeated(false);
	else
		this->objectTexture.setRepeated(true);
}

void ScreenObject::toggleSmooth()
{
	if (objectTexture.isSmooth())
		objectTexture.setSmooth(false);
	else
		this->objectTexture.setSmooth(true);
}
//Graphics Functions-----------------------------------------------------
bool ScreenObject::loadTexture(std::string textureName)
{
	if (!objectTexture.loadFromFile(textureName))
		return false;

	objectSprite.setTexture(objectTexture);
	return true;
}

//Manipulation Functions-----------------------------------------------------

void ScreenObject::moveSprite(float x, float y)
{
	objectSprite.move(x, y);
}
void ScreenObject::moveSprite(sf::Vector2f vf)
{
	objectSprite.move(vf);
}
void ScreenObject::setPosition(float x, float y)
{
	objectSprite.setPosition(x, y);
}
//theta is in degrees
void ScreenObject::setRotation(float theta)
{
	objectSprite.setRotation(theta);
}
//theta is in degrees
void ScreenObject::Rotate(float theta)
{
	objectSprite.rotate(theta);
}
void ScreenObject::setScale(float xScale, float yScale)
{
	objectSprite.setScale(xScale, yScale);
}

//Getters-----------------------------------------------------
sf::Sprite ScreenObject::getSprite()
{
	return objectSprite;
}
sf::Texture ScreenObject::getTexture()
{
	return objectTexture;
}
float ScreenObject::getRotation()
{
	return objectSprite.getRotation();
}
sf::Vector2f ScreenObject::getScale()
{
	return objectSprite.getScale();
}
//Setters-----------------------------------------------------

void ScreenObject::setSprite(sf::Sprite sprite)
{
	this->objectSprite = sprite;
}

void ScreenObject::setTexture(std::string textureName)
{
	this->textureFileName = textureName;
	loadTexture(textureName);
}
void ScreenObject::setSelected(bool onOff)
{
	selected = onOff;
}
void ScreenObject::setSmooth(bool onOff)
{
	objectTexture.setSmooth(onOff);
}
void ScreenObject::setRepeated(bool onOff)
{
	objectTexture.setRepeated(onOff);
}
//User Interaction Functions-----------------------------------------------------
/*bool ScreenObjects::onClick()
{
return true;
}
bool ScreenObjects::onRelease()
{
return true;
}*/