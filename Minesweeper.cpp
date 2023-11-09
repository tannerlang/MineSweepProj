// Two-Player Minesweeper
#include<SFML/Graphics.hpp>
#include<iostream>
#include<time.h> //for time and date functions from C++ standard library

using namespace sf; //for classes provided by SFML

int main()
{
	srand(time(0));							//RNG function, takes machine time for to generate new random seed.

	RenderWindow MineSweep(VideoMode(400, 400),"Minesweeper");	//initiate window for the game through SFML library.
	
	int w = 32;
	int grid[12][12];
	int sgrid[12][12]; //initializes size of grid.

	Texture tile;
	tile.loadFromFile("images/tiles.jpg");	    //load the tiles image from the repo to be used for the grid
	Sprite Sp(tile);							//SFML library function to draw the texture.

	//populates sgrid two dimensional array to be then be used by SFML to be displayed.
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++) 
		{
			sgrid[i][j] = 10;	


			if (rand() % 5 == 0) //if the random seed is divisible by 5 then set the grid equal to 9
			{
				grid[i][j] = 9;
			}
			else				//otherwise set grid equal to 0
			{
				grid[i][j] = 0;
			}
		}
	}	
	//---------------------------------------------------------
		



	//----------Lay Down Mines---------------------------------
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 1; j <= 10; j++)
		{
			int n = 0;
			if (grid[i][j] == 9) continue;
			if (grid[i + 1][j] == 9) n++;
			if (grid[i][j+1] == 9) n++;
			if (grid[i-1][j] == 9) n++;
			if (grid[i][j-1] == 9) n++;

			if (grid[i+1][j+1] == 9) n++;
			if (grid[i-1][j-1] == 9) n++;
			if (grid[i - 1][j + 1] == 9) n++;
			if (grid[i+1][j-1] == 9) n++;

			grid[i][j] = n;
		}


	}
	//------------------------------
	


	//------------DISPLAY------------//
	while (MineSweep.isOpen())
	{
		Vector2i mous = Mouse::getPosition(MineSweep);	//create a vector from sfml lib called mouse, set it equal to the real time mouse
														//location in the Minesweep window using the sfml getPosition lib function.
		int x = mous.x;
		int y = mous.y;									//initiate x and y vars and set them = to the current coordinates.

		Event ev;
		while (MineSweep.pollEvent(ev))		//checks to see if SFML class Event ev is active, will proceed if true.
		{
			if (ev.type == Event::Closed)
			{
				MineSweep.close();			//closes the MineSweep Window.
			}

			if (ev.type == Event::MouseButtonPressed)	//using sfml, check to see if a mouse button was pressed.
			{
				if (ev.key.code == Mouse::Left)
				{
					sgrid[x][y] = grid[x][y];	//if the left mouse button is clicked, set the sgrid cell spot (blank grid) at... 
												//the mouse coordinates equal to the populated grid to reveal what is in the cell beneath;
				}
				else if (ev.key.code == Mouse::Right)
				{
					sgrid[x][y] = 11;			//if the right button is clicked, set the cell at the mouse coordinates = to 11 (flag);
				}
			}
		}
		
		//builds the grid to be displayed, using SFML library functions and a nested for loop.
		MineSweep.clear(Color::Cyan);
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				/*
				if (sgrid[x][y] == 9)
				{
					sgrid[i][j] = grid[i][j];		//if u land on a mine;
				}
				*/				

				Sp.setTextureRect(IntRect(sgrid[i][j] * w, 0, w, w));
				Sp.setPosition(i * w, j * w);
				MineSweep.draw(Sp);
			}
		}
		//Display the grid!
		MineSweep.display();	//SFML function "display()" by calling it with the...
								//..."MineSweep" object we created using the RenderWindow SFML Class.
	}
	//-----------------------------------------------------------------------

}
