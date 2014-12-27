#include "Level.hpp"

Level::Level(){
}

Level::Level(int r, int c, int **arr){
	setMap(r, c, arr);
	setWorldXY(448, r*GRID_SIZE/2);
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

void Level::setWorldXY(float x, float y){
	worldX = x;
	worldY = y;
}

void Level::moveWorld(float dx, float dy){
	worldX += dx;
	worldY += dy;
}

int Level::getCell(int r, int c){
	return map[r][c];
}

float Level::getWorldX(){
	return worldX;
}

float Level::getWorldY(){
	return worldY;
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