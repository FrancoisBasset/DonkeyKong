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

	int _rect = 0;

	std::vector<std::vector<int>> _rights = {
		{3, 293, 16, 38},
		{22, 293, 19, 37},
		{44, 294, 23, 37},
		{70, 294, 19, 37},
		{92, 293, 16, 38},
		{111, 292, 18, 39},
		{132, 293, 21, 38},
		{156, 295, 18, 36}
	};

	std::vector<std::vector<int>> _lefts = {
		{3, 208, 16, 38},
		{22, 208, 19, 38},
		{44, 209, 23, 37},
		{70, 209, 19, 37},
		{92, 208, 16, 38},
		{111, 207, 18, 39},
		{132, 208, 21, 38},
		{156, 210, 18, 36}
	};

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

	void AnimationUpdate();
};