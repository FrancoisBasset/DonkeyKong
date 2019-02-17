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

public:
	void AddOneAmmo();
	void RemoveOneAmmo();

	void AddOneCoin();

	void ProfilToRight();
	void ProfilToLeft();

	void FloorUp();
	void FloorDown();
	int GetFloor();

	sf::Vector2u GetSize() {
		return sf::Vector2u(this->GetSprite().getTextureRect().width, this->GetSprite().getTextureRect().height);
	}

	float GetFoot() {
		return GetPosition().y + GetSize().y;
	}

	int GetCoins() {
		return _coins;
	}
};