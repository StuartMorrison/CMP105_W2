#include "Level.h"
#include <cmath>

int oldX, oldY, newX, newY, distance = 0, squaredD = 0, x, y;

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
		std::cout << "W was pressed.\n";
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);

		std::cout << "J,k and L was pressed.\n";

	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		input->setKeyUp(sf::Keyboard::Escape);
		window->close();
	}

	if (input->isMouseLDown())
	{
		
		newX = x;
		newY = y;
		
	}

	if (!input->isMouseLDown())
	{
		oldX = x;
		oldY = y;

	}

	
}

// Update game objects
void Level::update()
{

	distance = ((newX - oldX) * (newX - oldX)) + ((newY - oldY) * (newY - oldY));

	squaredD = sqrt(distance);
	

}

// Render level
void Level::render()
{
	
	beginDraw();

	//render text
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}

	x = input->getMouseX();
	y = input->getMouseY();

	std::string xVal = std::to_string(x);
	std::string yVal = std::to_string(y);
	std::string dVal = std::to_string(squaredD);

	text.setFont(font);
	text.setString(xVal + ", " + yVal);
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setPosition(0, 0);

	if (input->isMouseLDown())
	{
		displayDist.setFont(font);
		displayDist.setString(dVal);
		displayDist.setCharacterSize(24);
		displayDist.setFillColor(sf::Color::Red);
		displayDist.setPosition(0, 25);
	}

	
	window->draw(text);
	window->draw(displayDist);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}