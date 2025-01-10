#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"
#include "Scenes.h"

void Scene::Combat(Scene& manager, Player &playerStats)
{
	Enemy stats;
	

	char action;

	stats.isDead = false;

	while (stats.isDead == false)
	{
		system("cls");

		printf("------COMBAT------\n");
		printf("\n");

		// STATS ENEMIGO

		printf("--Enemy--\n");
		if (stats.actualEnemyHealth > stats.health / 2)
		{
			printf("[ = = = = = = ] ? / ? HP\n");
		}
		else if (stats.actualEnemyHealth <= stats.health / 2 && stats.actualEnemyHealth >= stats.health / 3)
		{
			printf("[ = = = ] ? / ? HP\n");
		}
		else if (stats.actualEnemyHealth <= stats.health / 3 && stats.actualEnemyHealth > 0)
		{
			printf("[ = ] ? / ? HP\n");
		}
		else if (stats.actualEnemyHealth <= 0)
		{
			manager.currentScene = DUNGEON;
		}

		if (manager.currentScene == DUNGEON)
		{
			break; 
		}

		if (stats.actualEnemyStamina > stats.stamina / 2)
		{
			printf("[ < < < < < < ] ? / ? Stamina\n");
		}
		else if (stats.actualEnemyStamina <= stats.stamina / 2 && stats.actualEnemyStamina >= stats.stamina / 3)
		{
			printf("[ < < < ] ? / ? Stamina\n");
		}
		else if (stats.actualEnemyStamina <= stats.stamina / 3 && stats.actualEnemyStamina > 0)
		{
			printf("[ < ] ? / ? Stamina\n");
		}
		else if (stats.actualEnemyStamina <= 0)
		{
			printf("[  ] %d / ? Stamina\n", stats.actualEnemyStamina);
		}

		// STATS JUGADOR

		printf("\n--Player--\n");
		if (playerStats.actualHealth > playerStats.health / 2)
		{
			printf("[ = = = = = = ] %d / %d HP\n", playerStats.actualHealth, playerStats.health);
		}
		else if (playerStats.actualHealth <= playerStats.health / 2 && playerStats.actualHealth >= playerStats.health / 3)
		{
			printf("[ = = = ] %d / %d HP\n", playerStats.actualHealth, playerStats.health);
		}
		else if (playerStats.actualHealth <= playerStats.health / 3 && playerStats.actualHealth > 0)
		{
			printf("[ = ] %d / %d HP\n", playerStats.actualHealth, playerStats.health);
		}
		else if (playerStats.actualHealth <= 0)
		{
			playerStats.isDead = true;
			manager.currentScene = GAMEOVER;
		}

		if (manager.currentScene == GAMEOVER)
		{
			break;
		}

		if (playerStats.actualStamina > playerStats.stamina / 2)
		{
			printf("[ < < < < < < ] %d / %d Stamina\n", playerStats.actualStamina, playerStats.stamina);
		}
		else if (playerStats.actualStamina <= playerStats.stamina / 2 && playerStats.actualStamina >= playerStats.stamina / 3)
		{
			printf("[ < < < ] %d / %d Stamina\n", playerStats.actualStamina, playerStats.stamina);
		}
		else if (playerStats.actualStamina <= playerStats.stamina / 3 && playerStats.actualStamina > 0)
		{
			printf("[ < ] %d / %d Stamina\n", playerStats.actualStamina, playerStats.stamina);
		}
		else if (playerStats.actualStamina <= 0)
		{
			printf("[  ] %d / %d Stamina\n", playerStats.actualStamina, playerStats.stamina);
		}

		printf("\nPotions: %d / %d\n", playerStats.actualPotions, playerStats.potions);
		printf("\n----------------------\n");

		printf("A -> Attack\n");
		printf("D -> Defend\n");
		printf("R -> Rest\n");
		printf("P -> Potion\n");
		printf("\nEnter your action: ");

		scanf_s(" %c", &action, 2); 
		printf("\n");

		int enemyAttack = rand() % stats.actualEnemyStamina;
		int reducedDamage;

		switch (action)
		{
		case 'A':

			int attackValue;
			printf("Enter attack value (max %d): ", playerStats.actualStamina);

			if (scanf_s("%d", &attackValue) == 1 && attackValue > 0 && attackValue <= playerStats.actualStamina)
			{
				printf("You strike the enemy with force! The enemy receives %d of damage.\n", attackValue);

				playerStats.actualStamina -= attackValue;
				stats.actualEnemyHealth -= attackValue;
				
				if (stats.actualEnemyStamina <= 0)
				{
					stats.actualEnemyStamina = stats.stamina;
				}
				else if (stats.actualEnemyStamina > 0)
				{
					playerStats.actualHealth -= enemyAttack;
					stats.actualEnemyStamina -= enemyAttack;
				}
			}
			else
			{
				printf("Invalid attack value. Ensure it's between 1 and %d.\n", playerStats.actualStamina);
			}
			break;

		case 'D':
			printf("You defended correctly. Damage has decreased and stamina has recovered.\n");

			// Restaurar estamina del jugador
			playerStats.actualStamina = playerStats.stamina;

			// Calcular daño enemigo reducido (75% del ataque enemigo)
			reducedDamage = (enemyAttack * 75) / 100; // Cálculo usando división entera


			if (stats.actualEnemyStamina <= 0)
			{
				stats.actualEnemyStamina = stats.stamina;
			}
			else if (stats.actualEnemyStamina > 0)
			{
				playerStats.actualHealth -= reducedDamage;
				stats.actualEnemyStamina -= enemyAttack;
			}
			
			
			break;

		case 'R':

			printf("Your stamina is fully recovered. You are vulnerable now.\n");
			playerStats.actualStamina = playerStats.stamina;

			if (stats.actualEnemyStamina <= 0)
			{
				stats.actualEnemyStamina = stats.stamina;
			}
			else if (stats.actualEnemyStamina > 0)
			{
				playerStats.actualHealth -= enemyAttack;
				stats.actualEnemyStamina -= enemyAttack;
			}
			
			break;

		case 'P':
			if (playerStats.actualPotions > 0)
			{
				printf("You used a Potion to restore.\n");
				playerStats.actualPotions--;
				playerStats.actualHealth = playerStats.health; 
			}
			else
			{
				printf("No potions left!\n");
			}
			break;

		default:

			printf("Invalid action. Please select A, D, R, or P.\n");
		}

		system("pause");
	}
}
