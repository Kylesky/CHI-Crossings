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
	Level(int r, int c);
	Level(int r, int c, int **arr);
	~Level();

	void setMap(int r, int c, int **arr);
	void setCell(int r, int c, int cell);
	void setWorldXY(float x, float y);
	void moveWorld(float dx, float dy);
	void setCellPassable(int r, int c, bool b);
	void setCellSlower(int r, int c, bool b);
	void setCellSpikeLeft(int r, int c, bool b);
	void setCellSpikeRight(int r, int c, bool b);
	void setCellSpikeTop(int r, int c, bool b);
	void setCellSpikeBottom(int r, int c, bool b);
	void setCellUV(int r, int c, int u, int v);

	int getCell(int r, int c);
	float getWorldX();
	float getWorldY();
	bool isCellPassable(int r, int c);
	bool isCellSlower(int r, int c);
	bool isCellSpikeLeft(int r, int c);
	bool isCellSpikeRight(int r, int c);
	bool isCellSpikeTop(int r, int c);
	bool isCellSpikeBottom(int r, int c);

	void setVtxArray( sf::VertexArray* vtx );
	sf::VertexArray* getVtxArray();

	void shutdown();

	int getRows();
	int getCols();

	void setTexture(sf::Texture* tex);
	sf::Texture* getTexture();
};