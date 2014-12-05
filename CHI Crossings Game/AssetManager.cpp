#include "AssetManager.hpp"

AssetManager::AssetManager(){
}

AssetManager::~AssetManager(){
	shutdown();
}

bool AssetManager::loadTexture(std::string name, std::string path){
	sf::Texture* tex = new sf::Texture();
	if(!tex->loadFromFile(path)){
		return false;
	}
	textures[name] = tex;
	return true;
}

bool AssetManager::loadSoundBuffer(std::string name, std::string path){
	sf::SoundBuffer* sb = new sf::SoundBuffer();
	if(!sb->loadFromFile(path)){
		return false;
	}
	soundBuffers[name] = sb;
	return true;
}

sf::Texture* AssetManager::getTexture(std::string name){
	if(textures.count(name) != 0){
		return textures[name];
	}
	return NULL;
}

sf::SoundBuffer* AssetManager::getSoundBuffer(std::string name){
	if(soundBuffers.count(name) != 0){
		return soundBuffers[name];
	}
	return NULL;
}

bool AssetManager::unloadTexture(std::string name){
	if(textures.count(name) == 0){
		return false;
	}
	std::map<std::string, sf::Texture*>::iterator it = textures.find(name);
	delete it->second;
	textures.erase(it);
	return true;
}

bool AssetManager::unloadSoundBuffer(std::string name){
	if(soundBuffers.count(name) == 0){
		return false;
	}
	std::map<std::string, sf::SoundBuffer*>::iterator it = soundBuffers.find(name);
	delete it->second;
	soundBuffers.erase(it);
	return true;
}

void AssetManager::shutdown(){
	for(std::map<std::string, sf::Texture*>::iterator it = textures.begin(); it != textures.end(); it++){
		delete it->second;
	}
	textures.clear();
	for(std::map<std::string, sf::SoundBuffer*>::iterator it = soundBuffers.begin(); it != soundBuffers.end(); it++){
		delete it->second;
	}
	soundBuffers.clear();
}