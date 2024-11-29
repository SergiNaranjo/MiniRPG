#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"

void main()
{
	srand(time(NULL));

	Enemy stats;

	stats.health = rand() % (MAX_HP_ENEMY - 1 - MIN_HP_ENEMY) + MIN_HP_ENEMY;
	int actualEnemyHealth = stats.health;
	stats.stamina = rand() % (MAX_STAMINA_ENEMY - 1 - MIN_STAMINA_ENEMY) + MIN_STAMINA_ENEMY;
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
	
	printf("%d Stamina", stats.stamina);
}