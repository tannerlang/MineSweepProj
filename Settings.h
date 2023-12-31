#pragma 
#ifndef Settings
#define Settings
#include<SFML/Graphics.hpp>
#include<time.h> //for time and date functions from C++ standard library


	sf::RenderWindow MineSweep(sf::VideoMode(400, 400), "Minesweeper");
	sf::Texture tile;
	sf::Sprite Sp(tile);		//SFML library function to draw the texture.
	sf::Font font;
	sf::Text P1;
	sf::Text P2;
	sf::Text P1Loss;
	sf::Text P2Loss;			//iniated SFML vales to use with displaying the game
	bool Player = 1;			// initiate and declare a bool value to use for toggling between player 1 and two

	class Board
	{
	public:
		int w = 32;
		int grid[12][12];		//hidden cells
		int sgrid[12][12];		//top of hidden cells

		Board();				//initiate constructor



	private:

	};
	Board::Board()				//using constructor definiton, populate cells
	{
		srand(time(0));
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)
			{
				sgrid[i][j] = 10;		//blank tile 


				if (rand() % 5 == 0)	//if the random seed is divisible by 5 then set the grid equal to 9
				{
					grid[i][j] = 9;
				}
				else					//otherwise set grid cell equal to 0
				{
					grid[i][j] = 0;
				}
			}
		}
		//----------Fill Number Cells---------------------------------
		for (int i = 1; i <= 10; i++)
		{
			for (int j = 1; j <= 10; j++)				////checks avery adjacent cell, if there is a bomb adjacent, increments n.
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

				grid[i][j] = n;						//to be used to place the number texture on each respective cell, depending what n sets that cell 
			}										//equal to.
		}
	}

#endif					//to be used to place the number texture on each respective cell, depending what n sets that cell 
			}										//equal to.
		}
	}

#endif
