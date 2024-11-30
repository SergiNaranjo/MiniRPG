#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"


void Combat()
{
	Enemy stats;
	Player playerStats;

	char action;

	printf("------COMBAT------\n");
	printf("\n");

	printf("--Enemy--\n");

	if (stats.actualEnemyHealth == stats.health)
	{
		printf("[ = = = = = = ] %d / %d HP\n", stats.actualEnemyHealth, stats.health);
	}
	else if (stats.actualEnemyHealth == stats.health / 2)
	{
		printf("[ = = = ] %d / %d HP\n", stats.actualEnemyHealth, stats.health);
	}

	if (stats.actualEnemyStamina == stats.stamina)
	{
		printf("[ < < < < < < ] %d / %d Stamina\n", stats.actualEnemyStamina, stats.stamina);
	}
	else if (stats.actualEnemyStamina == stats.stamina / 2)
	{
		printf("[ < < < ] %d / %d Stamina\n", stats.actualEnemyStamina, stats.stamina);
	}

	printf("\n");
	printf("----------------------\n");
	printf("\n");

	printf("--Player--\n");

	if (playerStats.actualHealth == playerStats.health)
	{
		printf("[ = = = = = = ] %d / %d HP\n", playerStats.actualHealth, playerStats.health);
	}
	else if (playerStats.actualHealth == playerStats.health / 2)
	{
		printf("[ = = = ] %d / %d HP\n", playerStats.actualHealth, playerStats.health);
	}

	if (playerStats.actualStamina == playerStats.stamina)
	{
		printf("[ < < < < < < ] %d / %d Stamina\n", playerStats.actualStamina, playerStats.stamina);
	}
	else if (playerStats.actualStamina == playerStats.stamina / 2)
	{
		printf("[ < < < ] %d / %d Stamina\n", playerStats.actualStamina, playerStats.stamina);
	}
	printf("\n");
	printf("Potions: %d / %d\n", playerStats.potions, MAX_POTIONS);
	printf("\n");

	printf("----------------------\n");

	printf("A -> Attack\n");
	printf("D -> Defend\n");
	printf("R -> Rest\n");
	printf("P -> Potion\n");

	printf("\n");
	printf("Enter your action: ");
	scanf_s("%c", &action, 2);
	printf("\n");

	int attackValue;

	switch (action)
	{
	case 'A':
		printf("Enter attack value (max 108): ");
		scanf_s("%d", &attackValue);

		if (attackValue <= 108 && attackValue >= 0)
		{
			printf("You strike the enemy with more force! The enemy receives %d of damage\n", attackValue);
		}
		break;

	case 'D':
		printf("You defended correctly. Damage has decreased and stamina has recovered.\n");
		break;

	case 'R':
		printf("Your stamina is full recovered. You are vulnerable now.\n");
		break;

	case 'P':
		printf("You used a Potion to restore.\n");
		break;
	}
}