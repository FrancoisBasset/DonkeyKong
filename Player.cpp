#include "pch.h"
#include "Player.h"

Player::Player(float x, float y) : Movable(Constants::PLAYER_SPRITESHEET(), x, y)
{
	ProfilToRight();
	_type = EntityType::PLAYER;
}

Player::~Player() {
	
}

void Player::ProfilToRight() {
	_sprite.setTextureRect(
		sf::IntRect(
			Constants::PLAYER_SPRITE_RIGHT_X,
			Constants::PLAYER_SPRITE_RIGHT_Y,
			Constants::PLAYER_SPRITE_RIGHT_WIDTH,
			Constants::PLAYER_SPRITE_RIGHT_HEIGHT
		)
	);
}

void Player::ProfilToLeft() {
	_sprite.setTextureRect(
		sf::IntRect(
			Constants::PLAYER_SPRITE_LEFT_X,
			Constants::PLAYER_SPRITE_LEFT_Y,
			Constants::PLAYER_SPRITE_LEFT_WIDTH,
			Constants::PLAYER_SPRITE_LEFT_HEIGHT
		)
	);
}

void Player::AddOneAmmo()
{
	 _ammoCount++;
}

void Player::RemoveOneAmmo()
{
	if (_ammoCount != 0) {
		_ammoCount--;
	}
}

void Player::AddOneCoin() {
	_coins++;
}

void Player::FloorUp()
{
	_floor--;
}

void Player::FloorDown() {
	_floor++;
}

int Player::GetFloor()
{
	return _floor;
}