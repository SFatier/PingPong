#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Tools/ResourcesManager/ResourcesManager.h"
#include "Game/Game.h"
#include <ctime>

using namespace sf;
using namespace Tools;
ResourcesManager* resourcesManagersPtr;
Game* game;

void createSingleton()
{
	Tools::Logger::log("ResourcesManager cree.");
	resourcesManagersPtr = ResourcesManager::createInstance();
}

void loadResources()
{
	Tools::Logger::log("Chargement des ressources");
	resourcesManagersPtr->addSprite("rackets", "../Data/rackets.png");
	resourcesManagersPtr->addSprite("ball", "../Data/ball.png");
	resourcesManagersPtr->addSprite("texture", "../Data/texture.png");

}

int main()
{
	createSingleton();
	loadResources();
	resourcesManagersPtr->getSprite("rackets")->setPosition(50, 50);
	resourcesManagersPtr->getSprite("ball")->setPosition(100, 50);
	resourcesManagersPtr->getSprite("texture")->setPosition(200, 50);

	game = new Game();
	game->setSingletons(resourcesManagersPtr);
	game->init();
	sf::RenderWindow* window = game->getWindow();
	double before, after;
	before = -1;
	after = 0;

	// Boucle principale
	while (window->isOpen())
	{
		double deltaTime;
		if (before < 0)
		{
			deltaTime = 0;
		}
		else
		{
			after = clock();
			deltaTime = after - before;
		}
		before = after;
		//Tools::Logger::log(std::to_string(deltaTime));
		game->update(deltaTime);
		game->draw();
		
		Event event;
		while (window->pollEvent(event))
		{
			if ((event.type == Event::Closed) ||
				((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
				window->close();
		}
	}
	delete game;
	return EXIT_SUCCESS;	
}