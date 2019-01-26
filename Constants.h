#pragma once
class Constants
{

public:
	static const int SPRITE_WIDTH = 32;
	static const int SPRITE_LENGTH = 64;
	static const int SPRITE_LEFT = 6;
	static const int SPRITE_TOP = 28;

	static const int LADDER_COUNT = 4;
	static const int BLOCK_COUNT_X = 12;
	static const int BLOCK_COUNT_Y = 5;

public:
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
		return  "Media/Textures/kim.png";
	};

	static const std::string BLOCK_SPRITESHEET() {
		return "Media/Textures/Block.png";
	}

	static const std::string LADDER_SPRITESHEET() {
		return "Media/Textures/Ladder.png";
	}
};

