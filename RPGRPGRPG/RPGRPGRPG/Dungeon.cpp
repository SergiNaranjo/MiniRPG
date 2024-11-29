#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"

void PrintMap(char map[ROWS][COLS])
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			printf("%c", map[i][j]);
		}
		printf("\n");
	}
}

void Dungeon()
{
	char map[ROWS][COLS];

	// DUNGEON
	Player stats;

	stats.health = rand() % (MAX_HP_PLAYER - 1 - MIN_HP_PLAYER) + MIN_HP_ENEMY;
	int actualHealth = stats.health;
	stats.potions = MAX_POTIONS;
	stats.agility = MAX_AGILITY;

	printf("------DUNGEON------\n");
	printf("\n");

	printf("Player -> P   Enemy -> E  Chest -> C\n");
	printf("\n");

	printf("Health: %d / %d\n", actualHealth, stats.health);
	printf("Potions: %d / %d\n", stats.potions, MAX_POTIONS);
	printf("Moves: %d / %d\n", stats.agility, MAX_AGILITY);
	printf("\n");

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			map[i][j] = ' ';
		}
	}

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (i % 4 == 0)
			{
				if (j % 4 != 3)
				{
					map[i][j] = '-';
				}
			}
			else if (j % 4 == 0)
			{
				map[i][j] = '|';
			}
		}
	}

	PrintMap(map);


	printf("\n");
	printf("-------------------\n");
	printf("\n");
	printf("WASD -> Move\n");
	printf("P -> Potion\n");
	printf("\n");
	printf("Enter your action\n");
}