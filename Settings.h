#pragma 
#ifndef Settings
#define Settings
#include<SFML/Graphics.hpp>
#include<time.h> //for time and date functions from C++ standard library


	sf::RenderWindow MineSweep(sf::VideoMode(400, 400), "Minesweeper");
	sf::Texture tile;
	sf::Sprite Sp(tile);							//SFML library function to draw the texture.

	class Board
	{
	public:
		int w = 32;
		int grid[12][12]; //hidden cells
		int sgrid[12][12]; //top of hidden cells

		Board(); //initiate constructor



	private:

	};
	Board::Board() //using constructor definiton, populate cells
	{
		srand(time(0));
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
		//----------Fill Number Cells---------------------------------
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				int n = 0;
				if (grid[i][j] == 9) continue;
				if (grid[i + 1][j] == 9) n++;
				if (grid[i][j + 1] == 9) n++;
				if (grid[i - 1][j] == 9) n++;
				if (grid[i][j - 1] == 9) n++;

				if (grid[i + 1][j + 1] == 9) n++;
				if (grid[i - 1][j - 1] == 9) n++;
				if (grid[i - 1][j + 1] == 9) n++;
				if (grid[i + 1][j - 1] == 9) n++;

				grid[i][j] = n;
			}
		}
	}

#endif
