#pragma once

#include "Entity.hpp"
#include <SFML/Graphics.hpp>

class GraphicsManager{
private:
	static sf::RenderWindow* window;
	//sf::View mapView;
	static Level* level;

public:
	GraphicsManager();
	~GraphicsManager();

	static void initialize(sf::RenderWindow* rw);
	
	static void drawCharacterEntity(CharacterEntity *e);
	static void drawBulletEntity(BulletEntity *e);
	static void drawObjectEntity(ObjectEntity *e);
	static void drawLevel();
	static void clearScreen();
	static void translate(float x, float y);
	static void zoom(float z);
	static void update(float z);
	static void loadLevel();
	static void setQuad(sf::VertexArray* vertices, int quad, int x, int y, int u, int v);
	static void setLevel(Level* l);
};