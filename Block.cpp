#include "pch.h"

#include "Block.h"
#include "Constants.h"

Block::Block(float x, float y) : Entity("Media/Textures/Block.png", x, y, sf::Color::Black)
{
	_type = EntityType::BLOCK;
}

Block::~Block() {}