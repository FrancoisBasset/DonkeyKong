#include "pch.h"
#include "CHero.h"


void CHero::AddAmmo()
{
	 this->ammoLeft++;
}

void CHero::RemoveAmmo()
{
	 this->ammoLeft--;
}

void move(EOrientation orientation) {
	switch (orientation)
	{
	case LEFT:
		break;
	case RIGHT:
		moveRight();
		break;
	case UP:
		break;
	default:
		break;
	}
}




