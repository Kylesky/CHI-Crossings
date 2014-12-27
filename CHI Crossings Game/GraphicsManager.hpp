#pragma once

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class GraphicsManager{
private:
	sf::RenderWindow* window;
	sf::View mapView;
	Level* level;
public:
	GraphicsManager(sf::RenderWindow* rw);
	~GraphicsManager();

	void drawEntity(Entity *e);
	void drawLevel();
	void clearScreen();
	void translate(float x, float y);
	void zoom(float z);
	void update(float z);
	void loadLevel();
	void setLevel(Level* l);
};