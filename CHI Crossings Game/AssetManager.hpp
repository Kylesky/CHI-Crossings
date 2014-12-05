#pragma once
#include <map>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class AssetManager{
private:
	std::map<std::string, sf::Texture*> textures;
	std::map<std::string, sf::SoundBuffer*> soundBuffers;
public:
	AssetManager();
	~AssetManager();

	bool loadTexture(std::string name, std::string path);
	bool loadSoundBuffer(std::string name, std::string path);

	sf::Texture* getTexture(std::string name);
	sf::SoundBuffer* getSoundBuffer(std::string name);

	bool unloadTexture(std::string name);
	bool unloadSoundBuffer(std::string name);

	void shutdown();
};