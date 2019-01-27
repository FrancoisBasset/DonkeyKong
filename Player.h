#pragma once
#include "Entity.h"
#include "Movable.h"
#include "Constants.h"

class Player : public Movable
{
	
public:
	Player(float x, float y);
	~Player();

private:
	int _ammoCount = 0;

public:
	void AddOneAmmo();
	void RemoveOneAmmo();

};