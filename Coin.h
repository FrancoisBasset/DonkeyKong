#pragma once

#include "Entity.h"
#include "Block.h"

class Coin : public Entity
{

public:
	Coin(std::shared_ptr<Block> block);
	~Coin();

	void PlaceCoinAtBlock(std::shared_ptr<Block> block);
};

