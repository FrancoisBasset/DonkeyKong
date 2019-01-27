#pragma once

#include "Constants.h"
#include "Player.h"
#include "Block.h"
#include "Ladder.h"
#include "EntityManager.h"

class Game
{

public:
	Game();
	~Game();
	void Run();

private:
	void ProcessEvents();
	//void update(sf::Time elapsedTime);
	
	void Render();

	void UpdateStatistics(sf::Time elapsedTime);
	void HandlePlayerInput(sf::Keyboard::Key key);

private:
	sf::RenderWindow	_renderWindow;

	//std::shared_ptr<Player> _player;

	EntityManager _entityManager;

	sf::Font	_font;
	sf::Text	_statisticsText;
	sf::Time	_statisticsUpdateTime;

	std::size_t	_statisticsNumFrames;
	/*bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;*/

	sf::Texture	_ladderTexture;
	sf::Sprite	_ladders[Constants::LADDER_COUNT];

	//sf::Vector2u blockSize;
	sf::Sprite	_blocks[Constants::BLOCK_COUNT_X][Constants::BLOCK_COUNT_Y];

	sf::Texture	_weaponTexture;
	sf::Sprite	_weapon;
};

