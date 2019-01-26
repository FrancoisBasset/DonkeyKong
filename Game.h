#pragma once

#include "Constants.h"
#include "Player.h"
#include "Block.h"

class Game
{

public:
	Game();
	~Game();
	void run();

private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();

	void updateStatistics(sf::Time elapsedTime);
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
	sf::RenderWindow	_renderWindow;

	std::shared_ptr<Player> _player;

	sf::Font	_font;
	sf::Text	_statisticsText;
	sf::Time	_statisticsUpdateTime;

	std::size_t	_statisticsNumFrames;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;

	sf::Texture	_ladderTexture;
	sf::Sprite	_ladders[Constants::LADDER_COUNT];

	//sf::Texture	_blockTexture;
	sf::Sprite	_blocks[Constants::BLOCK_COUNT_X][Constants::BLOCK_COUNT_Y];

	sf::Texture	_weaponTexture;
	sf::Sprite	_weapon;
};

