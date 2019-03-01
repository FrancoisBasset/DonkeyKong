#pragma once

#include "Block.h"

class Enemy : public Entity
{

public:
	Enemy(std::shared_ptr<Block> block, int floor);
	~Enemy();

private:
	int _floor;

	int _rect = -1;
	std::vector<std::vector<int>> _rects = {
		{18, 204, 43, 56},
		{132, 202, 50, 61},
		{242, 199, 63, 65}
	};

public:
	void TriggerAnimation();
	void AnimationUpdate();

	int GetFloor()
	{
		return _floor;
	}

};