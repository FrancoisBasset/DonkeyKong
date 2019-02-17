#include "pch.h"

#include "Constants.h"
#include "Coin.h"

Coin::Coin(std::shared_ptr<Block> block) : Entity(Constants::COIN_SPRITESHEET(), 0, 0)
{
	PlaceCoinAtBlock(block);
	_type = EntityType::COIN;
}

Coin::~Coin() {}

void Coin::PlaceCoinAtBlock(std::shared_ptr<Block> block) {
	float x = block->GetPosition().x;
	float y = block->GetPosition().y - this->GetSize().y;

	_sprite.move(sf::Vector2f(x, y));
}