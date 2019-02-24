#include "pch.h"

#include "Constants.h"
#include "Coin.h"

Coin::Coin(std::shared_ptr<Block> block) : Entity("Media/Textures/Coin.png", 0, 0, sf::Color::Black)
{
	PlaceAtBlock(block);
	_type = EntityType::COIN;
}

Coin::~Coin() {}