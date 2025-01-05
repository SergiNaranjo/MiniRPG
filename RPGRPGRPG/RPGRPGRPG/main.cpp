#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"
#include "Scenes.h"
#include "Map.h"

void PrintDungeon(Scene& scene, int &enemyCount);
void PrintCombat(Scene& scene);
void PrintChest(Scene& scene);
void PrintGameOver(Scene& scene);

void main()
{
	Scene manager;
	manager.currentScene = DUNGEON;
	

	while (true)
	{
		switch (manager.currentScene)
		{
		case DUNGEON:
			PrintDungeon(manager, manager.enemyCount);
			break;
		case COMBAT:
			PrintCombat(manager);
			break;
		case CHEST:
			PrintChest(manager);
			break;
		case GAMEOVER:
			PrintGameOver(manager);
			break;
		}
	}
	
}

void PrintDungeon(Scene& scene, int &enemyCount)
{
	scene.Dungeon(scene, enemyCount);
}

void PrintCombat(Scene& scene)
{
	scene.Combat(scene);
}

void PrintChest(Scene& scene)
{
	scene.Chest(scene);
}

void PrintGameOver(Scene& scene)
{
	scene.GameOver(scene);
}