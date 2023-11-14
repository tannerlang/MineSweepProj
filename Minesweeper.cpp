// Two - Player Minesweeper
#include<SFML/Graphics.hpp>
#include"Settings.h"

//sf:: scopes classes, data, and functions provided by SFML

//implement two player system in the game loop function somehow, 
void Gameloop(sf::RenderWindow& MineSweep,sf::Sprite& Sp, sf::Texture& tile,Board& b)
{
	sf::Vector2i mous = sf::Mouse::getPosition(MineSweep);	//create a vector from sfml lib called mouse, set it equal to the real time mouse
	//location in the Minesweep window using the sfml getPosition lib function.
	int x = mous.x / b.w;
	int y = mous.y / b.w;									//initiate x and y vars and set them = to the current coordinates.

	sf::Event ev;
	while (MineSweep.pollEvent(ev))		//checks to see if SFML class Event ev is active, will proceed if true.
	{
		if (ev.type == sf::Event::Closed)
		{
			MineSweep.close();			//closes the MineSweep Window.
		}
		//case here for 2 player? or another while????
		if (ev.type == sf::Event::MouseButtonPressed)	//using sfml, check to see if a mouse button was pressed.
		{
			if (ev.key.code == sf::Mouse::Left)
			{
				b.sgrid[x][y] = b.grid[x][y];	//if the left mouse button is clicked, set the sgrid cell spot (blank grid) at... 
				//the mouse coordinates equal to the populated grid to reveal what is in the cell beneath;
			}
			else if (ev.key.code == sf::Mouse::Right)
			{
				b.sgrid[x][y] = 11;			//if the right button is clicked, set the cell at the mouse coordinates = to 11 (flag);
			}
		}
	}
	MineSweep.clear(sf::Color::Cyan);
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{

			if (b.sgrid[x][y] == 9)
			{
				b.sgrid[i][j] = b.grid[i][j];		//if u land on a mine;
			}


			Sp.setTextureRect(sf::IntRect(b.sgrid[i][j] * b.w, 0, b.w, b.w));
			Sp.setPosition(i * b.w, j * b.w);
			MineSweep.draw(Sp);
		}
	}
}

int main()
{
	Board b;
	tile.loadFromFile("images/tiles.jpg");	    //load the tiles image from the repo to be used for the grid
	
	
	//----------------------------------------GAMELOOP----------------------------------------------
	while (MineSweep.isOpen())				
	{
		Gameloop(MineSweep,Sp, tile,b);
		MineSweep.display();	//SFML function "display()" by calling it with the "MineSweep" object we created using the RenderWindow SFML Class.
	}
	
}
