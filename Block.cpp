#include "pch.h"
#include "Block.h"
#include "Constants.h"

Block::Block(float x, float y) : Entity(Constants::BLOCK_SPRITESHEET(), x, y)
{
	_type = EntityType::BLOCK;
}

Block::~Block()
{
}
