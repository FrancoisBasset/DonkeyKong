#include "pch.h"
#include "Movable.h"

Movable::Movable(std::string spriteSheet, float x, float y) : Entity(spriteSheet, x, y) {}

Movable::~Movable() {}

void Movable::Move(Orientation orientation) {
	_sprite.move(GetMovement(orientation));
}

sf::Vector2f Movable::GetMovement(Orientation orientation) {
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

	return floorMovement;
}

void Movable::PlaceAtBlock(std::shared_ptr<Block> block, Orientation orientation) {
	float playerY = this->GetPosition().y + this->GetSprite().getTextureRect().height;
	float blockY = block->GetPosition().y;

	float diffY = fabsf(playerY - blockY);

	if (orientation == Orientation::DOWN) {
		diffY = -diffY;
	}

	sf::Vector2f movement(0.f, diffY);

	_sprite.move(movement);
}