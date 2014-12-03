#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

void setupTimeLoop();
void waitForFrameSync();
float secondsSinceLastLoop();
sf::RenderWindow* setupWindow();