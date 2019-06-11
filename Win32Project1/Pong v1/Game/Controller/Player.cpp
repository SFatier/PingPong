#include "Player.h"
#define SPEED 100

Player::Player(AbstractEntity* entity): Controller(entity)
{
}


Player::~Player()
{
}

void Player::Update(float deltatimef) 
{
	bool isDownPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
	bool isUpPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);

	if (isDownPressed && isUpPressed) {
		return;
	}

	if (isDownPressed) {
		sf::Vector2f vect = _entity->getPos();
		vect.y -= SPEED * (deltatimef / 1000);
		_entity->setPos(vect);
	}

	if (isUpPressed) {
		sf::Vector2f vect = _entity->getPos();
		vect.y += SPEED * (deltatimef / 1000);
		_entity->setPos(vect);
	}
}
