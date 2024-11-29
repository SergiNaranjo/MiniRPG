#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"

void main()
{
	srand(time(NULL));
	char map[COLS][ROWS];
	Player stats;

	stats.health = rand() % (110 - 1 - 90) + 90;
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

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			map[i][j] = '-';
		}
	}

	for (int i = 0; i < COLS; i++)
	{
		for (int j = 0; j < ROWS; j++)
		{
			printf("%c ", map[i][j]);
		}

		printf("\n");
	}

	printf("\n");
	printf("-------------------\n");
	printf("\n");
	printf("WASD -> Move\n");
	printf("P -> Potion\n");
	printf("\n");
	printf("Enter your action\n");

}