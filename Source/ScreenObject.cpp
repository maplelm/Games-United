#include "ScreenObject.h"

//Constructors-----------------------------------------------------
ScreenObject::ScreenObject()
{
	selected = false;
	mouseHover = false;
}
ScreenObject::ScreenObject(std::string textureName)
{
	selected = false;
	mouseHover = false;
	setTexture(textureName);
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
bool ScreenObject::isMouseHover()
{
	return mouseHover;
}
bool ScreenObject::isVisable()
{
	return visable;
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
void ScreenObject::toggleMouseHover()
{
	if (mouseHover)
		mouseHover = false;
	else
		mouseHover = true;
}
void ScreenObject::toggleVisable()
{
	if (visable)
		visable = false;
	else
		visable = true;
}

//Graphics Functions-----------------------------------------------------
bool ScreenObject::loadTexture(std::string textureName)
{
	textureFileName = textureName;

	if (!objectTexture.loadFromFile(textureName))
		return false;

	objectSprite.setTexture(objectTexture);
	return true;
}

//Manipulation Functions-----------------------------------------------------
void ScreenObject::move(float x, float y)
{
	objectSprite.move(x, y);
}
void ScreenObject::move(sf::Vector2f vf)
{
	objectSprite.move(vf);
}
void ScreenObject::setPosition(float x, float y)
{
	objectSprite.setPosition(x, y);
}
void ScreenObject::setPosition(sf::Vector2f pos)
{
	objectSprite.setPosition(pos);
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
void ScreenObject::setScale(sf::Vector2f scl)
{
	objectSprite.setScale(scl);
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
	objectSprite = sprite;
}

void ScreenObject::setTexture(std::string textureName)
{
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

//Virtual Fucntions-----------------------------------------------------
bool ScreenObject::onClick()
{
	//fucntion is called when window verifies that the mouse has clicked on object
	return true;
}
bool ScreenObject::onRelease()
{
	//fucntion is called after the mouse has released its click
	return true;
}