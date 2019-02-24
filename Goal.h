#pragma once

#include "Entity.h"
#include "Block.h"
#include "Player.h"

class Goal : public Entity
{

public:
	Goal(std::shared_ptr<Block> block);
	~Goal();

	void DoorMovement(std::shared_ptr<Player>);
};