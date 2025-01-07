#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"
#include "Scenes.h"
#include "Map.h"

void PrintDungeon(Scene& scene, int &enemyCount, Player &stats);
void PrintCombat(Scene& scene, Player &stats);
void PrintChest(Scene& scene, Player &stats);
void PrintGameOver(Scene& scene, Player &stats);

void main()
{
	Scene manager;
	manager.currentScene = DUNGEON;
	
	Player stats;
	

	while (true)
	{
		switch (manager.currentScene)
		{
		case DUNGEON:
			PrintDungeon(manager, manager.enemyCount, stats);
			break;
		case COMBAT:
			PrintCombat(manager, stats);
			break;
		case CHEST:
			PrintChest(manager, stats);
			break;
		case GAMEOVER:
			PrintGameOver(manager, stats);
			break;
		}
	}
	
}

void PrintDungeon(Scene& scene, int &enemyCount, Player &stats)
{
	scene.Dungeon(scene, enemyCount, stats);
}

void PrintCombat(Scene& scene, Player &stats)
{
	scene.Combat(scene, stats);
}

void PrintChest(Scene& scene, Player& stats)
{
	scene.Chest(scene, stats);
}

void PrintGameOver(Scene& scene, Player& stats)
{
	scene.GameOver(scene, stats);
}