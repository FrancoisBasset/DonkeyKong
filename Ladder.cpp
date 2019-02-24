#include "pch.h"
#include "Ladder.h"
#include "Entity.h"
#include "Constants.h"

Ladder::Ladder(float x, float y) : Entity("Media/Textures/Ladder.png", x, y, sf::Color::Black)
{
	_type = EntityType::LADDER;
}

Ladder::~Ladder() {}