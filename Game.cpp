#include "pch.h"
#include "StringHelpers.h"
#include "Game.h"
#include "EntityManager.h"

Game::Game()
	: _renderWindow(sf::VideoMode(840, 600), "Donkey Kong 1981", sf::Style::Close)
	, _font()
	, _statisticsText()
	, _statisticsUpdateTime()
	, _statisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
{
	_renderWindow.setFramerateLimit(160);

	for (int i = 0; i < Constants::BLOCK_COUNT_X; i++)
	{
		for (int j = 0; j < Constants::BLOCK_COUNT_Y; j++)
		{
			float x = 70.f * (i + 1) - 70.f;
			float y = 0.f + Constants::BLOCK_SPACE() * (j + 1);

			std::shared_ptr<Block> block = std::make_shared<Block>(x, y);
			EntityManager::m_Entities.push_back(block);
		}
	}

	_ladderTexture.loadFromFile(Constants::LADDER_SPRITESHEET());

	for (int i = 0; i < Constants::LADDER_COUNT; i++)
	{
		/*_ladders[i].setTexture(_ladderTexture);
		_ladders[i].setPosition(100.f + 70.f * (i + 1), 0.f + Constants::BLOCK_SPACE() * (i + 1) + _blockSize.y );*/

		/*std::shared_ptr<Entity> se = std::make_shared<Entity>();
		se->_sprite = _ladders[i];
		se->_type = EntityType::LADDER;
		//se->_size = _ladderTexture.getSize();
		//se->_position = _ladders[i].getPosition();
		EntityManager::m_Entities.push_back(se);*/
	}

	_player = std::make_shared<Player>(50, 50);
	EntityManager::m_Entities.push_back(_player);	

	// Draw Statistic Font 

	_font.loadFromFile("Media/Sansation.ttf");
	_statisticsText.setString("Welcome to Donkey Kong 1981");
	_statisticsText.setFont(_font);
	_statisticsText.setPosition(5.f, 5.f);
	_statisticsText.setCharacterSize(10);
}

Game::~Game()
{
	
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (_renderWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > Constants::TIME_PER_FRAME())
		{
			timeSinceLastUpdate -= Constants::TIME_PER_FRAME();

			processEvents();
			update(Constants::TIME_PER_FRAME());
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (_renderWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			_renderWindow.close();
			break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= Constants::PLAYER_SPEED();
	if (mIsMovingDown)
		movement.y += Constants::PLAYER_SPEED();
	if (mIsMovingLeft)
		movement.x -= Constants::PLAYER_SPEED();
	if (mIsMovingRight)
		movement.x += Constants::PLAYER_SPEED();

	for (std::shared_ptr<Entity> entity : EntityManager::m_Entities)
	{
		if (entity->_displayed == false)
		{
			continue;
		}

		if (entity->_type != EntityType::PLAYER)
		{
			continue;
		}

		entity->_sprite.move(movement * elapsedTime.asSeconds());
	}
}

void Game::render()
{
	_renderWindow.clear();

	for (std::shared_ptr<Entity> entity : EntityManager::m_Entities)
	{
		if (entity->_displayed == false)
		{
			continue;
		}

		_renderWindow.draw(entity->_sprite);
	}

	_renderWindow.draw(_statisticsText);
	_renderWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	_statisticsUpdateTime += elapsedTime;
	_statisticsNumFrames += 1;

	if (_statisticsUpdateTime >= sf::seconds(1.0f))
	{
		_statisticsText.setString(
			"Frames / Second = " + toString(_statisticsNumFrames) + "\n" +
			"Time / Update = " + toString(_statisticsUpdateTime.asMicroseconds() / _statisticsNumFrames) + "us");

		_statisticsUpdateTime -= sf::seconds(1.0f);
		_statisticsNumFrames = 0;
	}

	//
	// Handle collision
	//

	if (_statisticsUpdateTime >= sf::seconds(0.050f))
	{
		// Handle collision weapon enemies
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::Down)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::Left)
		mIsMovingLeft = isPressed;

	else if (key == sf::Keyboard::Right)
		mIsMovingRight = isPressed;

	if (key == sf::Keyboard::Space)
	{
	}
}
