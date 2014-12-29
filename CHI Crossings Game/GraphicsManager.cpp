#include "GraphicsManager.hpp"
#include "Level.hpp"
#include "Engine.hpp"
#include <iostream>

sf::RenderWindow* GraphicsManager::window = NULL;
Level* GraphicsManager::level = NULL;

GraphicsManager::GraphicsManager(){
}

GraphicsManager::~GraphicsManager(){
}

void GraphicsManager::initialize(sf::RenderWindow* rw){
	window = rw;
}

void GraphicsManager::drawCharacterEntity(CharacterEntity *e){
	int temp = ((int)(e->getStateTime()*10))%4;
	e->setTextureRect(sf::IntRect(temp*64, (e->getState()%2)*64, 64, 64));
	sf::View v = window->getDefaultView();
	v.setCenter(level->getWorldX(), level->getWorldY());
	window->setView(v);
	window->draw(*e);
	window->setView(window->getDefaultView());
}

void GraphicsManager::drawBulletEntity(BulletEntity *e){
}

void GraphicsManager::drawObjectEntity(ObjectEntity *e){
}

void GraphicsManager::drawLevel(){
	//draw
	sf::View v = window->getDefaultView();
	v.setCenter(level->getWorldX(), level->getWorldY());
	window->setView(v);
	window->draw(*(level->getVtxArray()), level->getTexture());
	window->setView(window->getDefaultView());
}

void GraphicsManager::loadLevel(){
	//pre-load xy values to map to textures
	const int cols = level->getCols(); //columns
	const int rows = level->getRows(); //rows

	//use sf::Quads
	int quadCount = cols*rows;
	for(int i=0; i<rows; i++){
		for(int j=0; j<cols; j++){
			if(level->isCellSlower(i, j)) quadCount++;
			if(level->isCellSpikeTop(i, j)) quadCount++;
			if(level->isCellSpikeBottom(i, j)) quadCount++;
			if(level->isCellSpikeLeft(i, j)) quadCount++;
			if(level->isCellSpikeRight(i, j)) quadCount++;
		}
	}
	sf::VertexArray* vertices = new sf::VertexArray( sf::Quads, quadCount*4 );

	int curQuad = 0;
	for( int i = 0; i < rows; ++i ){
		for( int j = 0; j < cols; ++j ){
			int x = (level->getCell(i, j)) & 15;
			int y = ((level->getCell(i, j)) & (15<<4) ) >> 4;
			setQuad(vertices, curQuad++, j, i, x, y);
			
			if(level->isCellSlower(i, j)){
				setQuad(vertices, curQuad++, j, i, 0, 2);
			}
			if(level->isCellSpikeTop(i, j)){
				setQuad(vertices, curQuad++, j, i, 0, 3);
			}
			if(level->isCellSpikeBottom(i, j)){
				setQuad(vertices, curQuad++, j, i, 1, 3);
			}
			if(level->isCellSpikeLeft(i, j)){
				setQuad(vertices, curQuad++, j, i, 2, 3);
			}
			if(level->isCellSpikeRight(i, j)){
				setQuad(vertices, curQuad++, j, i, 3, 3);
			}
		}
	}
	level->setVtxArray( vertices );
}

void GraphicsManager::setQuad(sf::VertexArray* vertices, int quad, int x, int y, int u, int v){
	(*vertices)[quad*4].position = sf::Vector2f( x*GRID_SIZE-1, y*GRID_SIZE-1 );
	(*vertices)[quad*4+1].position = sf::Vector2f( x*GRID_SIZE + GRID_SIZE+1, y*GRID_SIZE-1 );
	(*vertices)[quad*4+2].position = sf::Vector2f( x*GRID_SIZE + GRID_SIZE+1, y*GRID_SIZE + GRID_SIZE+1 );
	(*vertices)[quad*4+3].position = sf::Vector2f( x*GRID_SIZE-1, y*GRID_SIZE + GRID_SIZE+1 );

	(*vertices)[quad*4].texCoords = sf::Vector2f( u*GRID_SIZE, v*GRID_SIZE );
	(*vertices)[quad*4+1].texCoords = sf::Vector2f( u*GRID_SIZE + GRID_SIZE - 1, v*GRID_SIZE );
	(*vertices)[quad*4+2].texCoords = sf::Vector2f( u*GRID_SIZE + GRID_SIZE - 1, v*GRID_SIZE + GRID_SIZE - 1);
	(*vertices)[quad*4+3].texCoords = sf::Vector2f( u*GRID_SIZE, v*GRID_SIZE + GRID_SIZE - 1);
}

void GraphicsManager::clearScreen(){
	window->clear(sf::Color::White);
}

void GraphicsManager::translate(float x, float y){
	sf::View v = window->getView();
	v.move(x, y);
	window->setView(v);
}

void GraphicsManager::zoom(float z){
	sf::View v = window->getView();
	v.zoom(z);
	window->setView(v);
}

void GraphicsManager::update(float z){
	window->display();
}

void GraphicsManager::setLevel(Level* l){
	level = l;
}