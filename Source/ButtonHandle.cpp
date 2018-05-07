#include "ButtonHandle.h"

//Cosntructors---------------------------------
ButtonHandle::ButtonHandle(std::string texture, std::string font)
{

	int startx = 0, starty = 0;
	//loading texture
	loadTexture(texture);

	//setting up the text to be in the right position
	updateOffset();
	std::cout << "obj h, w = " << textOffset.x << ", " << textOffset.y << std::endl;
	std::cout << "obj1 h, w = " << objectSprite.getGlobalBounds().height << ", " << objectSprite.getGlobalBounds().width << std::endl;
	objectSprite.setPosition(startx, starty);
	buttonText.setPosition(startx + textOffset.x, starty);
	loadFont(font);
	objectSprite.setColor(sf::Color::Red);
	objectSprite.setScale(1, 1.3);
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
	buttonText.setPosition(x + textOffset.x , y + textOffset.y);
}
void ButtonHandle::setPosition(sf::Vector2f pos)
{
	objectSprite.setPosition(pos );
	buttonText.setPosition(pos + textOffset);
	buttonText.move(textOffset.x, textOffset.y);
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
	updateOffset();
}
void ButtonHandle::setScale(sf::Vector2f scl)
{
	objectSprite.setScale(scl);
	buttonText.setScale(scl);
	updateOffset();
}
void ButtonHandle::setTextureScale(sf::Vector2f scl)
{
	objectSprite.setScale(scl);
	updateOffset();
}

//Setters-------------------------------------------------
void ButtonHandle::setTextOffset(float x, float y)
{
	textOffset = sf::Vector2f(x, y);
}
void ButtonHandle::setTextOffset(sf::Vector2f offset)
{
	textOffset = offset;
}
void ButtonHandle::setText(std::string str)
{
	buttonText.setString(str);
	textFix();
}
void ButtonHandle::setTextStyle(sf::Uint32 style)
{
	buttonText.setStyle(style);
}
void ButtonHandle::setFontSize(float size)
{
	buttonText.setCharacterSize(size);
	objectSprite.setScale(size / 30.0f, size * 0.04333333333);
	updateOffset();
}

//Getters-----------------------------------------------
std::string ButtonHandle::getText()
{
	return buttonText.getString();
}
sf::Vector2f ButtonHandle::getTextOffset()
{
	return textOffset; 
}
int ButtonHandle::getFontSize()
{
	return buttonText.getCharacterSize();
}
//Text Based Functions--------------------------------
void ButtonHandle::loadFont(std::string tarFont)
{
	buttonFont.loadFromFile(tarFont);
	buttonText.setFont(buttonFont);
}
void ButtonHandle::updateOffset()
{
	// setting the (width, hight) of the text offset
	textOffset = sf::Vector2f(
	 objectSprite.getGlobalBounds().width / 2.0f - ((buttonText.getCharacterSize() / 2.0f) * (buttonText.getString().getSize() / 2.0f)),
	 objectSprite.getGlobalBounds().height / 2.0f - (buttonText.getCharacterSize() / 3.0f * 2.0f));
	buttonText.setPosition(objectSprite.getPosition() + textOffset);
}
void ButtonHandle::textFix()
{
	objectSprite.setScale(1 + (buttonText.getString().getSize() - 1) * 2, objectSprite.getScale().y);
	updateOffset();
}

//Graphics Functions--------------------------------------
void ButtonHandle::draw(WindowHandle* handle)
{
	handle->draw(objectSprite);
	handle->draw(buttonText);
}
bool ButtonHandle::loadTexture(std::string textureName)
{
	textureFileName = textureName;

	if (!objectTexture.loadFromFile(textureName))
		return false;

	objectSprite.setTexture(objectTexture);
	updateOffset();
	return true;
}
