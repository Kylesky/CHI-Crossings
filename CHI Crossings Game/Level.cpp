#include "Level.hpp"

Level::Level(){
}

Level::~Level(){
}

void Level::setMap(int **arr){
	map = arr;
}

int* Level::operator[](int x){
	return map[x];
}