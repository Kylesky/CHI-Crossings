#pragma once

#define GRID_SIZE 64.0f
#include <SFML\Graphics.hpp>

class Level{
private:
	int rows, columns;
	int **map;
	sf::Texture* texture;
	sf::VertexArray* vtx;
public:
	Level();
	Level(int r, int c, int **arr);
	~Level();

	void setMap(int r, int c, int **arr);
	void setCell(int r, int c, int cell);
	int getCell(int r, int c);
	int* operator[](int x);

	void setVtxArray( sf::VertexArray* vtx );
	sf::VertexArray* getVtxArray();

	void shutdown();

	int getRows();
	int getCols();

	void setTexture(sf::Texture* tex);
	sf::Texture* getTexture();
};