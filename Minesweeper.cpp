// Two - Player Minesweeper
#include<iostream>
#include<SFML/Graphics.hpp>
#include"Settings.h"

//gameloop function definition handles all of the sfml events and takes both SFML and standard library parameters to work together to run the game
void Gameloop(sf::RenderWindow& MineSweep,sf::Sprite& Sp, sf::Texture& tile,Board& b, sf::Font& font, sf::Text& P1, sf::Text& P2,sf::Text& P1Loss, sf::Text& P2Loss, bool& Player)
{
	sf::Vector2i mous = sf::Mouse::getPosition(MineSweep);	//create a vector from sfml lib called mouse, set it equal to the real time mouse
															//location in the Minesweep window using the sfml getPosition lib function.
	int x = mous.x / b.w;
	int y = mous.y / b.w;				//initiate x and y vars and set them = to the current coordinates.
	sf::Event ev;						//builds an object for the SFML Event class.

	while (MineSweep.pollEvent(ev))		//checks to see if SFML class Event ev is active, will proceed if true.
	{
		
		if (ev.type == sf::Event::Closed)
		{
			MineSweep.close();			//closes the MineSweep Window.
		}
		
		if (ev.type == sf::Event::MouseButtonPressed)	//using sfml, check to see if a mouse button was pressed.
		{
			if (ev.key.code == sf::Mouse::Left)
			{
				b.sgrid[x][y] = b.grid[x][y];			//if the left mouse button is clicked, set the sgrid cell spot (blank grid) at... 
														//the mouse coordinates equal to the populated grid to reveal what is in the cell beneath;							
				switch (Player)							
				{
				case 1:
					Player = 0;
					break;								//if the left mouse is clicked switch the Player value.

				case 0:
					Player = 1;
					break;
				}
			}
			else if (ev.key.code == sf::Mouse::Right)
			{
				b.sgrid[x][y] = 11;						//if the right button is clicked, set the cell at the mouse coordinates = to 11 (flag);
			}
		}
	}
	
	MineSweep.clear(sf::Color::Cyan);
	if (Player == 1)
	{
		MineSweep.draw(P1);
	}
	else if(Player == 0)
	{
		MineSweep.draw(P2);								//displays player turn at the bottom of the window.
	}

	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{

			if (b.sgrid[x][y] == 9)
			{
				b.sgrid[i][j] = b.grid[i][j];			//if u land on a mine;

				if (Player == 1)
				{
					MineSweep.draw(P2Loss);				//displays if P1 lost the game on the mine clicked
					P1.setFillColor(sf::Color::Cyan);	//"deletes" the player text from the window
				}
				else if(Player == 0)
				{
					MineSweep.draw(P1Loss);				//displays if P2 lost the game on clicked
					P2.setFillColor(sf::Color::Cyan);	//"deletes" the player text from the window
				}
			}

			Sp.setTextureRect(sf::IntRect(b.sgrid[i][j] * b.w, 0, b.w, b.w));	
			Sp.setPosition(i * b.w, j * b.w);
			MineSweep.draw(Sp);							//using the sprite variable 'sp' that uses the tile image for texture, draws the images									
		}												//of the respecive tile and whats on them.
	}
}

int main()
{ 
	Board b;
	 
	tile.loadFromFile("images/tiles.jpg");	    //load the tiles image from the repo to be used for the grid

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Error Loading File";
	}
	
	P1.setFont(font);						//the following 4 blocks of code use sfml Text classes to create text 
	P1.setString("Player 1");				//to be displayed on the render window called MineSweep
	P1.setCharacterSize(30);
	P1.setFillColor(sf::Color::Black);
	P1.setStyle(sf::Text::Bold);
	P1.setPosition(130,350);


	P2.setFont(font);
	P2.setFont(font);
	P2.setString("Player 2");
	P2.setCharacterSize(30);
	P2.setFillColor(sf::Color::Black);
	P2.setStyle(sf::Text::Bold);
	P2.setPosition(130, 350);

	P1Loss.setFont(font);
	P1Loss.setFont(font);
	P1Loss.setString("Player 1 Lost!");
	P1Loss.setCharacterSize(30);
	P1Loss.setFillColor(sf::Color::Black);
	P1Loss.setStyle(sf::Text::Bold);
	P1Loss.setPosition(0, 0);

	P2Loss.setFont(font);
	P2Loss.setFont(font);
	P2Loss.setString("Player 2 Lost!");
	P2Loss.setCharacterSize(30);
	P2Loss.setFillColor(sf::Color::Black);
	P2Loss.setStyle(sf::Text::Bold);
	P2Loss.setPosition(0, 0);
	
	
	//----------------------------------------GAMELOOP----------------------------------------------
	while (MineSweep.isOpen())				
	{
		Gameloop(MineSweep,Sp,tile,b,font,P1,P2,P1Loss,P2Loss, Player); //argument contains the render window, sprite, texture, Board object, font, text objects, and bool value to toggle.
		MineSweep.display();	//SFML function "display()" by calling it with the "MineSweep" object we created using the RenderWindow SFML Class.
	}
	
}
