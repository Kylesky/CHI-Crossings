#pragma once

class Level{
private:
	int rows, columns;
	int **map;
public:
	Level();
	Level(int r, int c, int **arr);
	~Level();

	void setMap(int r, int c, int **arr);
	void setCell(int r, int c, int cell);
	int* operator[](int x);

	void shutdown();
};