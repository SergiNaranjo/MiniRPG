#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"
#include "Scenes.h"
#include "Map.h"

void PrintDungeon();
void PrintCombat();
void PrintChest();

void main()
{
	srand(time(NULL));

	Scene manager;

	manager.currentScene = DUNGEON;

	while (true)
	{
		system("cls");
		switch (manager.currentScene)
		{
		case DUNGEON:
			PrintDungeon();
			break;
		case COMBAT:
			PrintCombat();
			break;
		case CHEST:
			PrintChest();
			break;
		}
		system("pause");
	}
	
}

void PrintDungeon()
{
	Scene scene;

	scene.Dungeon();
}

void PrintCombat()
{
	Scene scene;

	scene.Combat();
}

void PrintChest()
{
	Scene scene;

	scene.Chest();
}