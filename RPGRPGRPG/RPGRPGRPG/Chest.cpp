#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Enemy.h"
#include "Scenes.h"

void Scene::Chest(Scene& manager)
{
    while (true)
    {
        system("cls");
        printf("------CHEST------\n");
        printf("\n");

        printf(" > You open the chest and it contains the following: \n");
        printf("\n");

        int hasPotion = rand() % 2;
        int coins = rand() % (200 - 1 - 50) + 50;

        if (hasPotion == 0)
        {
            printf("  > %d gold\n", coins);
            printf("  > The Chest contains Gear!\n");
            printf("  > The Chest contains a Potion!\n");
        }
        else if (hasPotion == 1)
        {
            printf("  > %d gold\n", coins);
            printf("  > The Chest contains Gear!\n");
        }
        printf("\n");
        printf("-----------------------\n");
        printf("\n");

        printf("Enter any character except W, A, S, D, P or Q to continue\n");
        char pass;
        scanf_s("%d", &pass, 3);

        if (pass)
        {
            manager.currentScene = DUNGEON;
        }

        if (manager.currentScene == DUNGEON)
        {
            break;
        }

        system("pause");
    }
}
