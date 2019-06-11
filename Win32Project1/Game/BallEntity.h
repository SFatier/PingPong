#pragma once
#include "AbstractEntity.h"

class BallEntity: public AbstractEntity
{
public:
	BallEntity(float speed, sf::Sprite* sprite);
	~BallEntity();
	void Update(float deltatime);
	void setDirection(sf::Vector2f direction) { _direction = direction; }
	void setDirection(float x, float y) { _pos.x = x; _pos.y = y; };
	void setSpeed(float speed) { _speed += speed; }
	void initSpeed() { _speed = 0.5F; }
	float getSpeed() { return _speed; }
	sf::Vector2f getDirection() { return _direction; }
private:
	float _speed;
	sf::Vector2f _direction;
};

