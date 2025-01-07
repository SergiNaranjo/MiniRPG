#pragma once
#include "Consts.h"
#include "Character.h"

enum Scenes {DUNGEON, COMBAT, CHEST, GAMEOVER};

struct Scene
{
	Scenes currentScene;
	int enemyCount = rand() % (MAX_ENEMIES - MIN_ENEMIES + 1) + MIN_ENEMIES;
	void Dungeon(Scene& scene, int &enemyCount, Player &stats);
	void Combat(Scene& manager, Player &stats);
	void Chest(Scene& manager, Player &stats);
	void GameOver(Scene& manager, Player &stats);
};


