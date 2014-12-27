#include "GraphicsManager.hpp"
#include "Level.hpp"
#include "Engine.hpp"
#include <iostream>

GraphicsManager::GraphicsManager(sf::RenderWindow* rw){
	window = rw;
	//add views later
	//mapView.setCenter(sf::Vector2f(0,0));
	//mapView.setSize(sf::Vector2f(200,200 ));
	//window->setView(mapView);
}

GraphicsManager::~GraphicsManager(){
}

void GraphicsManager::drawEntity(Entity *e){
	int temp = (int)(((CharacterEntity*)e)->getStateTime()*1);
	e->setTextureRect(sf::IntRect(temp*64, temp*64, 64, 64));
	e->setScale(0.75, 0.75);
	sf::View v = window->getDefaultView();
	v.setCenter((int)(level->getWorldX()), (int)(level->getWorldY()));
	window->setView(v);
	window->draw(*e);
	window->setView(window->getDefaultView());
}

void GraphicsManager::drawLevel(){
	//draw
	sf::View v = window->getDefaultView();
	v.setCenter((int)(level->getWorldX()), (int)(level->getWorldY()));
	window->setView(v);
	window->draw(*(level->getVtxArray()), level->getTexture());
	window->setView(window->getDefaultView());
}

void GraphicsManager::loadLevel(){
	//pre-load xy values to map to textures
	const int cols = level->getCols(); //columns
	const int rows = level->getRows(); //rows

	//use sf::Quads
	sf::VertexArray* vertices = new sf::VertexArray( sf::Quads, cols*rows*4 );
	for( int i = 0; i < rows; ++i ){
		for( int j = 0; j < cols; ++j ){
			//XY
			(*vertices)[i*cols*4 + j*4].position = sf::Vector2f( j*GRID_SIZE-1, i*GRID_SIZE-1 );
			(*vertices)[i*cols*4 + j*4+1].position = sf::Vector2f( j*GRID_SIZE + GRID_SIZE+1, i*GRID_SIZE-1 );
			(*vertices)[i*cols*4 + j*4+2].position = sf::Vector2f( j*GRID_SIZE + GRID_SIZE+1, i*GRID_SIZE + GRID_SIZE+1 );
			(*vertices)[i*cols*4 + j*4+3].position = sf::Vector2f( j*GRID_SIZE-1, i*GRID_SIZE + GRID_SIZE+1 );

			//UV
			int x = (level->getCell(i, j)) & 15;
			int y = ((level->getCell(i, j)) & (15<<4) ) >> 4;
			(*vertices)[i*cols*4 + j*4].texCoords = sf::Vector2f( x*GRID_SIZE, y*GRID_SIZE );
			(*vertices)[i*cols*4 + j*4+1].texCoords = sf::Vector2f( x*GRID_SIZE + GRID_SIZE, y*GRID_SIZE );
			(*vertices)[i*cols*4 + j*4+2].texCoords = sf::Vector2f( x*GRID_SIZE + GRID_SIZE, y*GRID_SIZE + GRID_SIZE );
			(*vertices)[i*cols*4 + j*4+3].texCoords = sf::Vector2f( x*GRID_SIZE, y*GRID_SIZE + GRID_SIZE );

		}
	}
	level->setVtxArray( vertices );
}

void GraphicsManager::clearScreen(){
	window->clear(sf::Color::Black);
}

void GraphicsManager::translate(float x, float y){
	mapView.move(x,y);
}

void GraphicsManager::zoom(float z){
	mapView.zoom(z);
}

void GraphicsManager::update(float z){
	window->display();
}

void GraphicsManager::setLevel(Level* l){
	level = l;
}