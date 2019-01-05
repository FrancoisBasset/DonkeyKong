#include "pch.h"
#include "Entity.h"
#include "EOrientation.h"

class IMovable : Entity
{
public:
	IMovable();
	~IMovable();
protected:
	int moveSpeed;
	sf::Vector2f movement;

public:
	virtual void move(EOrientation orientation) =0;

};
