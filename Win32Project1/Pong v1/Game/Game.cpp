#include "Game.h"


void Game::update(double deltaTime)
{
	_controller->Update(deltaTime);
}

void Game::draw()
{
	_window.clear(sf::Color::White);
	_window.draw(*_resourcesManagersPtr->getSprite("rackets"));
	_window.draw(*_resourcesManagersPtr->getSprite("ball"));
	_window.draw(*_resourcesManagersPtr->getSprite("texture"));
	_racket->setPosition(_racketPlayer->getPos());
	_window.draw(*_racket);
	_ball->setPosition(_racketPlayer->getPos());
	_window.draw(*_ball);
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
	_window.create(sf::VideoMode::getDesktopMode(), "Pong", 0, settings);
	_racket = _resourcesManagersPtr->getSprite("rackets");
	_racketPlayer = new RacketEntity(_racket);
	_racketPlayer->setPos(20, _window.getSize().y / 2);
	_controller = new Player(_racketPlayer);
	_ball = _resourcesManagersPtr->getSprite("ball");
	_ballEnt = new BallEntity(1,_ball);
}

sf::RenderWindow* Game::getWindow()
{
	return &_window;
}

void Game::setSingletons(Tools::ResourcesManager* resourcesManagerPtr)
{
	_resourcesManagersPtr = resourcesManagerPtr;
}

Game::Game() : _player(nullptr), _racketPlayer(nullptr), _controller(nullptr)
{

}

Game::~Game()
{
	delete _player;
	delete _racketPlayer;
	delete _controller;
}
