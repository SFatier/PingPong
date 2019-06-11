#pragma once
#include "AbstractEntity.h"

class BallEntity: public AbstractEntity
{
public:
	BallEntity(float speed, sf::Sprite* sprite);
	~BallEntity();
	void Update(float deltatime);
private:
	float _speed;
	sf::Vector2f _direction;
};

