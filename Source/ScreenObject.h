//purpose: to manage all on screen images and make moving things on the GUI much easier
//          Will also come in handy when linking actions to clicks

#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <string>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "WindowHandle.h"
#include "Mouse.h"

//States Struct
struct states
{
	bool disabled = false;
	bool visable = true;
	bool mouseOver = false;
	bool triggered = false;
};

class ScreenObject
{
public:
	//Constructors
	ScreenObject();
	ScreenObject(int);
	ScreenObject(int, sf::RenderWindow *);
	ScreenObject(int,sf::RenderWindow *, std::string);

	//Destructor's
	~ScreenObject();

	//Toggle Functions
	void toggleSmooth();
	void toggleRepeated();
	virtual void toggleTriggered();
	void toggleVisable();
	void toggleDisable();
	void toggleMouseOver();

	//Toggle Queries
	bool isSmooth();
	bool isRepeated();
	bool isTriggered();
	bool isMouseOver();
	bool isVisable();
	bool isDisabled();

	//states struct
	states state;

	//Graphics Functions
	virtual void draw();

	//Manipulation Functions
	virtual void move(float x, float y);
	virtual void move(sf::Vector2f);
	virtual void setPosition(float x, float y);
	virtual void setPosition(sf::Vector2f);
	virtual void setRotation(float);
	virtual void Rotate(float);
	virtual void setScale(float, float);
	virtual void setScale(sf::Vector2f);

	//Setters
	void setSprite(sf::Sprite);
	void setTexture(std::string);
	void setSelected(bool);
	void setVisable(bool);
	void setDisable(bool);
	void setmouseOver(bool);
	void setSmooth(bool);
	void setRepeated(bool);
	void setTargetWindow(sf::RenderWindow *);


	//Getters
	sf::Sprite getSprite();
	sf::Texture getTexture();
	float getRotation();
	sf::Vector2f getScale();
	sf::RenderWindow * getTargetWindow();

	//User Interaction
	virtual void clicked(sf::RenderWindow*);

protected:

	int ID;
	//SFML Variables
	sf::Sprite objectSprite;
	sf::Texture objectTexture;
	std::string textureFileName;
	sf::RenderWindow * WindowPnt; //pointer to the window the button should be drawn two

	//Graphics Functions
	virtual bool loadTexture(std::string);


	
};

#endif // SCREENOBJECT_H
