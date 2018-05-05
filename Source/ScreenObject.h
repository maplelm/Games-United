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

	//Destructor's
	~ScreenObject();

	//Toggle Functions
	void toggleSmooth();
	void toggleRepeated();
	void toggleSelect();


	//Toggle Queries
	bool isSmooth();
	bool isRepeated();
	bool isSelect();

	//Manipulation Functions
	void moveSprite(float x, float y);
	void moveSprite(sf::Vector2f);
	void setPosition(float x, float y);
	void setRotation(float);
	void Rotate(float);
	void setScale(float, float);

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

private:

	//SFML Variables
	sf::Sprite objectSprite;
	sf::Texture objectTexture;
	std::string textureFileName;

	//User Interaction variables
	bool selected;

	//Graphics Functions
	bool loadTexture(std::string);

	//User Interaction Fucntions
	//virtual bool onClick() = 0;   // if object is clicked on this function will be called
	//virtual bool onRelease() = 0; // if object was clicked on this fucntion will be called apon release
};

#endif // SCREENOBJECT_H
