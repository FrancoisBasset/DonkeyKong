#include "pch.h"
#include "StringHelpers.h"
#include "Game.h"
#include "EntityManager.h"

Game::Game()
	: _renderWindow(sf::VideoMode(840, 600), "Donkey Kong 2019", sf::Style::Close)
	, _entityManager()
	, _font()
	, _statisticsText()
	, _statisticsUpdateTime()
	, _statisticsNumFrames(0)
{
	_renderWindow.setFramerateLimit(160);

	/*_font.loadFromFile("Media/Sansation.ttf");
	_statisticsText.setString("Welcome to Donkey Kong 1981");
	_statisticsText.setFont(_font);
	_statisticsText.setPosition(5.f, 5.f);
	_statisticsText.setCharacterSize(10);*/
}

Game::~Game()
{

}

void Game::Run()
{
	//sf::Clock clock;
	//sf::Time timeSinceLastUpdate = sf::Time::Zero;
	
	int ok = 0;
	
	while (_renderWindow.isOpen())
	{
		//sf::Time elapsedTime = clock.restart();
		//timeSinceLastUpdate += elapsedTime;
		//while (timeSinceLastUpdate > Constants::TIME_PER_FRAME())
		//{
			//timeSinceLastUpdate -= Constants::TIME_PER_FRAME();

			ProcessEvents();
			//update(Constants::TIME_PER_FRAME());
		//}

		//updateStatistics(elapsedTime);
		if (_entityManager.checkCollisionsWithLadder()) {
			std::cout << ok << " OK" << std::endl;
			ok++;
		}

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

	_renderWindow.draw(_entityManager.GetPlayer()->GetSprite());

	_renderWindow.draw(_statisticsText);

	_renderWindow.display();
}

void Game::UpdateStatistics(sf::Time elapsedTime)
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

void Game::HandlePlayerInput(sf::Keyboard::Key key)
{
	if (key == sf::Keyboard::Up) {
		_entityManager.GetPlayer()->move(Orientation::UP);
	}
	else if (key == sf::Keyboard::Down) {
		_entityManager.GetPlayer()->move(Orientation::DOWN);
	}
	else if (key == sf::Keyboard::Left) {
		_entityManager.GetPlayer()->move(Orientation::LEFT);
	}
	else if (key == sf::Keyboard::Right) {
		_entityManager.GetPlayer()->move(Orientation::RIGHT);
	}
	else if (key == sf::Keyboard::Space) {
		std::cout << "Attack";
	}
}
