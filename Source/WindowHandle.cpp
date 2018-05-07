#include "WindowHandle.h"

//Constructors--------------------------------------------
WindowHandle::WindowHandle()
{
	winHandle.create(sf::VideoMode(400, 300), "Window");
	visable = true;
	vsync = false;
	winHandle.setVerticalSyncEnabled(vsync);
}
WindowHandle::WindowHandle(sf::VideoMode vm)
{
	winHandle.create(vm, "Window");
	visable = true;
	vsync = false;
	winHandle.setVerticalSyncEnabled(vsync);
}
WindowHandle::WindowHandle(sf::VideoMode vm, std::string name)
{
	winHandle.create(vm, name);
	visable = true;
	vsync = false;
	winHandle.setVerticalSyncEnabled(vsync);
}

//Destructor's------------------------------------------
WindowHandle::~WindowHandle()
{
	//destructor stuff
}
//Toggle Functions-------------------------------------------
void WindowHandle::toggleVisable()
{
	if (visable)
	{
		visable = false;
		winHandle.setVisible(visable);
	}
	else
	{
		visable = true;
		winHandle.setVisible(visable);
	}
}
void WindowHandle::toggleVsync()
{
	if (vsync)
	{
		vsync = false;
		winHandle.setVerticalSyncEnabled(vsync);
	}
	else
	{
		vsync = true;
		winHandle.setVerticalSyncEnabled(vsync);
	}
}
//Toggle Query State Functions------------------------------------
bool WindowHandle::isVisable()
{
	return visable;
}
bool WindowHandle::isVsync()
{
	return vsync;
}
//Getters--------------------------------------------------
bool WindowHandle::isOpen()
{
	return winHandle.isOpen();
}
//Basic Window Functions-------------------------------------------
void WindowHandle::draw(sf::Sprite spr)
{
	winHandle.draw(spr);
}
void WindowHandle::draw(sf::Text txt)
{
	winHandle.draw(txt);
}
bool WindowHandle::pollEvent(sf::Event &e)
{
	return winHandle.pollEvent(e);
}
void WindowHandle::close()
{
	winHandle.close();
}
sf::RenderWindow *WindowHandle::getRenderWindow()
{
	return &winHandle;
}
void WindowHandle::clear(sf::Color color = sf::Color(0,0,0,255))
{
	winHandle.clear(color);
}
void WindowHandle::display()
{
	winHandle.display();
}