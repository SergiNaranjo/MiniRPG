#include <stdio.h>
#include <cstdio>
#include <stdlib.h>
#include <time.h>
#include "Consts.h"
#include "Character.h"
#include "Map.h"
#include "Scenes.h"
#include "Enemy.h"

void PrintMap(char map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void PlaceEnemies(char map[ROWS][COLS], MapPosition enemies[], int enemyCount, MapPosition playerPosition, MapPosition chests[], int chestCount, char enemyChar) {
    srand((unsigned int)time(NULL));
    int placed = 0;

    while (placed < enemyCount) {
        int x = rand() % ROWS;
        int y = rand() % COLS;

        // Verificar que la posición no esté ocupada por el jugador ni por cofres
        int valid = 1;
        if (map[x][y] != '-') valid = 0;
        if (x == playerPosition.x && y == playerPosition.y) valid = 0;

        for (int i = 0; i < chestCount; i++) {
            if (x == chests[i].x && y == chests[i].y) {
                valid = 0;
                break;
            }
        }

        if (valid) {
            map[x][y] = enemyChar;
            enemies[placed].x = x;
            enemies[placed].y = y;
            placed++;
        }
    }
}

void RemoveEnemy(MapPosition enemies[], int& enemyCount, int index) {
    for (int i = index; i < enemyCount - 1; i++) {
        enemies[i] = enemies[i + 1];
    }
    enemyCount -= 1; // Reducir la cuenta total de enemigos
}


void InitializeMap(char map[ROWS][COLS], MapPosition playerPosition, char playerChar, char chestChar, MapPosition chests[], int chestCount) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            map[i][j] = '-';
        }
    }

    // Colocar cofres
    for (int i = 0; i < chestCount; i++) {
        map[chests[i].x][chests[i].y] = chestChar;
    }

    // Colocar al jugador
    map[playerPosition.x][playerPosition.y] = playerChar;
}

MapPosition MovePlayer(MapPosition playerPosition, char action, char map[ROWS][COLS], Scene& manager, MapPosition enemies[], int& enemyCount)
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
    int enemyIndex = -1;

    if (map[playerPosition.x][playerPosition.y] == 'E') {
        manager.currentScene = COMBAT; // Cambiar a la escena de combate

        // Buscar al enemigo en el array de enemigos
        for (int i = 0; i < enemyCount; i++) {
            if (enemies[i].x == playerPosition.x && enemies[i].y == playerPosition.y) {
                enemyIndex = i;
                break;
            }
        }
    }


    if (map[playerPosition.x][playerPosition.y] == 'C')
    {
        manager.currentScene = CHEST; // Cambiar a la escena de combate
    }

    return playerPosition;
}


void UpdateMap(char map[ROWS][COLS], MapPosition playerPosition, char playerChar, char chestChar, MapPosition chests[], int chestCount, MapPosition enemies[], int enemyCount, char enemyChar) {
    InitializeMap(map, playerPosition, playerChar, chestChar, chests, chestCount);

    // Colocar enemigos
    for (int i = 0; i < enemyCount; i++) {
        map[enemies[i].x][enemies[i].y] = enemyChar;
    }
}

void Scene::Dungeon(Scene& manager)
{
    char map[ROWS][COLS];
    Player stats;
    Enemy enemyStats; // Agrega la estructura o clase Enemy para el enemigo
    MapPosition playerPosition = { 3, 2 }; // Posición inicial del jugador
    MapPosition enemyPosition = { 5, 5 }; // Posición inicial del enemigo
    char action;
    char chestChar = 'C';
    int enemyIndex = -1; // Inicializar a -1 para indicar que no hay enemigo seleccionado


    MapPosition chests[MAX_CHESTS] = { {0, 4}, {1, 3} };
    int chestCount = 2; // Número explícito de cofres

    // Generar enemigos aleatorios
    int enemyCount = (rand() % (MAX_ENEMIES - MIN_ENEMIES + 1)) + MIN_ENEMIES;
    MapPosition enemies[MAX_ENEMIES];

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
        }

        MapPosition newPosition = MovePlayer(playerPosition, action, map, manager, enemies, enemyCount);

        if (manager.currentScene == COMBAT) {
            printf("¡Combate activado! Cambiando de escena...\n");

            // Simular el final del combate (puedes integrar tu lógica aquí)
            printf("¡Combate terminado! Eliminando enemigo...\n");

            if (enemyIndex != -1) {
                RemoveEnemy(enemies, enemyCount, enemyIndex);
                map[playerPosition.x][playerPosition.y] = '-'; // Limpiar la casilla
            }
            break;
        }


        if (manager.currentScene == CHEST)
        {
            printf("¡Combate activado! Cambiando de escena...\n");
            break; // Salir del bucle principal para entrar al combate
        }

        if (newPosition.x != playerPosition.x || newPosition.y != playerPosition.y) 
		{
            stats.agility--;
            playerPosition = newPosition;
        }

        UpdateMap(map, playerPosition, stats.character, chestChar, chests, chestCount, enemies, enemyCount, enemyStats.enemy);


        system("pause");
    }

    printf("-------------------\n");
}

