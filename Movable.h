#include "pch.h"

#include "Entity.h"
#include "Orientation.h"
#include "Constants.h"
#include "Block.h"

class Movable : public Entity
{

public:
	Movable(std::string spriteSheet, float x, float y, sf::Color color);
	~Movable();

public:
	void Move(Orientation orientation);
	sf::Vector2f GetMovement(Orientation Orientation);
	void PlaceAtBlock(std::shared_ptr<Block> block, Orientation orientation);

};