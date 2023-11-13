#pragma 
#ifndef Settings
#define Settings
#include<SFML/Graphics.hpp>

int w = 32;
int grid[12][12]; //hidden cells
int sgrid[12][12]; //top of hidden cells

sf::RenderWindow MineSweep(sf::VideoMode(400, 400), "Minesweeper");
sf::Texture tile;
sf::Sprite Sp(tile);							//SFML library function to draw the texture.

#endif