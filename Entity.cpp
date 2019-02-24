#include "pch.h"
#include "Entity.h"
#include "Constants.h"

Entity::Entity(std::string spriteSheet, float x, float y, sf::Color color) : _texture()
{
	_image.loadFromFile(spriteSheet);
	_image.createMaskFromColor(color);	
	_texture.loadFromImage(_image);
	_sprite.setTexture(_texture);
	_sprite.setPosition(sf::Vector2f(x, y));
}

Entity::~Entity() {}

void Entity::SetUndisplayed()
{
	_displayed = false;
}