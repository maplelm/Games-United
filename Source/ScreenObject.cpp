#include "ScreenObject.h"

//Constructors-----------------------------------------------------
ScreenObject::ScreenObject()
{
	ID = -1;
}
ScreenObject::ScreenObject(int id)
{
	ID = id;
}
ScreenObject::ScreenObject(int id, sf::RenderWindow *windowHandle)
{
	ID = id;
	WindowPnt = windowHandle;

}
ScreenObject::ScreenObject(int id,sf::RenderWindow *windowHandle, std::string textureName)
{
	ID = id;
	WindowPnt = windowHandle;
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
bool ScreenObject::isTriggered()
{
	return state.triggered;
}
bool ScreenObject::isMouseOver()
{
	return state.mouseOver;
}
bool ScreenObject::isVisable()
{
	return state.visable;
}
bool ScreenObject::isDisabled()
{
	return state.disabled; 
}

//Toggle Functions-----------------------------------------------------
void ScreenObject::toggleTriggered()
{
	if (state.triggered)
		state.triggered = false;
	else
		state.triggered = true;

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
void ScreenObject::toggleVisable()
{
	if (state.visable)
		state.visable = false;
	else
		state.visable = true;
}
void ScreenObject::toggleDisable()
{
	if (state.disabled)
		state.disabled = false;
	else
		state.disabled = true;
}
void ScreenObject::toggleMouseOver()
{
	if (state.mouseOver)
		state.mouseOver = false;
	else
		state.mouseOver = true;
}
//Graphics Functions-----------------------------------------------------
bool ScreenObject::loadTexture(std::string textureName)
{
	textureFileName = textureName;

	if (!objectTexture.loadFromFile(textureName))
		return false;
	
	objectSprite.setTexture(objectTexture);
	objectSprite.setTextureRect(sf::IntRect(objectSprite.getPosition().x, objectSprite.getPosition().y, objectTexture.getSize().x, objectTexture.getSize().y));
	return true;
}
void ScreenObject::draw()
{
	WindowPnt->draw(objectSprite);
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
sf::RenderWindow * ScreenObject::getTargetWindow()
{
	return WindowPnt;
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
	state.triggered = onOff;
}
void ScreenObject::setVisable(bool onOff)
{
	state.visable = onOff;
}
void ScreenObject::setDisable(bool onOff)
{
	state.disabled = onOff;
}
void ScreenObject::setmouseOver(bool onOff)
{
	state.mouseOver = onOff;
}
void ScreenObject::setSmooth(bool onOff)
{
	objectTexture.setSmooth(onOff);
}
void ScreenObject::setRepeated(bool onOff)
{
	objectTexture.setRepeated(onOff);
}
void ScreenObject::setTargetWindow(sf::RenderWindow* tarWindow)
{
	WindowPnt = tarWindow;
}
//User Interaction Functions
void ScreenObject::clicked(sf::RenderWindow* window)
{
	Mouse mobj(window);
	if (mobj.isWithin(objectSprite.getGlobalBounds()) && state.triggered == false)
	{
		state.triggered = true;
		std::cout << "button " << ID << "\t triggered: " << state.triggered << std::endl;
	}
	else if (state.triggered = true && !Mouse::isLeftClicked)
		state.triggered = false;
	std::cout << "button " << ID << "\t triggered: " << state.triggered << std::endl;
}