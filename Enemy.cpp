#include "pch.h"
#include "Enemy.h"
#include "Block.h"
#include "Constants.h"
#include "Game.h"

Enemy::Enemy(std::shared_ptr<Block> block, int floor) : Entity("Media/Textures/Enemy.png", 0, 0, sf::Color(0, 255, 255, 255))
{
	_sprite.setTextureRect(sf::IntRect(142, 13, 28, 49));
	PlaceAtBlock(block);
	_floor = floor;
	_type = EntityType::ENEMY;
}

Enemy::~Enemy() {}

void Enemy::TriggerAnimation()
{
	_rect = 0;
}

void Enemy::AnimationUpdate()
{
	if (_rect == -1)
	{
		return;
	}

	if (_rect == _rects.size())
	{
		_rect = -1;
		SetUndisplayed();
		return;
	}

	_sprite.setTextureRect(
		sf::IntRect(
			_rects[_rect][0],
			_rects[_rect][1],
			_rects[_rect][2],
			_rects[_rect][3]
		)
	);

	_rect++;

	Sleep(50);
}