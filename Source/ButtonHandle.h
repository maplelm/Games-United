#ifndef BUTTONHANDLE_H
#define BUTTONHANDLE_H

#include <string>

#include <iostream>

#include "ScreenObject.h"

class ButtonHandle : public ScreenObject
{
public:
	//Constructors
	ButtonHandle(std::string, std::string);

	//Destructor's
	~ButtonHandle();

	//manipulation Functions
	void move(float, float);
	void move(sf::Vector2f);
	void setPosition(float, float);
	void setPosition(sf::Vector2f);
	void setRotation(float);
	void Rotate(float);
	void setScale(float, float);
	void setScale(sf::Vector2f);
	void setTextureScale(sf::Vector2f);

	//Graphics Functions
	void draw(WindowHandle*);
	
	//Getters
	std::string getText();
	sf::Vector2f getTextOffset();
	int getFontSize();

	//Setters
	void setTextOffset(float,float);
	void setTextOffset(sf::Vector2f);
	void setText(std::string);
	void setTextStyle(sf::Uint32);
	void setFontSize(float);

private:

	//Graphics Functions
	bool loadTexture(std::string);

	//Text Based Functions
	void loadFont(std::string);
	void updateOffset();
	void textFix();

	sf::Text buttonText;
	sf::Font buttonFont;

	sf::Vector2f textOffset;
};

#endif //BUTTONHANDLE_H