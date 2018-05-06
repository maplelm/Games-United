//purpose: to manage all on screen images and make moving things on the GUI much easier
//          Will also come in handy when linking actions to clicks

#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

#include <string>

#include <SFML/Graphics.hpp>

class ScreenObject
{
public:
	//Constructors
	ScreenObject();
	ScreenObject(std::string);

	//Destructor's
	~ScreenObject();

	//Toggle Functions
	void toggleSmooth();
	void toggleRepeated();
	virtual void toggleSelect();
	virtual void toggleMouseHover();
	void toggleVisable();


	//Toggle Queries
	bool isSmooth();
	bool isRepeated();
	bool isSelect();
	bool isMouseHover();
	bool isVisable();

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
	void setSmooth(bool);
	void setRepeated(bool);


	//Getters
	sf::Sprite getSprite();
	sf::Texture getTexture();
	float getRotation();
	sf::Vector2f getScale();

protected:

	//SFML Variables
	sf::Sprite objectSprite;
	sf::Texture objectTexture;
	std::string textureFileName;

	//User Interaction variables
	bool selected;
	bool mouseHover;
	bool visable;

	//Graphics Functions
	bool loadTexture(std::string);

	//Virtual Fucntions
	virtual bool onClick();   // if object is clicked on this function will be called
	virtual bool onRelease(); // if object was clicked on this fucntion will be called apon release
};

#endif // SCREENOBJECT_H
