#include "BallEntity.h"
#include "../Tools/Logger/Logger.h"



BallEntity::BallEntity(float speed, sf::Sprite* sprite): AbstractEntity(sprite)
{
	_speed = speed;  
	_direction.x = 0;
	_direction.y = 0;
}


BallEntity::~BallEntity()
{
}

void BallEntity::Update(float deltatime) 
{
	_pos += (_direction * _speed) * deltatime;
	_sprite->setPosition(_pos);
}

