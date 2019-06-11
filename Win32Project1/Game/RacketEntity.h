#pragma once
#include "AbstractEntity.h"

class RacketEntity: public AbstractEntity
{
public:
	RacketEntity(sf::Sprite* sprite);
	~RacketEntity();
	void Update(float deltatime);
};

