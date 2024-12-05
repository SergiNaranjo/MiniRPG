#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Map.h"
#include "Scenes.h"
#include "Enemy.h"

void PrintMap(char map[ROWS][COLS]) 
{
	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLS; j++) 
		{
			printf("%c ", map[i][j]);
		}
		printf("\n");
	}
}

void InitializeMap(char map[ROWS][COLS], MapPosition playerPosition, char playerChar, char enemyChar) 
{
	for (int i = 0; i < ROWS; i++) 
	{
		for (int j = 0; j < COLS; j++) 
		{
			map[i][j] = '-';

            if (i == 0 && j == 0 || i == 1 && j == 1 || i == 1 && j == 4 || i == 4 && j == 1 || i == 4 && j == 3)
            {
                map[i][j] = enemyChar;
            }
		}
	}
	map[playerPosition.x][playerPosition.y] = playerChar;
}

MapPosition MovePlayer(MapPosition playerPosition, char action) 
{
	if (action == 'A' || action == 'a') 
	{
		if (playerPosition.y > 0) 
		{
			playerPosition.y -= 1;
		}
	}
	else if (action == 'D' || action == 'd') 
	{
		if (playerPosition.y < COLS - 1) 
		{
			playerPosition.y += 1;
		}
	}
	else if (action == 'W' || action == 'w') 
	{
		if (playerPosition.x > 0) 
		{
			playerPosition.x -= 1;
		}
	}
	else if (action == 'S' || action == 's') 
	{
		if (playerPosition.x < ROWS - 1) 
		{
			playerPosition.x += 1;
		}
	}
	return playerPosition;
}

void UpdateMap(char map[ROWS][COLS], MapPosition playerPosition, char playerChar, char enemyChar) 
{
	InitializeMap(map, playerPosition, playerChar, enemyChar);
}

void Scene::Dungeon()
{
    char map[ROWS][COLS];
    Player stats;
    Enemy enemyStats; // Agrega la estructura o clase Enemy para el enemigo
    MapPosition playerPosition = { 3, 2 }; // Posición inicial del jugador
    MapPosition enemyPosition = { 5, 5 }; // Posición inicial del enemigo
    char action;
    Scene manager;

    InitializeMap(map, playerPosition, stats.character, enemyStats.enemy);

    bool play = true;

    while (play)
    {
        system("cls");

        printf("------DUNGEON------\n");
        printf("Player -> P   Enemy -> E  Chest -> C\n");
        printf("Health: %d / %d\n", stats.actualHealth, stats.health);
        printf("Potions: %d / %d\n", stats.potions, MAX_POTIONS);
        printf("Moves: %d / %d\n\n", stats.agility, MAX_AGILITY);

        PrintMap(map);

        printf("\nWASD -> Move\nP -> Potion\n");
        printf("Enter your action: ");
        scanf_s(" %c", &action);

        if (action == 'Q' || action == 'q')
        {
            printf("Exiting the dungeon...\n");
            break;
        }

        if (action == 'P' || action == 'p')
        {
            stats.potions--;
        }

        MapPosition newPosition = MovePlayer(playerPosition, action);

        if (newPosition.x != playerPosition.x || newPosition.y != playerPosition.y) {
            stats.agility--;
            playerPosition = newPosition;
        }
        else {
            printf("You can't move in that direction!\n");
        }

        UpdateMap(map, playerPosition, stats.character, enemyStats.enemy);

        system("pause");
    }

    printf("-------------------\n");
}

