#pragma once
#include "Entity.h"
#include "Player.h"
#include "Block.h"
#include "Ladder.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

private:
	std::shared_ptr<Player> _player;
	std::vector<std::vector<std::shared_ptr<Block>>> _blocks;
	std::vector<std::shared_ptr<Ladder>> _ladders;

public:
	bool checkCollisionsWithLadder();

	std::shared_ptr<Player> GetPlayer() {
		return _player;
	}

	std::vector<std::vector<std::shared_ptr<Block>>> GetBlocks() {
		return _blocks;
	}

	std::vector<std::shared_ptr<Ladder>> GetLadders() {
		return _ladders;
	}

};