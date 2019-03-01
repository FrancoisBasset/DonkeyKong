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
	
	void Render();

	void UpdateText(sf::Time elapsedTime);
	void HandlePlayerInput(sf::Keyboard::Key key);

private:
	sf::RenderWindow _renderWindow;

	EntityManager _entityManager;

	sf::Font _font;	
	sf::Time _time;

	sf::Text _coinsText;
	sf::Text _timeText;

	sf::Text _endText;

	bool _requestClose = false;

public:
	bool RequestClose() {
		return _requestClose;
	}

};