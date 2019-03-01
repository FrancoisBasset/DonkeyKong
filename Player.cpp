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
	_sprite.setTextureRect(sf::IntRect(3, 250, 15, 38));
}

void Player::ProfilToLeft()
{
	_profil = Orientation::LEFT;
	_sprite.setTextureRect(sf::IntRect(3, 166, 15, 38));
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

void Player::AnimationUpdate() {
	/*std::vector<std::vector<int>> tab;

	switch (_profil) {
		case Orientation::LEFT:
			tab = _lefts;
			break;
	}*/

	if (_rect == _rights.size())
	{
		_rect = 0;
	}

	_sprite.setTextureRect(
		sf::IntRect(
			_rights[_rect][0],
			_rights[_rect][1],
			_rights[_rect][2],
			_rights[_rect][3]
		)
	);

	_rect++;
}