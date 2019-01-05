#pragma once
#include "Entity.h"
#include "IMovable.h"
#include "Constants.h"
class CHero : public IMovable
{
public:
	~CHero();
	CHero()
	{
		ammoLeft = 0;
		orientation = EOrientation::RIGHT;
		initDisplay();
		
		
	}

private:
	int ammoLeft;
	EOrientation orientation;
	sf::IntRect spriteMode;
	sf::Sprite playerDisplay;

public:
	void AddAmmo();
	void RemoveAmmo();

protected:

public:
	void initDisplay() {
		sf::Texture texture;
		texture.loadFromFile(Constants::SPRITESHEET_ADRESS());
		playerDisplay.setTexture(texture);
		playerDisplay.setTextureRect(spriteMode = sf::IntRect(Constants::SPRITE_LEFT, Constants::SPRITE_TOP, Constants::SPRITE_WIDTH, Constants::SPRITE_LENGHT));
	};
	void moveRight() {
		this->movement.x = this->movement.x += moveSpeed;
		this->movement.y = this->movement.y += moveSpeed;

		spriteMode.left += Constants::SPRITE_WIDTH;

	};

};



