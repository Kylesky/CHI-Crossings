#pragma once

class Level{
private:
	int **map;
public:
	Level();
	~Level();

	void setMap(int **arr);
	int* operator[](int x);
};