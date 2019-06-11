#include <SFML/Graphics.hpp>
#include <cstdlib>
#include "Tools/ResourcesManager/ResourcesManager.h"
#include "Game/Game.h"
#include <ctime>
#include <SFML\Audio.hpp>

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
}

void Jouer(sf::RenderWindow* window) {
	createSingleton();
	loadResources();
	game = new Game();
	game->setSingletons(resourcesManagersPtr);
	game->init();
	//sf::RenderWindow* window = game->getWindow();
	window = game->getWindow();
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
}
int main()
{
	int selectedItemIndex = 0;
	sf::RenderWindow window(sf::VideoMode(800, 600), "Main Pong");

	//Image de fond
	sf::Texture texture;
	if (!texture.loadFromFile("../Data/texture1.png"))
		return EXIT_FAILURE;

	sf::Sprite sprite(texture);

	//Renvoie les textes du menu
	sf::Font font; //font normal
	if (!font.loadFromFile("../Font/Outwrite.ttf"))
		return EXIT_FAILURE;

	sf::Font font_pong; //font titre
	if (!font_pong.loadFromFile("../Font/name.ttf"))
		return EXIT_FAILURE;

	sf::Text text[3];
	//titre 
	text[0].setFont(font_pong);
	text[0].setFillColor(sf::Color::White);
	text[0].setString("");
	text[0].setCharacterSize(100);
	text[0].setPosition(sf::Vector2f((window.getSize().x / 2 - 100), (window.getSize().y / 4 * 1) - 100));

	//Menu
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Red);
	text[1].setString("Play");
	text[1].setCharacterSize(50);
	text[1].setPosition(sf::Vector2f(window.getSize().x / 2 - 30, window.getSize().y / 4 * 2));

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::White);
	text[2].setString("Options");
	text[2].setCharacterSize(50);
	text[2].setPosition(sf::Vector2f((window.getSize().x / 2 - 60), window.getSize().y / 4 * 3));

	//Joue de la music
	/*sf::Music music;
	if (!music.openFromFile("../nice_music.ogg"))
		return EXIT_FAILURE;

	music.play();*/


	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.key.code == sf::Keyboard::Up)
			{

				if (selectedItemIndex - 1 >= 1)
				{
					text[selectedItemIndex].setFillColor(sf::Color::White);
					selectedItemIndex--;
					text[selectedItemIndex].setFillColor(sf::Color::Red);
				}
			}

			if (event.key.code == sf::Keyboard::Down) {
				if (selectedItemIndex + 1 < 3 && selectedItemIndex + 1 > 0)
				{
					text[selectedItemIndex].setFillColor(sf::Color::White);
					selectedItemIndex++;
					text[selectedItemIndex].setFillColor(sf::Color::Red);
				}
			}

			if (event.key.code == sf::Keyboard::Return) {
				switch (selectedItemIndex)
				{
				case 1:
					Jouer(&window);
					break;
				case 2:
					//options
					break;
				}
			}

			if ((event.type == Event::Closed) ||
				((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
				window.close();

		
		}

		window.clear();

		window.draw(sprite);

		for (int i = 0; i < 3; i++)
		{
			window.draw(text[i]);
		}
		window.display();
	}
	return EXIT_SUCCESS;
}