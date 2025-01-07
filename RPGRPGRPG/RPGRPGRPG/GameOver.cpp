#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include "Scenes.h"
#include "Character.h"

void Scene::GameOver(Scene& scene, Player &playerStats)
{
	while (true)
	{
		system("cls");

		if (playerStats.isDead == true)
		{
			printf("  > YOU LOST! Radev's laughing right now. Your final score is: %d\n", playerStats.gold);
			printf("Thanks for playing :)\n");
		}
		else if (playerStats.isDead == false)
		{
			printf("  > YOU WON! Radev's minions are no more. Your final score is: %d\n", playerStats.gold);
			printf("Thanks for playing :)\n");
		}
		system("pause");
		exit(0);
	}
	
}