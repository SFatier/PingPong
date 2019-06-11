#pragma once
#include <SFML/Graphics.hpp>

#ifndef ABSTRACTENTITY_H
#define ABSTRACTENTITY_H

class AbstractEntity
{
public:
	~AbstractEntity();
	virtual void Draw(sf::RenderWindow* window);
	sf::Vector2f getPos() { return _pos; }
	void setPos(sf::Vector2f pos) { _pos = pos; }
	void setPos(float x, float y) { _pos.x = x; _pos.y = y; };
	sf::Sprite* getSprite() { return _sprite; };
	virtual void Update(float deltatime) = 0;
protected:
	 AbstractEntity(sf::Sprite* sprite);
	 sf::Vector2f _pos;
	 sf::Sprite* _sprite;

};

#endif //ABSTRACTENTITY_H

