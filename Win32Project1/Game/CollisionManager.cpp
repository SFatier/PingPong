#include "CollisionManager.h"
#include "../Tools/Logger/Logger.h"

/*static*/ CollisionType CollisionManager::checkCollision(AbstractEntity* entity, sf::Vector2u windowSize)
{
	sf::Vector2f entityPos = entity->getPos();
	if (entityPos.x < 0 - entity->getSprite()->getLocalBounds().width)
	{
		return CollisionType::LEFT;
	}
	else if (entityPos.x > windowSize.x)
	{
		return CollisionType::RIGHT;
	}
	else if (entityPos.y < 0)
	{
		return CollisionType::TOP;
	} 
	else if (entityPos.y > windowSize.y - entity->getSprite()->getLocalBounds().height)
	{
		return CollisionType::BOTTOM;
	}
	return CollisionType::NONE;
}

/*static*/ CollisionType CollisionManager::checkCollision(AbstractEntity* entity1, AbstractEntity* entity2)
{
	sf::Vector2f posBall = entity1->getPos();
	sf::Vector2f posRacket1 = entity2->getPos();
	sf::FloatRect spriteBall = entity1->getSprite()->getLocalBounds();
	sf::FloatRect spriteRacket1 = entity2->getSprite()->getLocalBounds();
	CollisionType returnCode;  

	
	//Cas 1 : si entity1 est plus bas que entity2
	if (posRacket1.y + spriteRacket1.height < posBall.y)
	{
		returnCode = CollisionType::NONE;
	} 
	//Cas 2 : si entity1 est plus haut que entity2
	else if (posRacket1.y > posBall.y + spriteBall.height)
	{
		returnCode = CollisionType::NONE;

	}
	//Cas 3 : si entity2 est trop à gauche
	else if (posRacket1.x + spriteRacket1.width < posBall.x)
	{
		returnCode = CollisionType::NONE;
	}
	//Cas 4 : si entity2 est trop à droite
	else if (posRacket1.x > posBall.x + spriteBall.width)
	{
		returnCode = CollisionType::NONE;

	}
	//Cas 5 :  deux entities se touchent
	
	else
	{
		Tools::Logger::log("Collision detectee");
		returnCode = CollisionType::OBJECT;
	}
	return returnCode;
}
