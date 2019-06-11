#pragma once
#include "Controller.h"
#include "../AbstractEntity.h"
#include "../Game.h"

class Game;
enum class Players;

class Player: public Controller
{
public:
	Player(AbstractEntity* entity, Game* game, Players id);
	~Player();
	void Update(float deltatimef);
	void addPoint() { _score += 1; }
private:
	Game* _game;
	Players _id;
	int _score;
};

