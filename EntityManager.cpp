#include "pch.h"
#include "EntityManager.h"

#include <cstdlib>
#include <ctime>

EntityManager::EntityManager()
{
	//BLOCKS
	for (int i = 0; i < Constants::BLOCK_COUNT_X; i++) {
		_blocks.push_back(std::vector<std::shared_ptr<Block>>());		

		for (int j = 0; j < Constants::BLOCK_COUNT_Y; j++) {
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

	// COINS
	srand(time(NULL));

	for (int i = 0; i < Constants::BLOCK_COUNT_X; i++) {
		for (int j = 0; j < Constants::BLOCK_COUNT_Y; j++) {
			int random = rand();

			if (random % 2 == 0) {
				_coins.push_back(std::make_shared<Coin>(_blocks[i][j]));
			}
		}
	}
	
	_coins.push_back(std::make_shared<Coin>(_blocks[4][6]));
	//_coins[0]->PlaceCoinAtBlock(_blocks[0][0]);

	float y = _blocks[_blocks.size() - 1][0]->GetPosition().y - blockSize.y - blockSize.y;

	//PLAYER
	_player = std::make_shared<Player>(0, y);

	_player->PlaceAtBlock(_blocks[4][0], Orientation::UP);

	
}

EntityManager::~EntityManager() {}

bool EntityManager::CheckCollisionsWithLeftWall() {
	sf::Vector2f movement = _player->GetMovement(Orientation::LEFT);
	
	int playerX = movement.x + _player->GetPosition().x;

	return playerX < 0;
}

bool EntityManager::CheckCollisionsWithRightWall() {
	sf::Vector2f movement = _player->GetMovement(Orientation::RIGHT);

	int playerX = movement.x + _player->GetPosition().x + _player->GetSize().x;

	return playerX > Constants::WINDOW_WIDTH;
}

bool EntityManager::CheckCollisionsWithUpperLadder() {
	if (_player->GetFloor() == 0) {
		return false;
	}

	float ladderX = _ladders[_player->GetFloor() - 1]->GetPosition().x;
	float diffX = fabsf(_player->GetPosition().x - ladderX);

	if (diffX <= 10) {
		std::cout << "Upper ladder" << std::endl;
	}

	return diffX <= 10;
}

bool EntityManager::CheckCollisionsWithLowerLadder() {
	if (_player->GetFloor() == _blocks.size() - 1) {
		return false;
	}

	float ladderX = _ladders[_player->GetFloor()]->GetPosition().x;
	float diffX = fabsf(_player->GetPosition().x - ladderX);

	if (diffX <= 10) {
		std::cout << "Lower ladder" << std::endl;
	}

	return diffX <= 10;
}

bool EntityManager::CheckCollisionsWithUpperFloor() {
	if (_player->GetFoot() < this->GetUpperBlockY()) {
		_player->FloorUp();
		_player->PlaceAtBlock(_blocks[_player->GetFloor()][0], Orientation::UP);
			
		return true;
	}

	return false;
}

bool EntityManager::CheckCollisionsWithCurrentFloor() {
	if (_player->GetFloor() == 0) {
		return true;
	}

	float playerY = _player->GetFoot();
	float blockY = this->GetCurrentBlockY();

	float diffY = fabsf(playerY - blockY);

	return diffY <= 10;
}

bool EntityManager::CheckCollisionsWithLowerFloor() {
	if (_player->GetFoot() >= this->GetLowerBlockY()) {
		std::cout << "Floor down" << std::endl;
		_player->FloorDown();
		_player->PlaceAtBlock(_blocks[_player->GetFloor()][0], Orientation::DOWN);

		return true;
	}

	return false;
}

float EntityManager::GetUpperBlockY() {
	if (_player->GetFloor() == 0) {
		return _blocks[0][0]->GetPosition().y;
	}

	return _blocks[_player->GetFloor()  - 1][0]->GetPosition().y;
}

float EntityManager::GetCurrentBlockY() {
	return _blocks[_player->GetFloor()][0]->GetPosition().y;
}

float EntityManager::GetLowerBlockY() {
	if (_player->GetFloor() == _blocks.size() - 1) {
		return _blocks[4][0]->GetPosition().y;
	}

	return _blocks[_player->GetFloor() + 1][0]->GetPosition().y;
}

void EntityManager::HandleCollisionsWithCoins() {
	float playerX = _player->GetPosition().x + _player->GetSize().x;
	float playerY = _player->GetFoot();

	for (int i = 0; i < _coins.size(); i++) {
		if (_coins[i]->IsDisplayed()) {
			float coinX = _coins[i]->GetPosition().x;
			float coinX2 = coinX + _coins[i]->GetSize().x;
			float coinY = _coins[i]->GetPosition().y + _coins[i]->GetSize().y;

			float diffY = fabsf(playerY - coinY);

			if (playerX > coinX && playerX < coinX2 && diffY <= 10) {
				_player->AddOneCoin();
				_coins[i]->SetUndisplayed();

				std::cout << _player->GetCoins() << std::endl;
			}
		}
	}
}