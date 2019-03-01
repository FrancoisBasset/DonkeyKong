#include "pch.h"
#include "EntityManager.h"

#include <cstdlib>
#include <ctime>

EntityManager::EntityManager()
{
	//BLOCKS
	for (int i = 0; i < Constants::BLOCK_COUNT_X; i++)
	{
		_blocks.push_back(std::vector<std::shared_ptr<Block>>());		

		for (int j = 0; j < Constants::BLOCK_COUNT_Y; j++)
		{
			float x = 70.f * (j + 1) - 70.f;
			float y = 0.f + Constants::BLOCK_SPACE() * (i + 1);

			_blocks[i].push_back(std::make_shared<Block>(x, y));
		}		
	}

	sf::Vector2u blockSize = _blocks[0][0]->GetSize();

	//LADDERS
	for (int i = 0; i < Constants::LADDER_COUNT; i++)
	{
		float x = 100.f + 70.f * (i + 1);
		float y = 0.f + Constants::BLOCK_SPACE() * (i + 1) + blockSize.y;

		_ladders.push_back(std::make_shared<Ladder>(x, y));		
	}

	//GOAL
	_goal = std::make_shared<Goal>(_blocks[0][0]);

	// COINS
	srand(time(NULL));

	for (int i = 0; i < Constants::BLOCK_COUNT_X; i++)
	{
		for (int j = 0; j < Constants::BLOCK_COUNT_Y; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}

			int random = rand();

			if (random % 3 == 0)
			{
				_coins.push_back(std::make_shared<Coin>(_blocks[i][j]));
			}
		}
	}			

	float y = _blocks[_blocks.size() - 1][0]->GetPosition().y - blockSize.y - blockSize.y;

	//ENEMY
	for (int i = 0; i < Constants::BLOCK_COUNT_X; i++)
	{
		for (int j = 0; j < Constants::BLOCK_COUNT_Y; j++)
		{
			if (i == 4 && j == 0)
			{
				continue;
			}

			int random = rand();

			if (rand() % 3 == 0)
			{
				_enemies.push_back(std::make_shared<Enemy>(_blocks[i][j], i));
			}
		}
	}
	//PLAYER
	_player = std::make_shared<Player>(0, y);

	_player->PlaceAtBlock(_blocks[4][0], Orientation::UP);
}

EntityManager::~EntityManager() {}

bool EntityManager::CheckCollisionsWithLeftWall()
{
	sf::Vector2f movement = _player->GetMovement(Orientation::LEFT);
	
	float playerX = movement.x + _player->GetPosition().x;

	return playerX < 0;
}

bool EntityManager::CheckCollisionsWithRightWall()
{
	sf::Vector2f movement = _player->GetMovement(Orientation::RIGHT);

	float playerX = movement.x + _player->GetPosition().x + _player->GetSize().x;

	return playerX > Constants::WINDOW_WIDTH;
}

bool EntityManager::CheckCollisionsWithUpperLadder()
{
	if (_player->GetFloor() == 0)
	{
		return false;
	}

	float ladderX = _ladders[_player->GetFloor() - 1]->GetPosition().x;
	float diffX = fabsf(_player->GetPosition().x - ladderX);

	return diffX <= 10;
}

bool EntityManager::CheckCollisionsWithLowerLadder()
{
	if (_player->GetFloor() == _blocks.size() - 1)
	{
		return false;
	}

	float ladderX = _ladders[_player->GetFloor()]->GetPosition().x;
	float diffX = fabsf(_player->GetPosition().x - ladderX);

	return diffX <= 10;
}

bool EntityManager::CheckCollisionsWithUpperFloor()
{
	if (_player->GetFoot() < this->GetUpperBlockY())
	{
		_player->FloorUp();
		_player->PlaceAtBlock(_blocks[_player->GetFloor()][0], Orientation::UP);
			
		return true;
	}

	return false;
}

bool EntityManager::CheckCollisionsWithCurrentFloor()
{
	if (_player->GetFloor() == 0)
	{
		return true;
	}

	float playerY = _player->GetFoot();
	float blockY = this->GetCurrentBlockY();

	float diffY = fabsf(playerY - blockY);

	return diffY <= 10;
}

bool EntityManager::CheckCollisionsWithLowerFloor()
{
	if (_player->GetFoot() >= this->GetLowerBlockY())
	{
		_player->FloorDown();
		_player->PlaceAtBlock(_blocks[_player->GetFloor()][0], Orientation::DOWN);

		return true;
	}

	return false;
}

float EntityManager::GetUpperBlockY()
{
	if (_player->GetFloor() == 0)
	{
		return _blocks[0][0]->GetPosition().y;
	}

	return _blocks[_player->GetFloor()  - 1][0]->GetPosition().y;
}

float EntityManager::GetCurrentBlockY()
{
	return _blocks[_player->GetFloor()][0]->GetPosition().y;
}

float EntityManager::GetLowerBlockY()
{
	if (_player->GetFloor() == _blocks.size() - 1)
	{
		return _blocks[4][0]->GetPosition().y;
	}

	return _blocks[_player->GetFloor() + 1][0]->GetPosition().y;
}

void EntityManager::HandleCollisionsWithCoins()
{
	float playerX = _player->GetPosition().x + _player->GetSize().x;
	float playerY = _player->GetFoot();

	for (auto coin : _coins)
	{
		if (coin->IsDisplayed())
		{
			float coinX = coin->GetPosition().x;
			float coinX2 = coinX + coin->GetSize().x;
			float coinY = coin->GetPosition().y + coin->GetSize().y;

			float diffY = fabsf(playerY - coinY);

			if (playerX > coinX && playerX < coinX2 && diffY <= 10)
			{
				_player->AddOneCoin();
				coin->SetUndisplayed();
			}
		}
	}
}

void EntityManager::CheckCollisionsWithGoal()
{
	float playerX = _player->GetPosition().x + _player->GetSize().x;
	float playerY = _player->GetFoot();

	float goalX = _goal->GetPosition().x;
	float goalX2 = goalX + _goal->GetSize().x;
	float goalY = _goal->GetPosition().y + _goal->GetSize().y;

	float diffY = fabsf(playerY - goalY);

	if (playerX > goalX && playerX < goalX2 && diffY <= 10)
	{
		_goal->DoorMovement(_player);
		_player->SetUndisplayed();
		_win = true;
	}
}

void EntityManager::CheckCollisionsWithEnemy()
{
	for (auto enemy : _enemies)
	{
		float playerX = _player->GetPosition().x + _player->GetSize().x;
		float playerY = _player->GetFoot();

		float enemyX = enemy->GetPosition().x;
		float enemyX2 = enemyX + enemy->GetSize().x;
		float enemyY = enemy->GetPosition().y + enemy->GetSize().y;

		float diffY = fabsf(playerY - enemyY);

		if (enemy->IsDisplayed() && playerX > enemyX && playerX < enemyX2 && diffY <= 10)
		{
			_player->SetUndisplayed();
			_killed = true;
			return;
		}
	}
}

void EntityManager::Attack()
{	
	int index = -1;

	switch (_player->GetProfil())
	{
		case Orientation::LEFT:
			for (auto enemy : _enemies)
			{
				if (_player->GetFloor() == enemy->GetFloor() && enemy->IsDisplayed() && _player->GetPosition().x > enemy->GetPosition().x)
				{
					index++;
				}
			}

			if (index != -1)
			{
				for (auto enemy : _enemies) {
					if (enemy->GetFloor() < _player->GetFloor()) {
						index++;
					}
				}

				_enemies[index]->TriggerAnimation();
			}

			break;
		case Orientation::RIGHT:
			for (auto enemy : _enemies)
			{
				if (_player->GetFloor() == enemy->GetFloor() && enemy->IsDisplayed() && _player->GetPosition().x < enemy->GetPosition().x)
				{
					enemy->TriggerAnimation();
					return;
				}
			}
			break;
	}
}