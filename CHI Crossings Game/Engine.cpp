#include "Engine.hpp"

sf::Time frameRate;
sf::Time curTime;
sf::Clock gameClock;
sf::Time nextFrame;

void setupTimeLoop(){
	frameRate = sf::seconds(1.f/60.f);
	curTime = sf::seconds(0.f);
	gameClock = sf::Clock();
	nextFrame = sf::seconds(1.f/60.f);
}

void waitForFrameSync(){
	while(gameClock.getElapsedTime() < nextFrame);
	while(nextFrame <= gameClock.getElapsedTime()) nextFrame += frameRate;
	curTime = gameClock.getElapsedTime();
}

float secondsSinceLastLoop(){
	return (gameClock.getElapsedTime()-curTime).asSeconds();
}

sf::RenderWindow* setupWindow(){
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 600), "CHI Crossings");
	return window;
}