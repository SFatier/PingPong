#include "ResourcesManager.h"
#include <SFML/Graphics/Texture.hpp>

//Gestion des ressources Sprites/Textures/Sounds

namespace Tools
{
	ResourcesManager::ResourcesManager()
	{
	}


	ResourcesManager::~ResourcesManager()
	{
	}

	void ResourcesManager::addSprite(std::string key, const std::string &path)
	{
		sf::Texture* texture = new sf::Texture();
		texture->loadFromFile(path);
		sf::Sprite* sprite = new sf::Sprite();
		sprite->setTexture(*texture);
		_Sprites[key] = sprite;
	}

	void ResourcesManager::addSound(std::string key, const std::string &path)
	{
		Audio::Sound *sound = new Audio::Sound(path);
		_Sound[key] = sound;
	}

	sf::Sprite* ResourcesManager::getSprite(std::string key)
	{
		return _Sprites[key];
	}
	Audio::Sound* ResourcesManager::getSound(std::string key)
	{
		return _Sound[key];
	}
}
