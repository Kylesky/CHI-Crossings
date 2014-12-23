#include "GraphicsManager.hpp"

GraphicsManager::GraphicsManager(sf::RenderWindow* rw){
	window = rw;
	//add views later
	mapView.setCenter(sf::Vector2f(0,0));
	mapView.setSize(sf::Vector2f(200,200));
	window->setView(mapView);
}

GraphicsManager::~GraphicsManager(){
}

void GraphicsManager::drawEntity(Entity *e){
	window->draw(*e);
}

void GraphicsManager::drawLevel(Level *l){
	//draw
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

void GraphicsManager::update(){
	window->display();
}