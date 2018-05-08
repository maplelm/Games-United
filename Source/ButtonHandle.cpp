#include "ButtonHandle.h"

//Cosntructors---------------------------------
ButtonHandle::ButtonHandle(sf::RenderWindow *windowHandle, std::string font)
{
	//setting the target window to draw button on
	WindowPnt = windowHandle;

	//setting origin of text to middle of button text
	buttonText.setOrigin(buttonText.getLocalBounds().width / 2, buttonText.getLocalBounds().height / 2);
	
	//setting origin of background
	background.setOrigin(0, 0);
	
	//change background color
	background.setFillColor(sf::Color::Black);
	background.setOutlineColor(sf::Color::Red);
	background.setOutlineThickness(2.0f);
	
	//Setting default Background size
	background.setSize(sf::Vector2f(100, 30));
	
	//setting text size based on background 
	updateFontSize();

	//update text-background position offset
	updateOffset();

	//setting text font
	loadFont(font);

	ispressed = false;
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
	background.move(x, y);
}
void ButtonHandle::move(sf::Vector2f pos)
{
	objectSprite.move(pos);
	buttonText.move(pos);
	background.move(pos);
}
void ButtonHandle::setPosition(float x, float y)
{
	objectSprite.setPosition(x, y);
	buttonText.setPosition(x + textOffset.x , y + textOffset.y);
	background.setPosition(x, y); 
}
void ButtonHandle::setPosition(sf::Vector2f pos)
{
	objectSprite.setPosition(pos );
	buttonText.setPosition(pos + textOffset);
	background.setPosition(pos);
}
//Theta is in degrees
void ButtonHandle::setRotation(float theta)
{
	objectSprite.setRotation(theta);
	buttonText.setRotation(theta);
	background.setRotation(theta);
}
void ButtonHandle::Rotate(float theta)
{
	objectSprite.rotate(theta);
	buttonText.rotate(theta);
	background.rotate(theta);
}
void ButtonHandle::setScale(float x, float y)
{
	objectSprite.setScale(x, y); 
	buttonText.setScale(x, y);
	background.setScale(x, y);
	updateOffset();
}
void ButtonHandle::setScale(sf::Vector2f scl)
{
	objectSprite.setScale(scl);
	buttonText.setScale(scl);
	background.setScale(scl);
	updateOffset();
	sf::FloatRect rec;
	rec.width = 10;
	rec.height = 10;
	;

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
	updateOffset();
}
void ButtonHandle::setTextStyle(sf::Uint32 style)
{
	buttonText.setStyle(style);
}
void ButtonHandle::setFontSize(float size)
{
	buttonText.setCharacterSize(size);
	updateTextOrigin();
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

void ButtonHandle::textFix()
{
	objectSprite.setScale(buttonText.getString().getSize() * .16, buttonText.getCharacterSize() * 0.0433333);
	updateOffset();
}

//Graphics Functions--------------------------------------
void ButtonHandle::draw(WindowHandle* handle)
{
	handle->draw(background);
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
//Update Functions--------------------------------------
void ButtonHandle::updateTextOrigin()
{
	buttonText.setOrigin(buttonText.getLocalBounds().width / 2, buttonText.getLocalBounds().height / 2);
}
void ButtonHandle::updateOffset()
{
	updateTextOrigin();
	textOffset = sf::Vector2f(background.getGlobalBounds().width / 2, (background.getGlobalBounds().height / 3));
	buttonText.setPosition(background.getPosition() + textOffset);
}
void ButtonHandle::updateFontSize()
{
	buttonText.setCharacterSize(sqrtf(powf(background.getGlobalBounds().width, 2) + powf(background.getLocalBounds().height, 2)) / 6);
	updateOffset();
}

void ButtonHandle::clicked()
{
	Mouse mobj(WindowPnt);
	if (mobj.isWithin(background.getGlobalBounds()) && Mouse::isLeftClicked() && state.triggered == false)
	{
		state.triggered = true;
		std::cout << "button " << ID << "\t triggered: " << state.triggered << std::endl;
	}

}