#pragma once
#include "Entity.h"
#include "Player.h"
#include "Block.h"
#include "Ladder.h"
#include "Coin.h"
#include "Goal.h"
#include "Enemy.h"

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
	std::shared_ptr<Goal> _goal;
	std::vector<std::shared_ptr<Enemy>> _enemies;

	bool _win = false;
	bool _killed = false;

public:
	bool CheckCollisionsWithLeftWall();
	bool CheckCollisionsWithRightWall();

	bool CheckCollisionsWithUpperLadder();
	bool CheckCollisionsWithLowerLadder();

	bool CheckCollisionsWithUpperFloor();
	bool CheckCollisionsWithCurrentFloor();
	bool CheckCollisionsWithLowerFloor();

	void HandleCollisionsWithCoins();

	void CheckCollisionsWithGoal();

	void CheckCollisionsWithEnemy();

	void Attack();

	float GetUpperBlockY();
	float GetCurrentBlockY();
	float GetLowerBlockY();

	std::shared_ptr<Player> GetPlayer()
	{
		return _player;
	}

	std::vector<std::vector<std::shared_ptr<Block>>> GetBlocks()
	{
		return _blocks;
	}

	std::vector<std::shared_ptr<Ladder>> GetLadders()
	{
		return _ladders;
	}

	std::vector<std::shared_ptr<Coin>> GetCoins()
	{
		return _coins;
	}

	std::shared_ptr<Goal> GetGoal()
	{
		return _goal;
	}

	std::vector<std::shared_ptr<Enemy>> GetEnemies()
	{
		return _enemies;
	}

	bool Win()
	{
		return _win;
	}

	bool Killed()
	{
		return _killed;
	}
};