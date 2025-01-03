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
        int gear = rand() % MAX_GEAR;
        int answer;
        Player playerStats;


        if (hasPotion == 0)
        {
            printf("  > %d gold\n", coins);
            printf("  > The Chest contains a Potion!\n");
            printf("  > The Chest contains Gear:\n");

            switch (gear)
            {
            case 0:
                printf("   > Richard Hatred (200 gold value)\n");
                break;
            case 1:
                printf("   > Swift boots (10 gold value)\n");
                break;
            case 2:
                printf("   > White Powder (150 gold value)\n");
                break;
            case 3:
                printf("   > Radev Mug (-300 gold value)\n");
                break;
            case 4:
                printf("   > Raven feather (50 gold value)\n");
                break;
            case 5:
                printf("   > Red Mushroom (170 gold value)\n");
                break;
            case 6:
                printf("   > Ugly Facemask (10 gold value)\n");
                break;
            case 7:
                printf("   > Broken Shield (25 gold value)\n");
                break;
            case 8:
                printf("   > Green mushroom (-50 gold value)\n");
                break;
            case 9:
                printf("   > Naughty book (69 gold value)\n");
                break;
            }

            printf(" > Do you want to equip the item? Yes(0) or No(1)");
            scanf_s("%d", &answer, 3);

            if (answer == 0)
            {
                if (gear == 0)
                {
                    playerStats.gold -= 200;
                    playerStats.health += 20;
                    playerStats.stamina += 40;
                    playerStats.agility += 1;
                }
                else if (gear == 1)
                {
                    playerStats.gold -= 10;
                    playerStats.health -= 10;
                    playerStats.stamina -= 5;
                    playerStats.agility += 1;
                }
                else if (gear == 2)
                {
                    playerStats.gold -= 150;
                    playerStats.health -= 20;
                    playerStats.stamina += 20;
                    playerStats.agility += 1;
                }
                else if (gear == 3)
                {
                    playerStats.gold -= 300;
                    playerStats.health -= 20;
                    playerStats.stamina -= 40;
                    playerStats.agility -= 1;
                }
                else if (gear == 4)
                {
                    playerStats.gold -= 50;
                    playerStats.health -= 10;
                    playerStats.agility += 2;
                }
                else if (gear == 5)
                {
                    playerStats.gold -= 170;
                    playerStats.health += 30;
                }
                else if (gear == 6)
                {
                    playerStats.gold -= 10;
                    playerStats.health += 5;
                }
                else if (gear == 7)
                {
                    playerStats.gold -= 25;
                    playerStats.health += 10;
                }
                else if (gear == 8)
                {
                    playerStats.gold -= 50;
                    playerStats.stamina -= 10;
                }
                else if (gear == 9)
                {
                    playerStats.gold -= 69;
                    playerStats.stamina += 7;
                }
            }

        }
        else if (hasPotion == 1)
        {
            printf("  > %d gold\n", coins);
            printf("  > The Chest contains Gear:\n");

            switch (gear)
            {
            case 0:
                printf("   > Richard Hatred (200 gold value)\n");
                break;
            case 1:
                printf("   > Swift boots (10 gold value)\n");
                break;
            case 2:
                printf("   > White Powder (150 gold value)\n");
                break;
            case 3:
                printf("   > Radev Mug (-300 gold value)\n");
                break;
            case 4:
                printf("   > Raven feather (50 gold value)\n");
                break;
            case 5:
                printf("   > Red Mushroom (170 gold value)\n");
                break;
            case 6:
                printf("   > Ugly Facemask (10 gold value)\n");
                break;
            case 7:
                printf("   > Broken Shield (25 gold value)\n");
                break;
            case 8:
                printf("   > Green mushroom (-50 gold value)\n");
                break;
            case 9:
                printf("   > Naughty book (69 gold value)\n");
                break;
            }

            printf(" > Do you want to equip the item? Yes(0) or No(1)");
            scanf_s("%d", &answer, 3);

            if (answer == 0)
            {
                if (gear == 0)
                {
                    playerStats.gold -= 200;
                    playerStats.health += 20;
                    playerStats.stamina += 40;
                    playerStats.agility += 1;
                }
                else if (gear == 1)
                {
                    playerStats.gold -= 10;
                    playerStats.health -= 10;
                    playerStats.stamina -= 5;
                    playerStats.agility += 1;
                }
                else if (gear == 2)
                {
                    playerStats.gold -= 150;
                    playerStats.health -= 20;
                    playerStats.stamina += 20;
                    playerStats.agility += 1;
                }
                else if (gear == 3)
                {
                    playerStats.gold -= 300;
                    playerStats.health -= 20;
                    playerStats.stamina -= 40;
                    playerStats.agility -= 1;
                }
                else if (gear == 4)
                {
                    playerStats.gold -= 50;
                    playerStats.health -= 10;
                    playerStats.agility += 2;
                }
                else if (gear == 5)
                {
                    playerStats.gold -= 170;
                    playerStats.health += 30;
                }
                else if (gear == 6)
                {
                    playerStats.gold -= 10;
                    playerStats.health += 5;
                }
                else if (gear == 7)
                {
                    playerStats.gold -= 25;
                    playerStats.health += 10;
                }
                else if (gear == 8)
                {
                    playerStats.gold -= 50;
                    playerStats.stamina -= 10;
                }
                else if (gear == 9)
                {
                    playerStats.gold -= 69;
                    playerStats.stamina += 7;
                }
            }
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
