#include "Game.h"
#include <ctime>
#include <cmath>
#include "CollisionManager.h"

void Game::update(double deltaTime)
{
	_firstPlayer->Update(deltaTime);
	_secondPlayer->Update(deltaTime);

	if (_waitLaunch == true)
	{
		sf::Vector2f pos;
		if (_waitPlayer == Players::LEFT)
		{
			pos = _racketFirstPlayer->getPos();
			pos.x += _racket->getLocalBounds().width;
			pos.y += _racket->getLocalBounds().height *0.5F - _ball->getLocalBounds().height *0.5F;
		}
		else
		{
			pos = _racketSecondPlayer->getPos();
			pos.x -= _ball->getLocalBounds().width;
			pos.y += _racket->getLocalBounds().height *0.5F - _ball->getLocalBounds().height *0.5F;
		}
		_ballEnt->setPos(pos.x, pos.y);
	
	}
	else
	{
		_ballEnt->Update(deltaTime);
	}

	CollisionType type = CollisionManager::checkCollision(_ballEnt, _window.getSize());

	if (type != CollisionType::NONE) {
		sf::Vector2f dir = _ballEnt->getDirection();
		switch (type)
		{
		case CollisionType::TOP:
			if (dir.y < 0) {
				dir.y *= -1.0F;
				_ballEnt->setDirection(dir);
			}
			Tools::Logger::log("La balle a touche le top");
			break;
		case CollisionType::BOTTOM:
			if (dir.y > 0) {
				dir.y *= -1.0F;
				_ballEnt->setDirection(dir);
			}
			Tools::Logger::log("La balle a touche le bas");
			break;
		case CollisionType::LEFT:
			_waitPlayer = Players::LEFT;
			_waitLaunch = true;
			_secondPlayer->addPoint();
			break;
		case CollisionType::RIGHT:
			_waitPlayer = Players::RIGHT;
			_waitLaunch = true;
			_firstPlayer->addPoint();
			Tools::Logger::log("La balle a touche la droite");
			break;
		}
	}

	type = CollisionManager::checkCollision(_racketFirstPlayer, _window.getSize());
	if (type == CollisionType::TOP)
	{
		_racketFirstPlayer->setPos(20, 0);
	}
	else if (type == CollisionType::BOTTOM)
	{
		_racketFirstPlayer->setPos(20, _window.getSize().y - _racketFirstPlayer->getSprite()->getLocalBounds().height);
	}

	type = CollisionManager::checkCollision(_racketSecondPlayer, _window.getSize());
	if (type == CollisionType::TOP)
	{
		_racketSecondPlayer->setPos(_window.getSize().x - 20 - _racketSecondPlayer->getSprite()->getLocalBounds().width, 0);
	}
	else if (type == CollisionType::BOTTOM)
	{
		_racketSecondPlayer->setPos(_window.getSize().x - 20 - _racketSecondPlayer->getSprite()->getLocalBounds().width, _window.getSize().y - _racketFirstPlayer->getSprite()->getLocalBounds().height);
	}
	
	if (!_waitLaunch)
	{
		type = CollisionManager::checkCollision(_ballEnt, _racketFirstPlayer);
		if (type == CollisionType::OBJECT)
		{
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			sf::Vector2f dir = _ballEnt->getDirection();
			sf::Vector2f pos = _ballEnt->getPos();
			if (dir.x < 0) {
				dir.x *= -1.0F;
			}
			if (dir.y < 0)
			{
				if (pos.y - _ball->getLocalBounds().height/2 > _racketFirstPlayer->getPos().y + _racket->getLocalBounds().height/2)
				{
					dir.y *= -1.0F;
					_ballEnt->setSpeed(0.2);
				}
			}
			if (dir.y > 0)
			{
				if (pos.y - _ball->getLocalBounds().height / 2 < _racketFirstPlayer->getPos().y + _racket->getLocalBounds().height / 2)
				{
					dir.y *= -1.0F;
				}
			}
			_ballEnt->setDirection(dir);
		}
   		type = CollisionManager::checkCollision(_ballEnt, _racketSecondPlayer);
		if (type == CollisionType::OBJECT)
		{
			float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
			sf::Vector2f dir = _ballEnt->getDirection();
			sf::Vector2f pos = _ballEnt->getPos();
			float speed = _ballEnt->getSpeed();
			if (dir.x > 0) {
				dir.x *= -1.0F;
				_ballEnt->setDirection(dir);
			}
			if (dir.y < 0)
			{
				if (pos.y - _ball->getLocalBounds().height / 2 > _racketSecondPlayer->getPos().y + _racket->getLocalBounds().height / 2)
				{
					dir.y *= -1.0F;
					if (speed < 1.5F)
					_ballEnt->setSpeed(0.1);
				}
			}
			if (dir.y > 0)
			{
				if (pos.y - _ball->getLocalBounds().height / 2 < _racketSecondPlayer->getPos().y + _racket->getLocalBounds().height / 2)
				{
					dir.y *= -1.0F;
					if (speed <= 1.5F && speed > 0.5F)
						_ballEnt->setSpeed(0.1);
				}
			}
			_ballEnt->setDirection(dir);
		}
	}
}


void Game::draw()
{
	_window.clear(sf::Color::White);

	_racket->setPosition(_racketFirstPlayer->getPos());

	_window.draw(*_racket);
	_racket->setPosition(_racketSecondPlayer->getPos());
	_window.draw(*_racket);

	_ball->setPosition(_ballEnt->getPos());
	_window.draw(*_ball);

	_window.draw(_text);
	_window.display();
}

void Game::init()
{
	Tools::Logger::log("Initialisation du jeu.");
	sf::ContextSettings settings;
	settings.depthBits = 0;
	settings.stencilBits = 0;
	settings.antialiasingLevel = 16;
	settings.majorVersion = 3;
	settings.minorVersion = 3;

	_window.create(sf::VideoMode(800,500), "Pong", 0, settings);

	_racket = _resourcesManagersPtr->getSprite("rackets");
	_racketFirstPlayer = new RacketEntity(_racket);
	_racketFirstPlayer->setPos(20, _window.getSize().y / 2 - (_racketFirstPlayer->getSprite()->getLocalBounds().height / 2));
	_firstPlayer = new Player(_racketFirstPlayer, this, Players::LEFT);

	_racketSecondPlayer = new RacketEntity(_racket);
	_racketSecondPlayer->setPos(_window.getSize().x - 20 - _racketSecondPlayer->getSprite()->getLocalBounds().width, _window.getSize().y / 2 - (_racketFirstPlayer->getSprite()->getLocalBounds().height / 2));
	_secondPlayer = new Player(_racketSecondPlayer, this, Players::RIGHT);

	_ball = _resourcesManagersPtr->getSprite("ball");
	_ballEnt = new BallEntity(0.5,_ball);

	sf::Vector2f pos = _racketFirstPlayer->getPos();
	pos.x += _racket->getLocalBounds().width;
	pos.y += _racket->getLocalBounds().height *0.5F - _ball->getLocalBounds().height *0.5F;
	_ballEnt->setPos(pos.x, pos.y);
	_waitPlayer = Players::LEFT;

	srand(time(NULL));
}

sf::RenderWindow* Game::getWindow()
{
	return &_window;
}

void Game::setSingletons(Tools::ResourcesManager* resourcesManagerPtr)
{
	_resourcesManagersPtr = resourcesManagerPtr;
}

void Game::launchBall(Players id)
{
	if (_waitLaunch == false)
	{
		return;
	}
	_ballEnt->initSpeed();
	sf::Vector2f dir = sf::Vector2f(1, ((rand()%21)-10)*0.1f);
	if (id == Players::RIGHT)
	{
		dir.x = -1;
	}
	float length = sqrt((dir.x * dir.x) + (dir.y * dir.y));
	if (length != 0)
	{
		Tools::Logger::log("Lancement de la balle");
		dir.x /= length;
		dir.y /= length;
	}
	std::string message = "La direction de la balle sera : (";
	message += std::to_string(dir.x) + "," + std::to_string(dir.y) + ")";
	Tools::Logger::log(message);
	_ballEnt->setDirection(dir);
	_waitLaunch = false;
}

Game::Game() : _firstPlayer(nullptr), _secondPlayer(nullptr), _racketFirstPlayer(nullptr), _racketSecondPlayer(nullptr)
{
}

Game::~Game()
{
	Tools::Logger::log("Destruction des pointeurs");
	delete _firstPlayer;
	delete _secondPlayer;
	delete _racketFirstPlayer;
	delete _racketSecondPlayer;
}
