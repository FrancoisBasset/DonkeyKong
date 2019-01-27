#include "pch.h"
#include "EntityManager.h"

EntityManager::EntityManager()
{
	for (int i = 0; i < Constants::BLOCK_COUNT_X; i++) {
		_blocks.push_back(std::vector<std::shared_ptr<Block>>());		

		for (int j = 0; j < Constants::BLOCK_COUNT_Y; j++) {
			float x = 70.f * (j + 1) - 70.f;
			float y = 0.f + Constants::BLOCK_SPACE() * (i + 1);

			_blocks[i].push_back(std::make_shared<Block>(x, y));
		}		
	}

	sf::Vector2u blockSize = _blocks[0][0]->GetSize();

	for (int i = 0; i < Constants::LADDER_COUNT; i++)
	{
		float x = 100.f + 70.f * (i + 1);
		float y = 0.f + Constants::BLOCK_SPACE() * (i + 1) + blockSize.y;

		_ladders.push_back(std::make_shared<Ladder>(x, y));		
	}

	float y = _blocks[_blocks.size() - 1][0]->GetPosition().y;

	_player = std::make_shared<Player>(0, y);

	sf::Vector2f n(0, 0 - _player->GetSize().y);
	std::cout << n.y;

	_player->GetSprite().move(n);
}

EntityManager::~EntityManager()
{
}

bool EntityManager::checkCollisionsWithLadder() {
	float lx = _ladders[_ladders.size() - 1]->GetPosition().x;

	float diffX = fabsf(_player->GetPosition().x - lx);

	//std::cout << diffX << "-" << diffY << std::endl;

	return diffX <= 10;
}