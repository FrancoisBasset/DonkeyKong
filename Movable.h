#include "pch.h"
#include "Entity.h"
#include "Orientation.h"

class Movable
{

public:
	Movable();
	~Movable();

public:
	Orientation _orientation;
	int moveSpeed;
	sf::Vector2f movement;

public:
	virtual void move(Orientation orientation) = 0;

};
