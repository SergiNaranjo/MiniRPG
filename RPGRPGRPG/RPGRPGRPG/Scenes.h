#pragma once
#include "Consts.h"

enum Scenes {DUNGEON, COMBAT, CHEST, GAMEOVER};

struct Scene
{
	Scenes currentScene;
	int enemyCount = rand() % (MAX_ENEMIES - MIN_ENEMIES + 1) + MIN_ENEMIES;
	void Dungeon(Scene& scene, int &enemyCount);
	void Combat(Scene& manager);
	void Chest(Scene& manager);
	void GameOver(Scene& manager);
};


