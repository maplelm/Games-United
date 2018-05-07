//Standard C++ includes
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <stdlib.h>

//API Includes

//Other Includes
#include "ScreenObject.h"
#include "WindowHandle.h"
#include "Mouse.h"
#include "ButtonHandle.h"

//prototypes
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}


int main(int argc, char* argv[])
{

	// Create the main window 3/4 the size of the monitors resolution
	WindowHandle mainApp(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 4 * 3,   // sets the width of the window to 3/4 the size of the monitor's width
		sf::VideoMode::getDesktopMode().height / 4 * 3),									// sets the height of the window to 3/4 the size of the monitor's height
		"PC Console");	                                                                    // sets the title of the window
	ScreenObject obj;
	obj.setTexture("Resources\\Images\\cb.bmp");

	ButtonHandle btn("Resources\\Images\\outlineButton.png", "Resources\\Fonts\\arial.ttf");
	btn.setText("Quit");
	btn.setPosition(sf::Vector2f(300,300));
	btn.setFontSize(30.0f);
	

	// While main Window is up
	while (mainApp.isOpen())
	{
		// Process events
		sf::Event event;
		while (mainApp.pollEvent(event))
		{
			// Close window : exit
			if (event.type == sf::Event::Closed)
				mainApp.close();
		}

		if (Mouse::isLeftClicked())
		{
			sf::Vector2i pos = Mouse::getLocalPos(mainApp.getRenderWindow());
			Mouse::setLocalPos(pos, mainApp.getRenderWindow());
			//std::cout << pos.x << ", " << pos.y << std::endl;
		}


		// Clear screen
		mainApp.clear(sf::Color::Blue);

		//draw stuff
		mainApp.draw(obj.getSprite());
		btn.draw(&mainApp); 

		// Update the window
		mainApp.display();
	}

	return EXIT_SUCCESS;
}

