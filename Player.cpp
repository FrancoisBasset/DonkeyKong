#include "pch.h"
#include "Player.h"

Player::Player(float x, float y) : Movable(Constants::PLAYER_SPRITESHEET(), x, y)
{
	_sprite.setTextureRect(sf::IntRect(Constants::SPRITE_LEFT, Constants::SPRITE_TOP, Constants::SPRITE_WIDTH, Constants::SPRITE_LENGTH));
	_type = EntityType::PLAYER;
}

Player::~Player() {
	
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

/*void move(Orientation orientation) {
	switch (orientation)
	{
		case LEFT:
			break;
		case RIGHT:
			//moveRight();
			break;
		case UP:
			break;
		default:
			break;
	}
}

*/


