#pragma once
class Constants
{

public:
	static const int WINDOW_WIDTH = 840;
	static const int WINDOW_HEIGHT = 600;

	static const int PLAYER_SPRITE_RIGHT_X = 0;
	static const int PLAYER_SPRITE_RIGHT_Y = 248;
	static const int PLAYER_SPRITE_RIGHT_WIDTH = 18;
	static const int PLAYER_SPRITE_RIGHT_HEIGHT = 40;

	static const int PLAYER_SPRITE_LEFT_X = 0;
	static const int PLAYER_SPRITE_LEFT_Y = 164;
	static const int PLAYER_SPRITE_LEFT_WIDTH = 18;
	static const int PLAYER_SPRITE_LEFT_HEIGHT = 40;
	
	static const int LADDER_COUNT = 4;
	static const int BLOCK_COUNT_X = 5;
	static const int BLOCK_COUNT_Y = 12;

public:
	static const std::string WINDOW_TITLE() {
		return "Donkey Kong 2019";
	}

	static const float BLOCK_SPACE() {
		return 110.f;
	}

	static const float PLAYER_SPEED() {
		return 400.f;
	}

	static const sf::Time TIME_PER_FRAME() {
		return sf::seconds(1.f / 60.f);
	}

public:
	static const std::string PLAYER_SPRITESHEET() {
		return  "Media/Textures/winnie.png";
	};

	static const std::string BLOCK_SPRITESHEET() {
		return "Media/Textures/Block.png";
	}

	static const std::string LADDER_SPRITESHEET() {
		return "Media/Textures/Ladder.png";
	}

	static const std::string COIN_SPRITESHEET() {
		return "Media/Textures/Coin.png";
	}
};

