#include "pch.h"
#include "Entity.h"
#include "Constants.h"

Entity::Entity(std::string spriteSheet, float x, float y) : _texture()
{
	_image.loadFromFile(spriteSheet);
	_image.createMaskFromColor(sf::Color(203, 217, 217, 255));
	_texture.loadFromImage(_image);
	_sprite.setTexture(_texture);
	_sprite.setPosition(sf::Vector2f(x, y));
}

Entity::~Entity() {
	
	
}