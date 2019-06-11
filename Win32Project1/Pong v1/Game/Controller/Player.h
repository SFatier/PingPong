#pragma once
#include "Controller.h"
#include "../AbstractEntity.h"


class Player: public Controller
{
public:
	Player(AbstractEntity* entity);
	~Player();
	void Update(float deltatimef);
};

