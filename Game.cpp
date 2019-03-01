#include "pch.h"
#include "StringHelpers.h"
#include "Game.h"
#include "EntityManager.h"

Game::Game()
	: _renderWindow(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), "Winnie et ses amis", sf::Style::Close)
	, _entityManager()
	, _font()
	, _time()
	, _timeText()
	, _coinsText()
	, _endText()
{
	_renderWindow.setFramerateLimit(160);

	_font.loadFromFile("Media/Sansation.ttf");

	_timeText.setFont(_font);
	_timeText.setPosition(300.f, 5.f);
	_timeText.setCharacterSize(20);

	_coinsText.setString("Coins 0 / " + toString(_entityManager.GetCoins().size()));
	_coinsText.setFont(_font);
	_coinsText.setPosition(5.f, 5.f);
	_coinsText.setCharacterSize(20);
}

Game::~Game() {}

void Game::Run()
{
	sf::Clock clock;
	
	while (_renderWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		
		ProcessEvents();		
		UpdateText(elapsedTime);
		Render();

		if (_entityManager.Win())
		{
			_endText.setFont(_font);
			_endText.setFillColor(sf::Color::Cyan);

			float score = (float) _entityManager.GetPlayer()->GetCoins() / this->_time.asSeconds() * 100;

			_endText.setString("Le score est de " + toString((int) score));
			_endText.setCharacterSize(80);

			float x = Constants::WINDOW_WIDTH / 2 - (_endText.getLocalBounds().width / 2);
			float y = Constants::WINDOW_HEIGHT / 2 - (_endText.getLocalBounds().height / 2);

			_endText.setPosition(sf::Vector2f(x, y));

			_renderWindow.draw(_endText);
			_renderWindow.display();

			Sleep(2000);
			_renderWindow.close();
		}

		if (_entityManager.Killed())
		{			
			_endText.setFont(_font);
			_endText.setFillColor(sf::Color::Red);
			_endText.setString("Game over !");
			_endText.setCharacterSize(80);

			float x = Constants::WINDOW_WIDTH / 2 - (_endText.getLocalBounds().width / 2);
			float y = Constants::WINDOW_HEIGHT / 2 - (_endText.getLocalBounds().height / 2);

			_endText.setPosition(sf::Vector2f(x, y));

			_renderWindow.draw(_endText);
			_renderWindow.display();
				
			Sleep(2000);
			_renderWindow.close();
		}
	}
}

void Game::ProcessEvents()
{
	sf::Event event;
	while (_renderWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				HandlePlayerInput(event.key.code);
				break;
			case sf::Event::Closed:
				_renderWindow.close();
				_requestClose = true;
				break;
		}
	}
}

void Game::Render()
{
	_renderWindow.clear();

	for (int x = 0; x < Constants::BLOCK_COUNT_X; x++)
	{
		for (int y = 0; y < Constants::BLOCK_COUNT_Y; y++)
		{
			_renderWindow.draw(_entityManager.GetBlocks()[x][y]->GetSprite());
		}
	}

	for (auto ladder : _entityManager.GetLadders())
	{
		_renderWindow.draw(ladder->GetSprite());
	}		

	for (auto coin : _entityManager.GetCoins())
	{
		if (coin->IsDisplayed())
		{
			_renderWindow.draw(coin->GetSprite());
		}
	}

	for (auto enemy : _entityManager.GetEnemies())
	{
		if (enemy->IsDisplayed())
		{
			enemy->AnimationUpdate();
			_renderWindow.draw(enemy->GetSprite());
		}
	}

	_renderWindow.draw(_entityManager.GetGoal()->GetSprite());

	if (_entityManager.GetPlayer()->IsDisplayed())
	{
		_renderWindow.draw(_entityManager.GetPlayer()->GetSprite());
	}

	_renderWindow.draw(_timeText);
	_renderWindow.draw(_coinsText);

	_renderWindow.draw(_endText);
	
	_renderWindow.display();
}

void Game::UpdateText(sf::Time elapsedTime)
{
	_time += elapsedTime;

	_timeText.setString("Time = " + toString((int)_time.asSeconds()) + " s");	
	_coinsText.setString("Coins " + toString(_entityManager.GetPlayer()->GetCoins()) + " / " + toString(_entityManager.GetCoins().size()));
}

void Game::HandlePlayerInput(sf::Keyboard::Key key)
{
	//_entityManager.CheckCollisionsWithUpperLadder();
	//_entityManager.CheckCollisionsWithLowerLadder();

	

	if (key == sf::Keyboard::Up)
	{
		if (_entityManager.CheckCollisionsWithUpperLadder())
		{
			if (!_entityManager.CheckCollisionsWithUpperFloor())
			{
				_entityManager.GetPlayer()->Move(Orientation::UP);
			}
		}
	}
	else if (key == sf::Keyboard::Down)
	{
		if (_entityManager.CheckCollisionsWithLowerLadder())
		{
			if (!_entityManager.CheckCollisionsWithLowerFloor())
			{
				_entityManager.GetPlayer()->Move(Orientation::DOWN);
			}
		}
	}
	else if (key == sf::Keyboard::Left)
	{
		_entityManager.GetPlayer()->ProfilToLeft();

		if (!_entityManager.CheckCollisionsWithLeftWall())
		{
			if (_entityManager.CheckCollisionsWithCurrentFloor())
			{
				_entityManager.GetPlayer()->Move(Orientation::LEFT);
			}
		}
	}
	else if (key == sf::Keyboard::Right)
	{
		_entityManager.GetPlayer()->ProfilToRight();
		_entityManager.GetPlayer()->AnimationUpdate();

		if (!_entityManager.CheckCollisionsWithRightWall())
		{
			if (_entityManager.CheckCollisionsWithCurrentFloor())
			{
				_entityManager.GetPlayer()->Move(Orientation::RIGHT);
			}
		}
	}
	else if (key == sf::Keyboard::Space)
	{
		_entityManager.Attack();
	}

	_entityManager.HandleCollisionsWithCoins();
	_entityManager.CheckCollisionsWithGoal();

	_entityManager.CheckCollisionsWithEnemy();
}