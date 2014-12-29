#pragma once
#include <map>
#include <bitset>
#include <string>
#include <fstream>

#include <SFML/Window.hpp>

enum KEY{LEFT, RIGHT, UP, DOWN, JUMP};

class InputHandler{
private:
	static std::bitset<5> keysprev, keysnow;
	static std::map<int, sf::Keyboard::Key> controls;

public:
	InputHandler();
	~InputHandler();
	
	static void initialize();
	static void shutdown();
	static void update();
	
	static bool isKeyDown(KEY k);
	static bool isKeyUp(KEY k);
	static bool isKeyPressed(KEY k);
	static bool isKeyHeld(KEY k);
	static bool isKeyReleased(KEY k);
	static void saveKeys();

	static void changeKey(KEY k, sf::Keyboard::Key b);
};