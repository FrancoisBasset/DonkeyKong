#include "pch.h"
#include "Entity.h"
#include "Orientation.h"

#include "Constants.h"

class Movable : public Entity
{

public:
	Movable(std::string spriteSheet, float x, float y);
	~Movable();

public:
	void move(Orientation orientation);

};
