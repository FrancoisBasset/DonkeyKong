#pragma once
class Constants
{
public:
	Constants();
	~Constants();

public:
	static const int SPRITE_WIDTH = 32;
	static const int SPRITE_LENGHT = 64;
	static const int SPRITE_LEFT = 6;
	static const int SPRITE_TOP = 28;

public:
	static const std::string SPRITESHEET_ADRESS() {
		return  "Media/Textures/kim.png";
	};
};

