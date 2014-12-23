#include "Level.hpp"

Level::Level(){
}

Level::Level(int r, int c, int **arr){
	setMap(r, c, arr);
}

Level::~Level(){
}

void Level::setMap(int r, int c, int **arr){
	rows = r;
	columns = c;
	map = arr;
}

void Level::setCell(int r, int c, int cell){
	map[r][c] = cell;
}

int Level::getCell(int r, int c){
	return map[r][c];
}

int* Level::operator[](int x){
	return map[x];
}

void Level::shutdown(){
	for(int i=0; i<rows; i++){
		delete map[i];
	}
	delete map;
}

void Level::setVtxArray( sf::VertexArray* vtx ){
	this->vtx = vtx;
}

sf::VertexArray* Level::getVtxArray(){
	return vtx;
}

int Level::getRows(){
	return rows;
}

int Level::getCols(){
	return columns;
}

void Level::setTexture(sf::Texture* tex){
	texture = tex;
}

sf::Texture* Level::getTexture(){
	return texture;
}