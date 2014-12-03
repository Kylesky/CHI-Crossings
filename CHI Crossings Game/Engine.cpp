#include "Engine.h"

sf::Time frameRate;
sf::Time curTime;
sf::Clock clock;
sf::Time nextFrame;

void setupTimeLoop(){
	frameRate = sf::seconds(1.f/60.f);
	curTime = sf::seconds(0.f);
	clock = sf::Clock();
	nextFrame = sf::seconds(1.f/60.f);
}

void waitForFrameSync(){
	while(clock.getElapsedTime() < nextFrame);
	nextFrame += frameRate;
	curTime = clock.getElapsedTime();
}

float secondsSinceLastLoop(){
	return (clock.getElapsedTime()-curTime).asSeconds();
}

sf::RenderWindow* setupWindow(){
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "CHI Crossings");
	return window;
}