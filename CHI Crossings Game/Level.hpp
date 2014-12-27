#pragma once

#define GRID_SIZE 64.0f
#include <SFML\Graphics.hpp>

class Level{
private:
	int rows, columns;
	int **map;
	float worldX, worldY;
	sf::Texture* texture;
	sf::VertexArray* vtx;
public:
	Level();
	Level(int r, int c, int **arr);
	~Level();

	void setMap(int r, int c, int **arr);
	void setCell(int r, int c, int cell);
	void setWorldXY(float x, float y);
	void moveWorld(float dx, float dy);

	int getCell(int r, int c);
	float getWorldX();
	float getWorldY();

	void setVtxArray( sf::VertexArray* vtx );
	sf::VertexArray* getVtxArray();

	void shutdown();

	int getRows();
	int getCols();

	void setTexture(sf::Texture* tex);
	sf::Texture* getTexture();
};