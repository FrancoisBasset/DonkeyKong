#pragma once

#include "pch.h"
#include "EntityType.h"

class Entity {

public:
	Entity(std::string spriteSheet, float x, float y, sf::Color color);
	~Entity();

protected:	
	sf::Image _image;
	sf::Texture _texture;
	sf::Sprite _sprite;
	EntityType _type;
	bool _displayed = true;

public:
	void SetUndisplayed();

	bool IsDisplayed()
	{
		return _displayed;
	}

	sf::Sprite GetSprite()
	{
		return _sprite;
	}

	sf::Vector2u GetSize()
	{
		return sf::Vector2u(this->GetSprite().getTextureRect().width, this->GetSprite().getTextureRect().height);
	}

	sf::Vector2f GetPosition()
	{
		return _sprite.getPosition();
	}

	void PlaceAtBlock(std::shared_ptr<Entity> block)
	{
		float x = block->GetPosition().x;
		float y = block->GetPosition().y - this->GetSize().y;

		_sprite.move(sf::Vector2f(x, y));
	}
};