#include "pch.h"
#include "Ladder.h"
#include "Entity.h"
#include "Constants.h"

Ladder::Ladder(float x, float y) : Entity(Constants::LADDER_SPRITESHEET(), x, y)
{
	_type = EntityType::LADDER;
}

Ladder::~Ladder()
{
}
