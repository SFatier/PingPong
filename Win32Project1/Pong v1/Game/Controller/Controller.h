#pragma once

#include "../AbstractEntity.h"


class Controller
{
public:
	Controller(AbstractEntity* entity);
	~Controller();
	virtual void Update(float deltatimef) = 0;
protected:
	AbstractEntity* _entity;
};

