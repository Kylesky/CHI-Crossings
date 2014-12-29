#include "InputHandler.hpp"

std::bitset<5> InputHandler::keysprev;
std::bitset<5> InputHandler::keysnow;
std::map<int, sf::Keyboard::Key> InputHandler::controls;

InputHandler::InputHandler(){
}
InputHandler::~InputHandler(){
}

void InputHandler::initialize(){
	std::ifstream fin("keymap.dat");
	std::string key, button;
	while(std::getline(fin, key, '=') && std::getline(fin, button)){
		int a = atoi(key.c_str());
		int b = atoi(button.c_str());
		controls[a] = (sf::Keyboard::Key)b;
	}
	keysprev.reset();
	keysnow.reset();
}

void InputHandler::update(){
	keysprev = keysnow;
	keysnow.reset();
	for(std::map<int, sf::Keyboard::Key>::iterator it = controls.begin(); it != controls.end(); it++){
		if(sf::Keyboard::isKeyPressed(it->second)){
			keysnow[it->first] = 1;
		}
	}
}
	
bool InputHandler::isKeyDown(KEY k){
	return keysnow[k];
}

bool InputHandler::isKeyUp(KEY k){
	return !keysnow[k];
}

bool InputHandler::isKeyPressed(KEY k){
	return keysnow[k] && !keysprev[k];
}

bool InputHandler::isKeyHeld(KEY k){
	return keysnow[k] && keysprev[k];
}

bool InputHandler::isKeyReleased(KEY k){
	return !keysnow[k] && keysprev[k];
}

void InputHandler::changeKey(KEY k, sf::Keyboard::Key b){
	controls[k] = b;
}

void InputHandler::saveKeys(){
	std::ofstream fout("keymap.dat");
	std::string key, button;
	for(std::map<int, sf::Keyboard::Key>::iterator it = controls.begin(); it != controls.end(); it++){
		fout << it->first << "=" << it->second << std::endl;
	}
	fout.close();
}

void InputHandler::shutdown(){
	saveKeys();
}