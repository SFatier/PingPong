#include "Player.h"
#define SPEED 500

Player::Player(AbstractEntity* entity, Game* game, Players id): Controller(entity)
{
	_game = game;
	_id = id;
}


Player::~Player()
{
}

void Player::Update(float deltatimef) 
{
	bool isDownPressed;
	bool isUpPressed;
	bool isSpacePressed;

	if (_id == Players::LEFT)
	{
		isDownPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q);
		isUpPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A);
		isSpacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
	}
	else 
	{
		isDownPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down);
		isUpPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up);
		isSpacePressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Return);

	}

	if (isSpacePressed)
	{
		_game->launchBall(_id);
	}

	if (isDownPressed && isUpPressed) {
		return;
	}

	if (isDownPressed) {
		sf::Vector2f vect = _entity->getPos();
		vect.y += SPEED * (deltatimef / 1000);
		_entity->setPos(vect);
	}

	if (isUpPressed) {
		sf::Vector2f vect = _entity->getPos();
		vect.y -= SPEED * (deltatimef / 1000);
		_entity->setPos(vect);
	}
}
