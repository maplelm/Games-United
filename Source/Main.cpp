//Standard C++ includes
#include <fstream>
#include <string.h>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>

//API Includes
#include <SFML/Graphics.hpp>

//Other Includes
//#include "ScreenObjects.h"

//prototypes

int main()
{

	// Create the main window 3/4 the size of the monitors resolution
	sf::RenderWindow mainApp(sf::VideoMode(sf::VideoMode::getDesktopMode().width / 4 * 3,   // sets the width of the window to 3/4 the size of the monitor's width
		sf::VideoMode::getDesktopMode().height / 4 * 3),									// sets the height of the window to 3/4 the size of the monitor's height
		"PC Console");	                                                                    // sets the title of the window
	sf::Sprite sprite;
	sf::Texture texture;
	texture.loadFromFile("cb.bmp");
	sprite.setTexture(texture);

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

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			sf::Vector2i pos = sf::Mouse::getPosition(mainApp);
			//sf::Mouse::setPosition(sf::Vector2i(100, 200), mainApp);
			std::cout << pos.x << ", " << pos.y << std::endl;
		}


		// Clear screen
		mainApp.clear();

		//draw stuff
		mainApp.draw(sprite);

		// Update the window
		mainApp.display();
	}

	return EXIT_SUCCESS;
}

