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
	int _coins = 0;
	int _ammoCount = 0;
	int _floor = 4;
	Orientation _profil;

public:
	void AddOneAmmo();
	void RemoveOneAmmo();

	void AddOneCoin();

	void ProfilToRight();
	void ProfilToLeft();

	void FloorUp();
	void FloorDown();
	int GetFloor();

	float GetFoot()
	{
		return GetPosition().y + GetSize().y;
	}

	int GetCoins()
	{
		return _coins;
	}

	Orientation GetProfil()
	{
		return _profil;
	}
};