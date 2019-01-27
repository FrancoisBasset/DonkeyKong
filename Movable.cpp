#include "pch.h"
#include "Movable.h"

Movable::Movable(std::string spriteSheet, float x, float y) : Entity(spriteSheet, x, y)
{
}

Movable::~Movable()
{
}

void Movable::move(Orientation orientation) {
	sf::Vector2f movement(0.f, 0.f);

	switch (orientation) {
		case Orientation::LEFT:
			movement.x -= Constants::PLAYER_SPEED();
			break;
		case Orientation::RIGHT:
			movement.x += Constants::PLAYER_SPEED();
			break;
		case Orientation::UP:
			movement.y -= Constants::PLAYER_SPEED();
			break;
		case Orientation::DOWN:
			movement.y += Constants::PLAYER_SPEED();
			break;
	}

	sf::Vector2f floorMovement = movement * Constants::TIME_PER_FRAME().asSeconds();
	floorMovement.x = floorf(floorMovement.x);
	floorMovement.y = floorf(floorMovement.y);

	_sprite.move(floorMovement);
}