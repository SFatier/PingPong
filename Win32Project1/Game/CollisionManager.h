#pragma once
#include "AbstractEntity.h"

enum class CollisionType
{
	NONE,
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
	OBJECT
};

class CollisionManager 
{
public:
	static CollisionType checkCollision(AbstractEntity* entity, sf::Vector2u windowSize);
	static CollisionType checkCollision(AbstractEntity* entity1, AbstractEntity* entity2);
	static CollisionType checkCollision(AbstractEntity* entity);
};

