#pragma once
class Constants
{

public:
	static const int WINDOW_WIDTH = 1400;
	static const int WINDOW_HEIGHT = 600;
	
	static const int LADDER_COUNT = 4;
	static const int BLOCK_COUNT_X = 5;
	static const int BLOCK_COUNT_Y = 20;

public:
	static const float BLOCK_SPACE()
	{
		return 110.f;
	}

	static const sf::Time TIME_PER_FRAME()
	{
		return sf::seconds(1.f / 60.f);
	}
};