#pragma once

#define GRID_SIZE 64.0;
#include <SFML\Graphics.hpp>

class Level{
private:
	int rows, columns;
	int **map;
	sf::Texture *texture;
public:
	Level();
	Level(int r, int c, int **arr);
	~Level();

	void setMap(int r, int c, int **arr);
	void setCell(int r, int c, int cell);
	int* operator[](int x);

	void shutdown();

	void setTexture(sf::Texture* tex);
	sf::Texture* getTexture();
};