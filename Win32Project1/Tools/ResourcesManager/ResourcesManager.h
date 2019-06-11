#pragma once

#include "../Singleton.h"
#include <SFML/Graphics/Sprite.hpp>
#include <string>
#include <map>
#include "../../Audio/Sound.h"

namespace Tools
{
	class ResourcesManager : public Singleton<ResourcesManager>
	{

	public:
		void addSprite(std::string key, const std::string &path);
		void addSound(std::string key, const std::string &path);
		sf::Sprite *getSprite(std::string key);
		Audio::Sound *getSound(std::string key);
	private:
		std::map<std::string, sf::Sprite*> _Sprites;
		std::map<std::string, Audio::Sound*> _Sound;
		ResourcesManager();
		~ResourcesManager();
		friend class Singleton<ResourcesManager>;
	};
}

