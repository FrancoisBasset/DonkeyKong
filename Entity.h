#pragma once

#include "pch.h"
#include "EntityType.h"

class Entity {

public:
	Entity(std::string spriteSheet, float x, float y);
	~Entity();

public:	
	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;
	bool _displayed = true;
	EntityType _type;
	

	// Enemy only
	//bool m_bLeftToRight = true;
	//int m_times = 0;

public:
	/*virtual int Draw() {
		return 0;
	};*/

	sf::Vector2u GetSize() {
		return _sprite.getTexture()->getSize();
	}

	sf::Vector2f GetPosition() {
		return _sprite.getPosition();
	}
};

