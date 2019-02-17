#pragma once
#include "Entity.h"
#include "Player.h"
#include "Block.h"
#include "Ladder.h"
#include "Coin.h"

class EntityManager
{
public:
	EntityManager();
	~EntityManager();

private:
	std::shared_ptr<Player> _player;
	std::vector<std::vector<std::shared_ptr<Block>>> _blocks;
	std::vector<std::shared_ptr<Ladder>> _ladders;
	std::vector<std::shared_ptr<Coin>> _coins;

public:
	bool CheckCollisionsWithLeftWall();
	bool CheckCollisionsWithRightWall();

	bool CheckCollisionsWithUpperLadder();
	bool CheckCollisionsWithLowerLadder();

	bool CheckCollisionsWithUpperFloor();
	bool CheckCollisionsWithCurrentFloor();
	bool CheckCollisionsWithLowerFloor();

	void HandleCollisionsWithCoins();

	float GetUpperBlockY();
	float GetCurrentBlockY();
	float GetLowerBlockY();

	std::shared_ptr<Player> GetPlayer() {
		return _player;
	}

	std::vector<std::vector<std::shared_ptr<Block>>> GetBlocks() {
		return _blocks;
	}

	std::vector<std::shared_ptr<Ladder>> GetLadders() {
		return _ladders;
	}

	std::vector<std::shared_ptr<Coin>> GetCoins() {
		return _coins;
	}

};