#ifndef BUTTONHANDLE_H
#define BUTTONHANDLE_H

#include <string>

#include "ScreenObject.h"

class ButtonHandle : public ScreenObject
{
public:
	//Constructors
	ButtonHandle();

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

	//Getters
	std::string getText();
	sf::Vector2f getTextOffset();

	//Setters
	void setTextXOffset(float,float);
	void setTextYoffset(sf::Vector2f);
	void setText();
	void setTextColor();
	void setTextStyle();

private:

	//Text Based Functions
	void loadFont(std::string);

	sf::Text buttonText;
	sf::Font buttonFont;

	sf::Vector2f textOffset;
};

#endif //BUTTONHANDLE_H