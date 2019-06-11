#pragma once
#include <string>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>


namespace Audio
{
	class Sound
	{
	public:
		Sound();
		~Sound();
		Sound(const std::string &path);
		bool load(const std::string &path);
		bool play();
		bool stop();
		bool pause();
	private:
		sf::SoundBuffer _data;
		sf::Sound _sound;
		bool _loaded;
	};
}

