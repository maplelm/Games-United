#ifndef WINDOWHANDLE_H
#define WINDOWHANDLE_H

#include <SFML\Graphics.hpp>

class WindowHandle
{
public:
	WindowHandle();
	WindowHandle(sf::VideoMode);
	WindowHandle(sf::VideoMode,std::string);
	~WindowHandle();

	//Toggle Functions
	void toggleVisable();
	void toggleVsync();

	//Query Toggle State Functions
	bool isVisable();
	bool isVsync();

	//Getters
	bool isOpen();

	//Basic Window Functions
	void draw(sf::Sprite);
	bool pollEvent(sf::Event &e);
	void close();
	sf::RenderWindow *getRenderWindow();
	void clear();
	void display();
	
	

private:

	bool visable;
	bool vsync;

	//sfml renderwindow object
	sf::RenderWindow winHandle;
};


#endif //WINDOWHANDLE_H
