#pragma 
#ifndef GameLoop
#define GameLoop
#include<SFML/Graphics.hpp>

 
class Game
{
private:
	int w = 32;
	int grid[12][12];
	int sgrid[12][12]; //initializes size of grid.

public:
	
	void buildGrid(int grid[][12], int sgrid[][12]);
	void LayMines(int grid[][12], int sgrid[][12]);
	void GameOpen(int grid[][12], int sgrid[][12], int w);
	void play();
};

#endif