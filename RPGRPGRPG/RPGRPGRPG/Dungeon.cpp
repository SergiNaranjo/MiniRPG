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

MapPosition MovePlayer(MapPosition playerPosition, char action, char map[ROWS][COLS], Scene& manager)
{
    // Guardar la posición previa
    MapPosition previousPosition = playerPosition;

    // Movimiento del jugador
    if (action == 'A' || action == 'a' && playerPosition.y > 0)
    {
        playerPosition.y -= 1;
    }
    else if (action == 'D' || action == 'd' && playerPosition.y < COLS - 1)
    {
        playerPosition.y += 1;
    }
    else if (action == 'W' || action == 'w' && playerPosition.x > 0)
    {
        playerPosition.x -= 1;
    }
    else if (action == 'S' || action == 's' && playerPosition.x < ROWS - 1)
    {
        playerPosition.x += 1;
    }

    // Comprobar si la nueva posición tiene un enemigo
    if (map[playerPosition.x][playerPosition.y] == 'E')
    {
        manager.currentScene = COMBAT; // Cambiar a la escena de combate
    }

    return playerPosition;
}


void UpdateMap(char map[ROWS][COLS], MapPosition playerPosition, char playerChar, char enemyChar) 
{
	InitializeMap(map, playerPosition, playerChar, enemyChar);
}

void Scene::Dungeon(Scene& manager)
{
    char map[ROWS][COLS];
    Player stats;
    Enemy enemyStats; // Agrega la estructura o clase Enemy para el enemigo
    MapPosition playerPosition = { 3, 2 }; // Posición inicial del jugador
    MapPosition enemyPosition = { 5, 5 }; // Posición inicial del enemigo
    char action;

    InitializeMap(map, playerPosition, stats.character, enemyStats.enemy);

    bool play = true;

    while (play)
    {
        system("cls");

        printf("------DUNGEON------\n");
        printf("Player -> P   Enemy -> E  Chest -> C\n");
        printf("Health: %d / %d\n", stats.actualHealth, stats.health);
        printf("Potions: %d / %d\n", stats.actualPotions, stats.potions);
        printf("Moves: %d / %d\n\n", stats.agility, MAX_AGILITY);

        PrintMap(map);

        printf("\nWASD -> Move\nP -> Potion\n");
        printf("Enter your action: ");
        scanf_s(" %c", &action, 2);

        if (action == 'Q' || action == 'q')
        {
            printf("Exiting the dungeon...\n");
            break;
        }

        if (action == 'P' || action == 'p')
        {
            stats.actualPotions--;
        }

        MapPosition newPosition = MovePlayer(playerPosition, action, map, manager);

        if (manager.currentScene == COMBAT)
        {
            printf("¡Combate activado! Cambiando de escena...\n");
            break; // Salir del bucle principal para entrar al combate
        }

        if (newPosition.x != playerPosition.x || newPosition.y != playerPosition.y) 
		{
            stats.agility--;
            playerPosition = newPosition;
        }

        UpdateMap(map, playerPosition, stats.character, enemyStats.enemy);

        system("pause");
    }

    printf("-------------------\n");
}

