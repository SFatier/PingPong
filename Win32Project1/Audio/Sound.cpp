#include "Sound.h"

namespace Audio
{
	Sound::Sound(): _loaded(false)
	{

	}

	Sound::~Sound()
	{

	}

	Sound::Sound(const std::string &path) : _loaded(false)
	{
		load(path);
	}

	bool Sound::load(const std::string &path) 
	{
		if (_data.loadFromFile(path))
		{
			_sound.setBuffer(_data);
			_loaded = true;
			return true;
		}
		return false;
	}
	bool Sound::play()
	{
		if (_loaded)
		{
			_sound.play();
			return true;
		}
		return false;
	}
	bool Sound::stop()
	{
		if (_loaded)
		{
			_sound.stop();
			return true;
		}
		return false;
	}
	bool Sound::pause()
	{
		if (_loaded)
		{
			_sound.pause();
			return true;
		}
		return false;
	}
}