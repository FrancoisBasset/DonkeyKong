#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "pch.h"

#include "Game.h"

int main()
{
	while (true) {
		Game game;
		game.Run();

		if (game.RequestClose()) {
			break;
		}
	}
}