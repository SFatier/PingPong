#include "AbstractEntity.h"

void AbstractEntity::Draw(sf::RenderWindow* window)
{

}

AbstractEntity::AbstractEntity(sf::Sprite* sprite): _sprite(sprite)
{
}

AbstractEntity::~AbstractEntity(){}
