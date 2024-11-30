#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"
#include "Dungeon.cpp"

void main()
{
	srand(time(NULL));

	Enemy stats;

	stats.health = rand() % (MAX_HP_ENEMY - 1 - MIN_HP_ENEMY) + MIN_HP_ENEMY;
	int actualEnemyHealth = stats.health;
	stats.stamina = rand() % (MAX_STAMINA_ENEMY - 1 - MIN_STAMINA_ENEMY) + MIN_STAMINA_ENEMY;
	int actualEnemyStamina = stats.stamina;

	printf("------COMBAT------\n");
	printf("\n");

	printf("--Enemy--\n");

	if (actualEnemyHealth == stats.health)
	{
		printf("[ = = = = = = ] %d HP\n", stats.health);
	}
	else if (actualEnemyHealth == stats.health / 2)
	{
		printf("[ = = = ] %d HP\n", stats.health);
	}
	
	if (actualEnemyStamina == stats.stamina)
	{
		printf("[ < < < < < < ] %d Stamina\n", stats.stamina);
	}
	else if (actualEnemyStamina == stats.stamina / 2)
	{
		printf("[ < < < ] %d Stamina\n", stats.stamina);
	}
	
	printf("\n");
	printf("----------------------\n");
	printf("\n");

	printf("--Player--\n");
}