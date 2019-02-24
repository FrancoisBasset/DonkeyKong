#include "pch.h"
#include "Goal.h"
#include "Constants.h"
#include "Player.h"

Goal::Goal(std::shared_ptr<Block> block) : Entity("Media/Textures/Goal.png", 0, 0, sf::Color::Black)
{
	_sprite.setTextureRect(sf::IntRect(177, 12, 34, 48));
	PlaceAtBlock(block);
	_type = EntityType::GOAL;
}

Goal::~Goal() {}

void Goal::DoorMovement(std::shared_ptr<Player> player)
{
	int a[2][4] = {
		{226, 11, 33, 49},
		{273, 11, 33, 49}
	};

	for (int i = 0; i < 2; i++)
	{
		_sprite.setTextureRect(
			sf::IntRect(
				a[i][0],
				a[i][1],
				a[i][2],
				a[i][3]
			)
		);
	}
}