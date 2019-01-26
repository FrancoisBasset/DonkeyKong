#pragma once
#include "Entity.h"
#include "Movable.h"
#include "Constants.h"

class Player : public Entity/*, Movable*/
{
	
public:
	Player(float x, float y);
	~Player();

private:
	int _ammoLeft = 0;

public:
	void AddAmmo();
	void RemoveAmmo();

public:	

	/*void moveRight() {
		this->movement.x = this->movement.x += moveSpeed;
		this->movement.y = this->movement.y += moveSpeed;

		_spriteMode.left += Constants::SPRITE_WIDTH;

	};*/

};



