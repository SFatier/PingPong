#pragma once

#include "RacketEntity.h"
#include "BallEntity.h"
#include "../Tools/ResourcesManager/ResourcesManager.h"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Controller\Player.h"
#include <SFML\Graphics\Font.hpp>
#include <SFML\Graphics\Text.hpp>

class Player;

enum class Players
{
	LEFT,
	RIGHT
};

class Game
{
public:
	//static Game& GetInstance();
	void update(double deltaTime);
	void draw();
	void launchBall(Players id);
	Game();
	~Game();
	void setSingletons(Tools::ResourcesManager* resourcesManagerPtr);
	void init();
	sf::RenderWindow* getWindow();
private:
	static Game instance;
	Tools::ResourcesManager* _resourcesManagersPtr;
	sf::Sprite* _racket;
	sf::Font _font;
	sf::Text _text;

	sf::Sprite* _ball;
	sf::RenderWindow _window;
	Player* _firstPlayer;
	RacketEntity* _racketFirstPlayer;
	Player* _secondPlayer;
	RacketEntity* _racketSecondPlayer;
	BallEntity* _ballEnt;
	bool _waitLaunch;
	Players _waitPlayer;
};

