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

void PlaceEnemies(char map[ROWS][COLS], MapPosition enemies[], int enemyCount, MapPosition playerPosition, MapPosition chests[], int chestCount, char enemyChar) 
{
    int placed = 0;

    while (placed < enemyCount) 
    {
        int x = rand() % ROWS;
        int y = rand() % COLS;

        // Verificar que la posición no esté ocupada por el jugador ni por cofres

        int valid = 1;

        if (map[x][y] != '-')
        {
            valid = 0;
        }

        if (x == playerPosition.x && y == playerPosition.y)
        {
            valid = 0;
        }

        for (int i = 0; i < chestCount; i++) 
        {
            if (x == chests[i].x && y == chests[i].y) 
            {
                valid = 0;
                break;
            }
        }

        if (valid) 
        {
            map[x][y] = enemyChar;
            enemies[placed].x = x;
            enemies[placed].y = y;
            placed++;
        }
    }
}


void InitializeMap(char map[ROWS][COLS], MapPosition playerPosition, char playerChar, char chestChar, MapPosition chests[], int chestCount) 
{
    // Mapa
    for (int i = 0; i < ROWS; i++) 
    {
        for (int j = 0; j < COLS; j++) 
        {
            map[i][j] = '-';
        }
    }

    // Cofres
    for (int i = 0; i < chestCount; i++) 
    {
        map[chests[i].x][chests[i].y] = chestChar;
    }

    // Jugador
    map[playerPosition.x][playerPosition.y] = playerChar;
}

MapPosition MovePlayer(MapPosition playerPosition, char action, char map[ROWS][COLS], Scene& manager, MapPosition enemies[], int* enemyCount, int *chestCount)
{
  
    MapPosition previousPosition = playerPosition;

    
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
    int enemyIndex = -1;

    if (map[playerPosition.x][playerPosition.y] == 'E') 
    {
        (*enemyCount)--;

         manager.currentScene = COMBAT; 
    }


    if (map[playerPosition.x][playerPosition.y] == 'C')
    {
        chestCount--;
        manager.currentScene = CHEST; 
    }

    return playerPosition;
}


void UpdateMap(char map[ROWS][COLS], MapPosition playerPosition, char playerChar, char chestChar, MapPosition chests[], int chestCount, MapPosition enemies[], int enemyCount, char enemyChar) 
{
    InitializeMap(map, playerPosition, playerChar, chestChar, chests, chestCount);

    // Enemigos
    for (int i = 0; i < enemyCount; i++) 
    {
        map[enemies[i].x][enemies[i].y] = enemyChar;
    }
}

void Scene::Dungeon(Scene& manager, int &enemyCount, Player &stats)
{
    char map[ROWS][COLS];
    Enemy enemyStats; 
    MapPosition playerPosition = { 3, 2 }; 
    MapPosition enemyPosition = { 5, 5 }; 
    char action;
    char chestChar = 'C';
    int enemyIndex = -1; // Inicializar a -1 para indicar que no hay enemigo seleccionado


    MapPosition chests[MAX_CHESTS] = { {0, 4}, {1, 3} };
    int chestCount = 2; 
    

    // malloc(): Asigna memoria dinámica en el heap. Pertenece a la librería stdlib.h
    // Retorna un puntero al bloque asignado o NULL si falla. 
    // Lo uso para poder hacer un array dinamica de enemigos aleatorios ya que no se pueden hacer arrays con variables,
    // solo con constantes

    MapPosition* enemies = (MapPosition*)malloc(enemyCount * sizeof(MapPosition));

    if (enemies == NULL) 
    {
        exit(EXIT_FAILURE);
    }

    InitializeMap(map, playerPosition, stats.character, chestChar, chests, chestCount);

    PlaceEnemies(map, enemies, enemyCount, playerPosition, chests, chestCount, enemyStats.enemy);

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
            stats.actualHealth = stats.health;
        }

        MapPosition newPosition = MovePlayer(playerPosition, action, map, manager, enemies, &enemyCount, &chestCount);

        if (manager.currentScene == COMBAT) 
        {
            break;
        }

        if (manager.currentScene == CHEST)
        {
            break; 
        }

        if (newPosition.x != playerPosition.x || newPosition.y != playerPosition.y) 
		{
            stats.agility--;
            playerPosition = newPosition;
        }

        if (enemyCount == 0) 
        {
            manager.currentScene = GAMEOVER; 
            break; 
        }

        UpdateMap(map, playerPosition, stats.character, chestChar, chests, chestCount, enemies, enemyCount, enemyStats.enemy);


        system("pause");
    }

    printf("-------------------\n");
}

