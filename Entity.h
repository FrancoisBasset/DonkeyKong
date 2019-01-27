#pragma once

#include "pch.h"
#include "EntityType.h"

class Entity {

public:
	Entity(std::string spriteSheet, float x, float y);
	~Entity();

protected:	
	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;
	EntityType _type;
	bool _displayed = true;

	// Enemy only
	//bool m_bLeftToRight = true;
	//int m_times = 0;

public:
	sf::Sprite GetSprite() {
		return _sprite;
	}

	bool IsDisplayed() {
		return _displayed;
	}

	sf::Vector2u GetSize() {
		return _sprite.getTexture()->getSize();
	}

	sf::Vector2f GetPosition() {
		return _sprite.getPosition();
	}
};

