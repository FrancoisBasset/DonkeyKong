#include "pch.h"
#include "Player.h"

Player::Player(float x, float y) : Movable("Media/Textures/Winnie.png", x, y, sf::Color(173, 214, 214, 255))
{
	ProfilToRight();
	_type = EntityType::PLAYER;
}

Player::~Player() {}

void Player::ProfilToRight()
{
	_profil = Orientation::RIGHT;
	_sprite.setTextureRect(sf::IntRect(0, 248, 18, 40));
}

void Player::ProfilToLeft()
{
	_profil = Orientation::LEFT;
	_sprite.setTextureRect(sf::IntRect(0, 164, 18, 40));
}

void Player::AddOneAmmo()
{
	 _ammoCount++;
}

void Player::RemoveOneAmmo()
{
	if (_ammoCount != 0)
	{
		_ammoCount--;
	}
}

void Player::AddOneCoin()
{
	_coins++;
}

void Player::FloorUp()
{
	_floor--;
}

void Player::FloorDown()
{
	_floor++;
}

int Player::GetFloor()
{
	return _floor;
}