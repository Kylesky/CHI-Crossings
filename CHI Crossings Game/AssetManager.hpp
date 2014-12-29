#pragma once
#include <map>
#include <string>
#include <fstream>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager{
private:
	static std::map<std::string, sf::Texture*> textures;
	static std::map<std::string, sf::SoundBuffer*> soundBuffers;
	static std::map<std::string, std::string> paths;

public:
	AssetManager();
	~AssetManager();

	static void initialize();

	static bool loadTexture(std::string name);
	static bool loadSoundBuffer(std::string name);

	static sf::Texture* getTexture(std::string name);
	static sf::SoundBuffer* getSoundBuffer(std::string name);

	static bool unloadTexture(std::string name);
	static bool unloadSoundBuffer(std::string name);

	static void shutdown();
};