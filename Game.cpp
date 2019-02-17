#include "pch.h"
#include "StringHelpers.h"
#include "Game.h"
#include "EntityManager.h"

Game::Game()
	: _renderWindow(sf::VideoMode(Constants::WINDOW_WIDTH, Constants::WINDOW_HEIGHT), Constants::WINDOW_TITLE(), sf::Style::Close)
	, _entityManager()
	, _font()
	, _statisticsText()
	, _coinsText()
	, _statisticsUpdateTime()
	, _statisticsNumFrames(0)
{
	_renderWindow.setFramerateLimit(160);

	_font.loadFromFile("Media/Sansation.ttf");
	/*_statisticsText.setString("Coins 0");
	_statisticsText.setFont(_font);
	_statisticsText.setPosition(5.f, 5.f);
	_statisticsText.setCharacterSize(10);*/

	_coinsText.setString("Coins 0");
	_coinsText.setFont(_font);
	_coinsText.setPosition(5.f, 5.f);
	_coinsText.setCharacterSize(20);
}

Game::~Game()
{

}

void Game::Run()
{
	sf::Clock clock;
	//sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	int ok = 0;
	
	while (_renderWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		//timeSinceLastUpdate += elapsedTime;
		//while (timeSinceLastUpdate > Constants::TIME_PER_FRAME())
		//{
			//timeSinceLastUpdate -= Constants::TIME_PER_FRAME();

			ProcessEvents();
			//update(Constants::TIME_PER_FRAME());
		//}
		
		UpdateStatistics(elapsedTime);
		//if (_entityManager.CheckCollisionsWithLadder()) {
		//	std::cout << ok << " OK" << std::endl;
			ok++;
		//}

		Render();
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
	
			/*case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code);
				break;*/

			case sf::Event::Closed:
				_renderWindow.close();
				break;
		}
	}
}

void Game::Render()
{
	_renderWindow.clear();

	//isdisplayed

	for (int x = 0; x < Constants::BLOCK_COUNT_X; x++) {
		for (int y = 0; y < Constants::BLOCK_COUNT_Y; y++) {
			_renderWindow.draw(_entityManager.GetBlocks()[x][y]->GetSprite());
		}
	}

	for (int i = 0; i < Constants::LADDER_COUNT; i++) {
		_renderWindow.draw(_entityManager.GetLadders()[i]->GetSprite());
	}		

	for (int i = 0; i < _entityManager.GetCoins().size(); i++) {
		if (_entityManager.GetCoins()[i]->IsDisplayed()) {
			_renderWindow.draw(_entityManager.GetCoins()[i]->GetSprite());
		}
	}

	_renderWindow.draw(_entityManager.GetPlayer()->GetSprite());

	_renderWindow.draw(_statisticsText);
	_renderWindow.draw(_coinsText);

	_renderWindow.display();
}

void Game::UpdateStatistics(sf::Time elapsedTime)
{
	/*_statisticsUpdateTime += elapsedTime;
	_statisticsNumFrames += 1;

	if (_statisticsUpdateTime >= sf::seconds(1.0f))
	{
		_statisticsText.setString(
			"Frames / Second = " + toString(_statisticsNumFrames) + "\n" +
			"Time / Update = " + toString(_statisticsUpdateTime.asMicroseconds() / _statisticsNumFrames) + "us");

		_statisticsUpdateTime -= sf::seconds(1.0f);
		_statisticsNumFrames = 0;
	}*/

	//
	// Handle collision
	//

	/*if (_statisticsUpdateTime >= sf::seconds(0.050f))
	{
		// Handle collision weapon enemies
	}*/

	_coinsText.setString("Coins " + toString(&_entityManager.GetCoins()));
}

void Game::HandlePlayerInput(sf::Keyboard::Key key)
{
	_entityManager.CheckCollisionsWithUpperLadder();
	_entityManager.CheckCollisionsWithLowerLadder();

	if (key == sf::Keyboard::Up) {
		if (_entityManager.CheckCollisionsWithUpperLadder()) {
			if (!_entityManager.CheckCollisionsWithUpperFloor()) {
				_entityManager.GetPlayer()->Move(Orientation::UP);
			}
		}
	}
	else if (key == sf::Keyboard::Down) {
		if (_entityManager.CheckCollisionsWithLowerLadder()) {
			if (!_entityManager.CheckCollisionsWithLowerFloor()) {
				_entityManager.GetPlayer()->Move(Orientation::DOWN);
			}
		}
	}
	else if (key == sf::Keyboard::Left) {
		_entityManager.GetPlayer()->ProfilToLeft();

		if (!_entityManager.CheckCollisionsWithLeftWall()) {
			if (_entityManager.CheckCollisionsWithCurrentFloor()) {
				_entityManager.GetPlayer()->Move(Orientation::LEFT);
			}
		}
	}
	else if (key == sf::Keyboard::Right) {
		_entityManager.GetPlayer()->ProfilToRight();

		if (!_entityManager.CheckCollisionsWithRightWall()) {
			if (_entityManager.CheckCollisionsWithCurrentFloor()) {
				_entityManager.GetPlayer()->Move(Orientation::RIGHT);
			}
		}
	}
	else if (key == sf::Keyboard::Space) {
		std::cout << "Attack";
	}

	_entityManager.HandleCollisionsWithCoins();
}
