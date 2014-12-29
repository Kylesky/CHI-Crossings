#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "ModuleHandler.hpp"
#include "AssetManager.hpp"
#include "GraphicsManager.hpp"
#include "InputHandler.hpp"

void setupTimeLoop();
void waitForFrameSync();
float secondsSinceLastLoop();
sf::RenderWindow* setupWindow();