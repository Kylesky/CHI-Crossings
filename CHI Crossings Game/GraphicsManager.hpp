#pragma once

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class GraphicsManager{
private:
	sf::RenderWindow* window;
	sf::View mapView;
public:
	GraphicsManager(sf::RenderWindow* rw);
	~GraphicsManager();

	void drawEntity(Entity *e);
	void drawLevel(Level* l);
	void clearScreen();
	void translate(float x, float y);
	void zoom(float z);
	void update();
};