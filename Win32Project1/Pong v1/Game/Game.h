#pragma once

#include "RacketEntity.h"
#include "BallEntity.h"
#include "../Tools/ResourcesManager/ResourcesManager.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Controller\Player.h"

class Game
{
public:
	//static Game& GetInstance();
	void update(double deltaTime);
	void draw();
	Game();
	~Game();
	void setSingletons(Tools::ResourcesManager* resourcesManagerPtr);
	void init();
	sf::RenderWindow* getWindow();

private:
	static Game instance;
	Tools::ResourcesManager* _resourcesManagersPtr;
	sf::Sprite* _racket;
	sf::Sprite* _ball;
	sf::RenderWindow _window;
	Player* _player;
	RacketEntity* _racketPlayer;
	Controller* _controller;
	BallEntity* _ballEnt;
};

