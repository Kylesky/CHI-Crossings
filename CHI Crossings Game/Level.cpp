#include "Level.hpp"

Level::Level(){
}

Level::Level(int r, int c){
	int **map = new int*[r];
	for(int i=0; i<r; i++){
		map[i] = new int[c];
		for(int j=0; j<c; j++){
			map[i][j] = 0;
		}
	}
	setMap(r, c, map);
	setWorldXY(448, r*GRID_SIZE/2);
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

void Level::setCellPassable(int r, int c, bool b){
	if((map[r][c] & (1<<8)) != b){
		map[r][c] ^= (1<<8);
	}
}

void Level::setCellSlower(int r, int c, bool b){
	if((map[r][c] & (1<<9)) != b){
		map[r][c] ^= (1<<9);
	}
}

void Level::setCellSpikeLeft(int r, int c, bool b){
	if((map[r][c] & (1<<12)) != b){
		map[r][c] ^= (1<<12);
	}
}

void Level::setCellSpikeRight(int r, int c, bool b){
	if((map[r][c] & (1<<13)) != b){
		map[r][c] ^= (1<<13);
	}
}

void Level::setCellSpikeTop(int r, int c, bool b){
	if((map[r][c] & (1<<14)) != b){
		map[r][c] ^= (1<<14);
	}
}

void Level::setCellSpikeBottom(int r, int c, bool b){
	if((map[r][c] & (1<<15)) != b){
		map[r][c] ^= (1<<15);
	}
}

void Level::setCellUV(int r, int c, int u, int v){
	map[r][c] &= ~((1<<8)-1);
	map[r][c] |= ((v<<4)|u);
}

bool Level::isCellPassable(int r, int c){
	return (map[r][c] & (1<<8)) != 0;
}

bool Level::isCellSlower(int r, int c){
	return (map[r][c] & (1<<9)) != 0;
}

bool Level::isCellSpikeLeft(int r, int c){
	return (map[r][c] & (1<<12)) != 0;
}

bool Level::isCellSpikeRight(int r, int c){
	return (map[r][c] & (1<<13)) != 0;
}

bool Level::isCellSpikeTop(int r, int c){
	return (map[r][c] & (1<<14)) != 0;
}

bool Level::isCellSpikeBottom(int r, int c){
	return (map[r][c] & (1<<15)) != 0;
}