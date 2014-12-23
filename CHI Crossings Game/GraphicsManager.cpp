#include "GraphicsManager.hpp"
#include "Level.hpp"
#include "Engine.hpp"
#include <iostream>

GraphicsManager::GraphicsManager(sf::RenderWindow* rw){
	window = rw;
	//add views later
	//mapView.setCenter(sf::Vector2f(0,0));
	//mapView.setSize(sf::Vector2f(200,200 ));
	window->setView(mapView);
	worldX = 0;
	worldY = 0;
	worldX2 = 0;
	worldY2 = 0;
}

GraphicsManager::~GraphicsManager(){
}

void GraphicsManager::drawEntity(Entity *e){
	int temp = (int)(((CharacterEntity*)e)->getStateTime()*1);
	e->setTextureRect(sf::IntRect(temp*64, temp*64, 64, 64));
	//std::cout << temp << std::endl;
	//std::cout << ((CharacterEntity*)e)->getStateTime() << std::endl;
	window->draw(*e);
}

void GraphicsManager::drawLevel(Level *l){
	//draw
	window->draw(*(l->getVtxArray()), l->getTexture());
}

void GraphicsManager::loadLevel(Level *l){
	//pre-load xy values to map to textures
	const int cols = l->getCols(); //columns
	const int rows = l->getRows(); //rows

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
			int x = (l->getCell(i, j)) & 15;
			int y = ((l->getCell(i, j)) & (15<<4) ) >> 4;
			(*vertices)[i*cols*4 + j*4].texCoords = sf::Vector2f( x*GRID_SIZE, y*GRID_SIZE );
			(*vertices)[i*cols*4 + j*4+1].texCoords = sf::Vector2f( x*GRID_SIZE + GRID_SIZE, y*GRID_SIZE );
			(*vertices)[i*cols*4 + j*4+2].texCoords = sf::Vector2f( x*GRID_SIZE + GRID_SIZE, y*GRID_SIZE + GRID_SIZE );
			(*vertices)[i*cols*4 + j*4+3].texCoords = sf::Vector2f( x*GRID_SIZE, y*GRID_SIZE + GRID_SIZE );

		}
	}
	l->setVtxArray( vertices );
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
	//worldX2 += z*99;
	mapView.move((int)(worldX2-worldX), (int)(worldY2-worldY));
	worldX = (int)worldX2;
	window->setView(mapView);
	window->display();
}